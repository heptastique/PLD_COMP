
	.globl main

main:

	pushq	%rbp
	movq	%rsp, %rbp
	subq	$0, %rsp

	movl	$97, %edi
	call	putchar

	addq	$0, %rsp
	popq	%rbp
	retq

