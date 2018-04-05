
	.globl main

main:

	pushq	%rbp
	movq	%rsp, %rbp
	subq	$16, %rsp

	movl	$0, -24(%rbp)
	movl	-24(%rbp), %eax
	movl	%eax, -8(%rbp)
	jmp .L2
.L3:
	movl	$86, -32(%rbp)
	movl	-32(%rbp), %edi
	call	putchar
	movl	$1, -40(%rbp)
	movl	-8(%rbp), %eax
	add		-40(%rbp), %eax
	movl	%eax, -48(%rbp)
	movl	-48(%rbp), %eax
	movl	%eax, -8(%rbp)
.L2:
	movl	$5, -64(%rbp)
	movl	-8(%rbp), %eax
	cmp	-64(%rbp), %eax
	setl	%al
	movl	%eax, -72(%rbp)
	cmpl	$1, -72(%rbp)
	je .L3
	movl	$10, -88(%rbp)
	movl	-88(%rbp), %edi
	call	putchar

	addq	$16, %rsp
	popq	%rbp
	retq

