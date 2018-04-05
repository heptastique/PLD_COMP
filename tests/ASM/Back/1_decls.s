
	.globl main

toto:

	pushq	%rbp
	movq	%rsp, %rbp
	subq	$48, %rsp


	addq	$48, %rsp
	popq	%rbp
	retq

