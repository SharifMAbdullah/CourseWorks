.data
	mynumber: .word 23
	
.text
	li $v0, 1
	lw $a0, mynumber
	syscall 