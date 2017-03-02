/*
 * mm-naive.c - The fastest, least memory-efficient malloc package.
 * 
 * In this naive approach, a block is allocated by simply incrementing
 * the brk pointer.  A block is pure payload. There are no headers or
 * footers.  Blocks are never coalesced or reused. Realloc is
 * implemented directly using mm_malloc and mm_free.
 *
 * NOTE TO STUDENTS: Replace this header comment with your own header
 * comment that gives a high level description of your solution.
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <string.h>

#include "mm.h"
#include "memlib.h"

//#define checkheap(lineno) mm_checkheap(lineno)
#define checkheap(lineno)

/*********************************************************
 * NOTE TO STUDENTS: Before you do anything else, please
 * provide your team information in the following struct.
 ********************************************************/
team_t team = {
    /* Team name */
    "ateam",
    /* First member's full name */
    "Harry Bovik",
    /* First member's email address */
    "bovik@cs.cmu.edu",
    /* Second member's full name (leave blank if none) */
    "",
    /* Second member's email address (leave blank if none) */
    ""};

/* single word (4) or double word (8) alignment */
#define ALIGNMENT 8
#define WSIZE 4
#define DSIZE 8
#define INITCHUNK (1 << 8)
#define CHUNKSIZE (1 << 12)
/* rounds up to the nearest multiple of ALIGNMENT */
#define ALIGN(size) (((size) + (ALIGNMENT - 1)) & ~0x7)

#define SIZE_T_SIZE (ALIGN(sizeof(size_t))) //size of size_t depend on machine
//macro
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) > (y) ? (y) : (x))
#define PACK(size, alloc) ((size) | (alloc))
#define GET(p) (*(unsigned int *)(p))
#define PUT(p, val) (*(unsigned int *)(p) = (val))
#define GET_SIZE(p) (GET(p) & ~0x7)
#define GET_ALLOC(p) (GET(p) & 0x1)
#define HDRP(bp) ((char *)(bp)-WSIZE)
#define FTRP(bp) ((char *)(bp) + GET_SIZE(HDRP(bp)) - DSIZE)
#define NEXT_BLKP(bp) ((char *)(bp) + GET_SIZE(((char *)(bp)-WSIZE)))
#define PREV_BLKP(bp) ((char *)(bp)-GET_SIZE(((char *)(bp)-DSIZE)))

#define GET_PRED_P(bp) (*(char **)(bp))
#define GET_SUCC_P(bp) (*((char **)(bp) + 1))
#define SET_PRED_P(bp, qp) (GET_PRED_P(bp) = (qp))
#define SET_SUCC_P(bp, qp) (GET_SUCC_P(bp) = (qp))

/* 
 * mm_init - initialize the malloc package.
 */

static char *heap_listp;
static void *extend_heap(size_t);
static void *coalesce(void *);
static void *find_fit(size_t);
static void place(void *, size_t);
static void insert_i_freelist(void *bp);
static void remove_f_freelist(void *bp);
//
static char *FREE_L_HEADER = NULL;
//
static void insert_i_freelist(void *bp)
{
    SET_PRED_P(bp, NULL);
    SET_SUCC_P(bp, FREE_L_HEADER);
    if (FREE_L_HEADER)
        SET_PRED_P(FREE_L_HEADER, bp);
    FREE_L_HEADER = bp;
}
static void remove_f_freelist(void *bp)
{
    SET_PRED_P(GET_SUCC_P(bp), GET_PRED_P(bp));
    if (GET_PRED_P(bp) != FREE_L_HEADER)
        SET_SUCC_P(GET_PRED_P(bp), GET_SUCC_P(bp));
    else
        FREE_L_HEADER = GET_SUCC_P(bp);
}
int mm_init(void)
{
    if ((heap_listp = (char *)mem_sbrk(ALIGN(4 * WSIZE))) == (void *)-1)
        return -1;
    PUT(heap_listp, 0);
    PUT(heap_listp + (1 * WSIZE), PACK(DSIZE, 1));
    PUT(heap_listp + (2 * WSIZE), PACK(DSIZE, 1));
    PUT(heap_listp + (3 * WSIZE), PACK(0, 1));
    if (extend_heap(INITCHUNK / WSIZE) == NULL)
        return -1;
    FREE_L_HEADER = heap_listp + 2 * WSIZE;
    //
    return 0;
}

static void *extend_heap(size_t words)
{
    char *bp;
    size_t size;
    int pointer_size = 2 * sizeof(bp) / WSIZE; //size of pointer;
    words += pointer_size;
    size = (words % 2) ? (words + 1) * WSIZE : words * WSIZE;
    if ((long)(bp = mem_sbrk(size)) == -1)
        return NULL;
    PUT(HDRP(bp), PACK(size, 0));
    PUT(FTRP(bp), PACK(size, 0));
    PUT(HDRP(NEXT_BLKP(bp)), PACK(0, 1));


    return coalesce(bp);
}

static void *coalesce(void *bp)
{
    size_t prev_alloc = GET_ALLOC(FTRP(PREV_BLKP(bp)));
    size_t next_alloc = GET_ALLOC(HDRP(NEXT_BLKP(bp)));
    size_t size = GET_SIZE(HDRP(bp));
    if (prev_alloc && next_alloc)
    {
        insert_i_freelist(bp);
        return bp;
    }
    else if (prev_alloc && !next_alloc)
    {
        size += GET_SIZE(HDRP(NEXT_BLKP(bp)));
        remove_f_freelist(NEXT_BLKP(bp));
        PUT(HDRP(bp), PACK(size, 0));
        PUT(FTRP(bp), PACK(size, 0));
        insert_i_freelist(bp);
    }
    else if (!prev_alloc && next_alloc)
    {
        size += GET_SIZE(HDRP(PREV_BLKP(bp)));
        remove_f_freelist(PREV_BLKP(bp));
        PUT(FTRP(bp), PACK(size, 0));
        PUT(HDRP(PREV_BLKP(bp)), PACK(size, 0));
        bp = PREV_BLKP(bp);
        insert_i_freelist(bp);
    }
    else
    {
        size += GET_SIZE(HDRP(PREV_BLKP(bp))) + GET_SIZE(FTRP(NEXT_BLKP(bp)));
        remove_f_freelist(NEXT_BLKP(bp));
        remove_f_freelist(PREV_BLKP(bp));
        PUT(HDRP(PREV_BLKP(bp)), PACK(size, 0));
        PUT(FTRP(NEXT_BLKP(bp)), PACK(size, 0));
        bp = PREV_BLKP(bp);
        insert_i_freelist(bp);
    }
    return bp;
}
/* 
 * mm_malloc - Allocate a block by incrementing the brk pointer.
 *     Always allocate a block whose size is a multiple of the alignment.
 */
void *mm_malloc(size_t size)
{
    size_t asize;
    size_t extendsize;
    size_t MSIZE;
    char *p;

    if (size == 0)
        return NULL;

    MSIZE = DSIZE + 2 * SIZE_T_SIZE;
    if (size <= DSIZE)
        asize = 2 * DSIZE;
    else
        asize = DSIZE * ((size + (DSIZE) + (DSIZE - 1)) / DSIZE);

    if ((p = find_fit(asize)) != NULL)
    {
        place(p, asize);
        return p;
    }

    extendsize = MAX(asize, CHUNKSIZE);
    if ((p = extend_heap(extendsize / WSIZE)) == NULL)
        return NULL;
    place(p, asize);
    return p;
}
static void *find_fit(size_t asize)
{
    void *bp;
    for (bp = FREE_L_HEADER; bp; bp = GET_SUCC_P(bp))
    {
        if (!GET_ALLOC(bp) && (asize <= GET_SIZE(HDRP(bp))))
            return bp;
    }
    return NULL;
}
static void place(void *bp, size_t asize)
{
    size_t csize = GET_SIZE(HDRP(bp));
    if ((csize - asize) >= (2 * DSIZE))
    {
        PUT(HDRP(bp), PACK(asize, 1));
        PUT(FTRP(bp), PACK(asize, 1));
        remove_f_freelist(bp);
        bp = NEXT_BLKP(bp);
        PUT(HDRP(bp), PACK((csize - asize), 0));
        PUT(FTRP(bp), PACK((csize - asize), 0));
        coalesce(bp);
    }
    else
    {
        PUT(HDRP(bp), PACK(csize, 1));
        PUT(FTRP(bp), PACK(csize, 1));
        remove_f_freelist(bp);
    }
}
/* mm_checkheap - Check the heap for correctness. Helpfudl hint: You
 * 				  can call this function using mm_checkheap(__LINE__);
 * 				  to identify the line number of the call site.
 */
void mm_checkheap(int lineno)
{
    printf("checkheap called from %d\n", lineno);
}
/*
 * mm_free - Freeing a block does nothing.
 */
void mm_free(void *bp)
{
    size_t size = GET_SIZE(HDRP(bp));
    PUT(HDRP(bp), PACK(size, 0));
    PUT(FTRP(bp), PACK(size, 0));
    coalesce(bp);
    checkheap(__LINE__);
}

/*
 * mm_realloc - Implemented simply in terms of mm_malloc and mm_free
 */
void *mm_realloc(void *ptr, size_t size)
{
    void *oldptr = ptr;
    void *newptr;
    size_t copySize;

    newptr = mm_malloc(size);
    if (newptr == NULL)
        return NULL;
    copySize = *(size_t *)((char *)oldptr - SIZE_T_SIZE);
    if (size < copySize)
        copySize = size;
    memcpy(newptr, oldptr, copySize);
    mm_free(oldptr);
    return newptr;
}
