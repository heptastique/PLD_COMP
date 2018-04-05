
	.globl main

main:

	pushq	%rbp
	movq	%rsp, %rbp
	subq	$8, %rsp

	movl	$10, -16(%rbp)
	movl	-16(%rbp), %eax
	movl	%eax, -8(%rbp)
	jmp .L2
.L3:
	movl	$1, -24(%rbp)
	movl	-8(%rbp), %eax
	sub		-24(%rbp), %eax
	movl	%eax, -32(%rbp)
	movl	-32(%rbp), %eax
	movl	%eax, -8(%rbp)
.L2:
	movl	$0, -40(%rbp)
	movl	-8(%rbp), %eax
	cmp	-40(%rbp), %eax
	movl	$0, %eax
	setne	%al
	movl	%eax, -48(%rbp)
	cmpl	$1, -48(%rbp)
	je .L3

	addq	$8, %rsp
	popq	%rbp
	retq

