.data 
	size : .word 10
	sum : .word
	i : .word 
	arr : .word 1, 15, 0, -3, 99, 48, -17, -9, 20, 15
.text
	la $t0,sum
	lw $t1,($t0)
	li $t1,0

	la $t2,size
	lw $t3,($t2)
	la $s0,arr

start:
	beqz $t3,end 
	lw $s1,($s0)
	add $t1,$t1,$s1
	
	# 4 bytes γιατί είναι ακέραιοι αριθοί τα στοιχεία του arr
	addi $s0,$s0,4   
	addi $t3,$t3,-1
	j start 
        
end:
    #la $t2,$t1
    #sw $a0,($t2)
    move $a0,$t1
    
    li $v0,1
    syscall
    li $v0,10  
    syscall 
