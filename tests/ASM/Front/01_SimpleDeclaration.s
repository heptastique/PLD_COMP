
	.globl main

main:

	pushq	%rbp
	movq	%rsp, %rbp
	subq	$8, %rsp


	addq	$8, %rsp
	popq	%rbp
	retq
