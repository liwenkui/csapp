
switch_eg.o:	file format Mach-O 64-bit x86-64

Disassembly of section __TEXT,__text:
_switch_eg:
       0:	48 83 ee 64 	subq	$100, %rsi
       4:	48 83 fe 06 	cmpq	$6, %rsi
       8:	77 4a 	ja	74 <_switch_eg+54>
       a:	48 8d 0d 0b 00 00 00 	leaq	11(%rip), %rcx
      11:	48 63 04 b1 	movslq	(%rcx,%rsi,4), %rax
      15:	48 01 c8 	addq	%rcx, %rax
      18:	ff e0 	jmpq	*%rax
      1a:	66 90 	nop
      1c:	1c 00 	sbbb	$0, %al
      1e:	00 00 	addb	%al, (%rax)
      20:	38 00 	cmpb	%al, (%rax)
      22:	00 00 	addb	%al, (%rax)
      24:	26 00 00 	addb	%al, %es:(%rax)
      27:	00 2a 	addb	%ch, (%rdx)
      29:	00 00 	addb	%al, (%rax)
      2b:	00 32 	addb	%dh, (%rdx)
      2d:	00 00 	addb	%al, (%rax)
      2f:	00 38 	addb	%bh, (%rax)
      31:	00 00 	addb	%al, (%rax)
      33:	00 32 	addb	%dh, (%rdx)
      35:	00 00 	addb	%al, (%rax)
      37:	00 48 8d 	addb	%cl, -115(%rax)
      3a:	04 7f 	addb	$127, %al
      3c:	48 8d 3c 87 	leaq	(%rdi,%rax,4), %rdi
      40:	eb 08 	jmp	8 <_switch_eg+4A>
      42:	48 83 c7 0a 	addq	$10, %rdi
      46:	48 83 c7 0b 	addq	$11, %rdi
      4a:	48 89 3a 	movq	%rdi, (%rdx)
      4d:	c3 	retq
      4e:	48 0f af ff 	imulq	%rdi, %rdi
      52:	eb f6 	jmp	-10 <_switch_eg+4A>
      54:	bf 00 00 00 00 	movl	$0, %edi
      59:	eb ef 	jmp	-17 <_switch_eg+4A>
Disassembly of section __TEXT,__text_startup:
_main:
      5b:	48 83 ec 10 	subq	$16, %rsp
      5f:	48 8d 54 24 08 	leaq	8(%rsp), %rdx
      64:	be 69 00 00 00 	movl	$105, %esi
      69:	bf 01 00 00 00 	movl	$1, %edi
      6e:	e8 00 00 00 00 	callq	0 <_main+18>
      73:	b8 00 00 00 00 	movl	$0, %eax
      78:	48 83 c4 10 	addq	$16, %rsp
      7c:	c3 	retq
