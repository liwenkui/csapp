
main.o:	file format Mach-O 64-bit x86-64

Disassembly of section __TEXT,__text_startup:
_main:
       0:	48 83 ec 08 	subq	$8, %rsp
       4:	be 02 00 00 00 	movl	$2, %esi
       9:	48 8d 3d 00 00 00 00 	leaq	(%rip), %rdi
      10:	e8 00 00 00 00 	callq	0 <_main+15>
      15:	b8 00 00 00 00 	movl	$0, %eax
      1a:	48 83 c4 08 	addq	$8, %rsp
      1e:	c3 	retq
