
	.globl main

main:

	pushq	%rbp
	movq	%rsp, %rbp
	subq	$8, %rsp

	movl	$4, -16(%rbp)
	movl	$2, -24(%rbp)
	movl	-16(%rbp), %eax
	movl	$0, %edx
	movl	-24(%rbp), %ebx
	idiv	%ebx
	movl	%eax, -32(%rbp)
	movl	-32(%rbp), %eax
	movl	%eax, -8(%rbp)

	addq	$8, %rsp
	popq	%rbp
	retq

