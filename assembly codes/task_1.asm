.data
	array: .space 2212 	
	size: .word 40
	promptRow: .asciiz "Enter total row number: "
	promptCol: .asciiz "\nEnter total column number: "
	promptArr: .asciiz "\nEnter the array: \n"
	promptRowSwap1: .asciiz "\nEnter the first row number you want to swap: "
	promptRowSwap2: .asciiz "\nEnter the second row number you want to swap: "
	showArray: .asciiz "Array after swapping rows :\n"
	space: .asciiz " "
	newLine: .asciiz "\n"
	.eqv DATA_SIZE 4
 
.text
	main:
 
	#take input row number
	li $v0, 4
	la $a0, promptRow 
	syscall
	li $v0, 5
	syscall
	move $s0,$v0
 
	#take input column number
	li $v0, 4
	la $a0, promptCol 
	syscall
	li $v0, 5
	syscall
	move $s1,$v0		
 
	#store the total size required to hold the array as intended by user
	mult $s0, $s1
	mflo $s3			# $s3 hold row*col
 
	#take input whole array
	li $v0, 4       	
    	la $a0, promptArr        
    	syscall
 
   	li $t0,0		#set counter to 0
   	
	while1:
    		li $v0, 12		
    		syscall 
    		sb $v0, array($t0)       #store input 
    		
    		li $v0, 12		
    		syscall 
    		
    		addi  $t0, $t0, 1  	 #increase by 1 to to get to next char
    		beq $t0, $s3, continue
    	j while1
 
    	#COntinue taking inputs for exchanging row
    	continue:
    		li $v0, 4
		la $a0, promptRowSwap1
		syscall
 		li $v0, 5
		syscall
		move $s4,$v0		# $s4 holds the serial of first row to be swapped

     		li $v0, 4
		la $a0, promptRowSwap2
		syscall
 		li $v0, 5
		syscall
		move $s5,$v0 		# $s5 holds the serial of second row to be swapped
	j swap
	
	#####DO THE ACTUAL SWAPPING######
	swap:
		li $t0, 0
		la $t1, array($t0)
		move $s6,$t1		# $s6 holds base address
		j for
		
		for:
		
			beq $t0,$s1,print		#if counter == colNumber exit
			mul $t6, $s1,$s4		
			
			add $t1,$t6,$t0	
			add $t1,$t1,$s6			#base address + data size* (row number* total column number)
			
			mul $t7, $s1, $s5	
			
			add $t2,$t7,$t0			#ans = ans + first_row_col_position
			add $t2, $t2, $s6		#ans = ans + second_row_col_position			
			
			lb $t3,0($t1)	
			lb $t4,0($t2)
			sb $t4,0($t1)
			sb $t3,0($t2)
			
			addi $t0,$t0,1			#counter++
		j for
		
	j print
	
	print:
	# print message
	li $v0, 4
	la $a0, showArray 
	syscall
	li $t0, 0
	
	#print array after swapping
	while:
		beq $t0,$s3,exit
		lb $t7,array($t0)
		
    		li $v0, 11		
    		move $a0,$t7
    		syscall 
    		li $v0, 4		
    		la $a0,space
    		syscall 
    		addi  $t0, $t0, 1
    	
		div $t0,$s1
		mfhi $t6
		beqz $t6, newL
		bnez $t6,while
		newL: 
			li $v0, 4		
    			la $a0,newLine
    			syscall 
    			j while
    	
		
	exit:
	li $v0, 10
	la $a0, showArray 
	syscall