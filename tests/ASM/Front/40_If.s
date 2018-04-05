
	.globl main

main:

	pushq	%rbp
	movq	%rsp, %rbp
	subq	$8, %rsp

	movl	$1, -16(%rbp)
	movl	-16(%rbp), %eax
	movl	%eax, -8(%rbp)
	movl	$1, -24(%rbp)
	movl	-8(%rbp), %eax
	movl	%eax, -32(%rbp)
	cmpl	$1, -32(%rbp)
	jne .L2
	movl	$2, -40(%rbp)
	movl	-40(%rbp), %eax
	movl	%eax, -8(%rbp)
.L2:

	addq	$8, %rsp
	popq	%rbp
	retq

