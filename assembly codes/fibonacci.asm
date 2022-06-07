.data 
	prompt: .asciiz "Enter the number: "
.text
	#take input and store the number of numbers that are to be shown in fibonacci series
	li $v0,4
	la $a0,prompt
	syscall
	
	li $v0,5
	syscall
	
	move $t0,$v0
	
	#store the first two numbers
	addi $t1,$zero,0
	addi $t2,$t1,1
	
	#print these two numbers
	li $v0,1
	move $a0,$t1
	syscall
	
	li $v0,1
	move $a0,$t2
	syscall
	
	#set i=2
	addi $s0,$zero,2
	#print the rest n-2 numbers
	while:
		beq $s0,$t0,exit
			move $s1,$t2
			add $t2,$t1,$t2
			li $v0,1
			move $a0,$t2
			syscall
			move $t1,$s1
			addi $s0,$s0,1 #i++
		j while
	exit: