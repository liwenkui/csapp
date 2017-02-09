	.text
	.globl _switch_eg
_switch_eg:
LFB0:
	subq	$100, %rsi
	cmpq	$6, %rsi
	ja	L8
	leaq	L4(%rip), %rcx
	movslq	(%rcx,%rsi,4), %rax
	addq	%rcx, %rax
	jmp	*%rax
	.align 2,0x90
L4:
	.long	L3-L4
	.long	L8-L4
	.long	L5-L4
	.long	L6-L4
	.long	L7-L4
	.long	L8-L4
	.long	L7-L4
L3:
	leaq	(%rdi,%rdi,2), %rax
	leaq	(%rdi,%rax,4), %rdi
	jmp	L2
L5:
	addq	$10, %rdi
L6:
	addq	$11, %rdi
L2:
	movq	%rdi, (%rdx)
	ret
L7:
	imulq	%rdi, %rdi
	jmp	L2
L8:
	movl	$0, %edi
	jmp	L2
LFE0:
	.section __TEXT,__text_startup,regular,pure_instructions
	.globl _main
_main:
LFB1:
	subq	$16, %rsp
LCFI0:
	leaq	8(%rsp), %rdx
	movl	$105, %esi
	movl	$1, %edi
	call	_switch_eg
	movl	$0, %eax
	addq	$16, %rsp
LCFI1:
	ret
LFE1:
	.section __TEXT,__eh_frame,coalesced,no_toc+strip_static_syms+live_support
EH_frame1:
	.set L$set$0,LECIE1-LSCIE1
	.long L$set$0
LSCIE1:
	.long	0
	.byte	0x1
	.ascii "zR\0"
	.byte	0x1
	.byte	0x78
	.byte	0x10
	.byte	0x1
	.byte	0x10
	.byte	0xc
	.byte	0x7
	.byte	0x8
	.byte	0x90
	.byte	0x1
	.align 3
LECIE1:
LSFDE1:
	.set L$set$1,LEFDE1-LASFDE1
	.long L$set$1
LASFDE1:
	.long	LASFDE1-EH_frame1
	.quad	LFB0-.
	.set L$set$2,LFE0-LFB0
	.quad L$set$2
	.byte	0
	.align 3
LEFDE1:
LSFDE3:
	.set L$set$3,LEFDE3-LASFDE3
	.long L$set$3
LASFDE3:
	.long	LASFDE3-EH_frame1
	.quad	LFB1-.
	.set L$set$4,LFE1-LFB1
	.quad L$set$4
	.byte	0
	.byte	0x4
	.set L$set$5,LCFI0-LFB1
	.long L$set$5
	.byte	0xe
	.byte	0x18
	.byte	0x4
	.set L$set$6,LCFI1-LCFI0
	.long L$set$6
	.byte	0xe
	.byte	0x8
	.align 3
LEFDE3:
	.subsections_via_symbols
