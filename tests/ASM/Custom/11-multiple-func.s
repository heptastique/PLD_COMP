
	.globl main

test1:

	pushq	%rbp
	movq	%rsp, %rbp
	subq	$0, %rsp


	addq	$0, %rsp
	popq	%rbp
	retq

main:

	pushq	%rbp
	movq	%rsp, %rbp
	subq	$0, %rsp


	addq	$0, %rsp
	popq	%rbp
	retq

