.data 
	input1: .asciiz "Enter a number: "
	input2: .asciiz "\nEnter another number: "
	messageQ: .asciiz "\nQuotient = "
	messageR: .asciiz "\nRemainder = "
	
.text
	#get first input
	li $v0,4
	la $a0,input1
	syscall
	li $v0,5
	syscall
	move $t0,$v0
	
	#get second input
	li $v0,4
	la $a0,input2
	syscall
	li $v0,5
	syscall
	move $t1,$v0
	
	slt $s0,$zero,$t0	#to compare if a<0 
	slt $s1,$zero,$t1	#to compare if b<0
	and $t2,$s0,$s1		#to check if both the above statements is true
	
	bnez $t2,special	#if and operation holds, go to special case
	beqz $t2, normal
	
	special:
		divu  $t0,$t1
		j continue
	
	normal:
	div $t0,$t1
	j continue
	
	continue:
	mflo $s2
	mfhi $s3
	
	#for printing quotitent
	li $v0,4
	la $a0,messageQ
	syscall
	li $v0,1
	add $a0,$zero,$s2
	syscall
	
	#for printing remainder
	li $v0,4
	la $a0,messageR
	syscall
	li $v0,1
	add $a0,$zero,$s3
	syscall
	
	#exit
	li $v0,10
	syscall
