
	.globl main

main:

	pushq	%rbp
	movq	%rsp, %rbp
	subq	$8, %rsp

	movl	$1, -16(%rbp)
	movl	$2, -24(%rbp)
	movl	-16(%rbp), %eax
	and	-24(%rbp), %eax
	movl	%eax, -32(%rbp)
	movl	-32(%rbp), %eax
	movl	%eax, -8(%rbp)

	addq	$8, %rsp
	popq	%rbp
	retq

