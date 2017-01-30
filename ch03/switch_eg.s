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
	.subsections_via_symbols
