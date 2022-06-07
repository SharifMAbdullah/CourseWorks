.data 
	message: .asciiz "Overflow detected\n"
	negMessage: .asciiz "-"
	 
.text
	addi $t0,$zero,54654567443
	addi $t1,$zero,2
	
	#check if (a>0)&&(b<0)
		slt $s0,$zero,$t0
		slt $s1,$t1,$zero #check if b<0
	
		and $s2,$s0,$s1
	
	#check if (a<0)&&(b>0)
		slt $s3,$t0,$zero #check if a<0
		slt $s4,$zero,$t1 
	
		and $s5,$s3,$s4
	
	and $t4,$s0,$s4		#check if (a>0) && (b>0)
	or $t2,$s2,$s5		#check if (a>0)&&(b<0) || (a<0)&&(b>0)
	and $t3,$s1,$s3		#check if (a<0) && (b<0)
	
	bnez $t3,multiply
	bnez $t4,multiply
	bnez $t2,special_case
	
	special_case:
		multu $t0,$t1
		mflo $s0
		li $v0,4
		la $a0,negMessage
		li $v0,1
		add $a0, $zero, $s0
		syscall
		j exit
		
	#for multiplication otherwise
	multiply:
		mult $t0,$t1
		mfhi $at
			
	
	beq $at,$0,no_overflow
	
	#code for reporting overflow 
	overflow:
		li $v0,4
		la $a0,message
		syscall
		j exit
			
	no_overflow:
	mflo $s0
	#for printing if no overflow
	li $v0,1
	j exit
	
	exit:
		li $v0,10
		syscall
