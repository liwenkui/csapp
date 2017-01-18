	.text
	.globl _plus
_plus:
LFB4:
	leaq	(%rdi,%rsi), %rax
	ret
LFE4:
	.globl _sumstore
_sumstore:
LFB5:
	pushq	%rbx
LCFI0:
	movq	%rdx, %rbx
	call	_plus
	movq	%rax, (%rbx)
	popq	%rbx
LCFI1:
	ret
LFE5:
	.cstring
lC0:
	.ascii "%ld + %ld --> %ld\12\0"
	.section __TEXT,__text_startup,regular,pure_instructions
	.globl _main
_main:
LFB6:
	pushq	%rbp
LCFI2:
	pushq	%rbx
LCFI3:
	subq	$24, %rsp
LCFI4:
	movq	%rsi, %rbp
	movq	8(%rsi), %rdi
	call	_atoi
	movslq	%eax, %rbx
	movq	16(%rbp), %rdi
	call	_atoi
	movslq	%eax, %rbp
	leaq	8(%rsp), %rdx
	movq	%rbp, %rsi
	movq	%rbx, %rdi
	call	_sumstore
	movq	8(%rsp), %rcx
	movq	%rbp, %rdx
	movq	%rbx, %rsi
	leaq	lC0(%rip), %rdi
	movl	$0, %eax
	call	_printf
	movl	$0, %eax
	addq	$24, %rsp
LCFI5:
	popq	%rbx
LCFI6:
	popq	%rbp
LCFI7:
	ret
LFE6:
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
	.quad	LFB4-.
	.set L$set$2,LFE4-LFB4
	.quad L$set$2
	.byte	0
	.align 3
LEFDE1:
LSFDE3:
	.set L$set$3,LEFDE3-LASFDE3
	.long L$set$3
LASFDE3:
	.long	LASFDE3-EH_frame1
	.quad	LFB5-.
	.set L$set$4,LFE5-LFB5
	.quad L$set$4
	.byte	0
	.byte	0x4
	.set L$set$5,LCFI0-LFB5
	.long L$set$5
	.byte	0xe
	.byte	0x10
	.byte	0x83
	.byte	0x2
	.byte	0x4
	.set L$set$6,LCFI1-LCFI0
	.long L$set$6
	.byte	0xe
	.byte	0x8
	.align 3
LEFDE3:
LSFDE5:
	.set L$set$7,LEFDE5-LASFDE5
	.long L$set$7
LASFDE5:
	.long	LASFDE5-EH_frame1
	.quad	LFB6-.
	.set L$set$8,LFE6-LFB6
	.quad L$set$8
	.byte	0
	.byte	0x4
	.set L$set$9,LCFI2-LFB6
	.long L$set$9
	.byte	0xe
	.byte	0x10
	.byte	0x86
	.byte	0x2
	.byte	0x4
	.set L$set$10,LCFI3-LCFI2
	.long L$set$10
	.byte	0xe
	.byte	0x18
	.byte	0x83
	.byte	0x3
	.byte	0x4
	.set L$set$11,LCFI4-LCFI3
	.long L$set$11
	.byte	0xe
	.byte	0x30
	.byte	0x4
	.set L$set$12,LCFI5-LCFI4
	.long L$set$12
	.byte	0xe
	.byte	0x18
	.byte	0x4
	.set L$set$13,LCFI6-LCFI5
	.long L$set$13
	.byte	0xe
	.byte	0x10
	.byte	0x4
	.set L$set$14,LCFI7-LCFI6
	.long L$set$14
	.byte	0xe
	.byte	0x8
	.align 3
LEFDE5:
	.subsections_via_symbols
