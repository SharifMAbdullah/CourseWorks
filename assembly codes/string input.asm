.data
	prompt: .asciiz "Enter a string:\n"
	output: .asciiz "\nOutput is:\n"
	input: .space 81
	size: .word 81
	
.text
	#prompt for a string
	li $v0,4
	la $a0,prompt
	syscall
	
	#take input
	li $v0,8
	la $a0, input
	lw $a1, size
	syscall
	
	#show text
	li $v0,4
	la $a0,output
	syscall
	
	#show number
	li $v0,4
	la $a0, input
	syscall
	