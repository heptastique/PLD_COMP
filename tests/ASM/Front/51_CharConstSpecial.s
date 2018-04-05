
	.globl main

main:

	pushq	%rbp
	movq	%rsp, %rbp
	subq	$8, %rsp

	movl	$10, -16(%rbp)
	movl	-16(%rbp), %eax
	movl	%eax, -8(%rbp)

	addq	$8, %rsp
	popq	%rbp
	retq

