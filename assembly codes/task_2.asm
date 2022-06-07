.data 
	input1: .asciiz "Enter a number: "
	input2: .asciiz "\nEnter another number: "
	ans: .asciiz "\nMultiplication result: "
	message: .asciiz "\nOverflow detected\n"
	
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
		
	slt $s0,$t0,$zero	#to compare if a<0 
	slt $s1,$t1,$zero	#to compare if b<0
	xor $s2,$s0,$s1		#to check if only one of the above statements is true
	
	 bnez $s2,special	#if xor operation holds, go to special case
	 j continue
	 
	special:
	multu $t0,$t1
	mflo $s0
	
	li $v0,1
	add $a0,$zero,$s0
	syscall
	li $v0,10
	syscall
	  
	 continue:
	#for multiplication
	mult $t0,$t1
	mfhi $at
	mflo $s4
	
	bne  $s4,-2,no_overflow
	beq $at,$0,no_overflow
	
	#for reporting overflow
	li $v0,4
	la $a0,message
	syscall
	li $v0,10
	syscall
	
	
	no_overflow:
	li $v0,4
	la $a0,ans
	syscall
	mflo $s0
	li $v0,1
	add $a0,$zero,$s0
	syscall
