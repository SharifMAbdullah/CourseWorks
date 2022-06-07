.data
	num1: .word 20
	num2: .word 199
.text
	lw $s0, num1
	lw $s1, num2
	
	sub $t0, $s0, $s1
	move $a0,$t0
	li $v0,1
	syscall 
	