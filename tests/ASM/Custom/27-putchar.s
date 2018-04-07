
	.globl main

main:

	pushq	%rbp
	movq	%rsp, %rbp
	subq	$0, %rsp

	movl	$97, -8(%rbp)
	mov 	-8(%rbp), %edi
	call	putchar

	addq	$0, %rsp
	popq	%rbp
	retq
