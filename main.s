.text           # section declaration
.global main  	#	 entry point to the ELF linker or loader.	

main:

	movl $'O', %edi 
	call putchar
	movl $'K', %edi 
	call putchar
	movl $'\n', %edi 
	call putchar

	retq

