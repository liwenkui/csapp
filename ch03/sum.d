
sum:	file format Mach-O 64-bit x86-64

Disassembly of section __TEXT,__text:
__text:
100000ea0:	48 8d 04 37 	leaq	(%rdi,%rsi), %rax
100000ea4:	c3 	retq
100000ea5:	53 	pushq	%rbx
100000ea6:	48 89 d3 	movq	%rdx, %rbx
100000ea9:	e8 f2 ff ff ff 	callq	-14 <_plus>
100000eae:	48 89 03 	movq	%rax, (%rbx)
100000eb1:	5b 	popq	%rbx
100000eb2:	c3 	retq

_plus:
100000ea0:	48 8d 04 37 	leaq	(%rdi,%rsi), %rax
100000ea4:	c3 	retq

_sumstore:
100000ea5:	53 	pushq	%rbx
100000ea6:	48 89 d3 	movq	%rdx, %rbx
100000ea9:	e8 f2 ff ff ff 	callq	-14 <_plus>
100000eae:	48 89 03 	movq	%rax, (%rbx)
100000eb1:	5b 	popq	%rbx
100000eb2:	c3 	retq
Disassembly of section __TEXT,__text_startup:
_main:
100000eb3:	55 	pushq	%rbp
100000eb4:	53 	pushq	%rbx
100000eb5:	48 83 ec 18 	subq	$24, %rsp
100000eb9:	48 89 f5 	movq	%rsi, %rbp
100000ebc:	48 8b 7e 08 	movq	8(%rsi), %rdi
100000ec0:	e8 47 00 00 00 	callq	71
100000ec5:	48 63 d8 	movslq	%eax, %rbx
100000ec8:	48 8b 7d 10 	movq	16(%rbp), %rdi
100000ecc:	e8 3b 00 00 00 	callq	59
100000ed1:	48 63 e8 	movslq	%eax, %rbp
100000ed4:	48 8d 54 24 08 	leaq	8(%rsp), %rdx
100000ed9:	48 89 ee 	movq	%rbp, %rsi
100000edc:	48 89 df 	movq	%rbx, %rdi
100000edf:	e8 c1 ff ff ff 	callq	-63 <_sumstore>
100000ee4:	48 8b 4c 24 08 	movq	8(%rsp), %rcx
100000ee9:	48 89 ea 	movq	%rbp, %rdx
100000eec:	48 89 de 	movq	%rbx, %rsi
100000eef:	48 8d 3d 46 00 00 00 	leaq	70(%rip), %rdi
100000ef6:	b8 00 00 00 00 	movl	$0, %eax
100000efb:	e8 12 00 00 00 	callq	18
100000f00:	b8 00 00 00 00 	movl	$0, %eax
100000f05:	48 83 c4 18 	addq	$24, %rsp
100000f09:	5b 	popq	%rbx
100000f0a:	5d 	popq	%rbp
100000f0b:	c3 	retq
Disassembly of section __TEXT,__stubs:
__stubs:
100000f0c:	ff 25 fe 00 00 00 	jmpq	*254(%rip)
100000f12:	ff 25 00 01 00 00 	jmpq	*256(%rip)
Disassembly of section __TEXT,__stub_helper:
__stub_helper:
100000f18:	4c 8d 1d e9 00 00 00 	leaq	233(%rip), %r11
100000f1f:	41 53 	pushq	%r11
100000f21:	ff 25 d9 00 00 00 	jmpq	*217(%rip)
100000f27:	90 	nop
100000f28:	68 00 00 00 00 	pushq	$0
100000f2d:	e9 e6 ff ff ff 	jmp	-26 <__stub_helper>
100000f32:	68 0c 00 00 00 	pushq	$12
100000f37:	e9 dc ff ff ff 	jmp	-36 <__stub_helper>
