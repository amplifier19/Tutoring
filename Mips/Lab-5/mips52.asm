.data 
	str : .space 16
	num1 : .word 0
	nl : .asciiz "\n"
.text
main:
	la $a0,str
	li $a1,16
	li $v0,8
	syscall
	move $s0,$a0

	# αποθήκευση της διεύθυνσης μνήμης του num1 στον $t1 
	la $t1,num1
	
	# αποθήκευση του περιεχομένου που βρίσκεται στην διέυθυνση μνήμης (η διέυθυνση μνήμης βρίσκεται αποθηκευμένη στον $t1)
	lw $t2,($t1)
start: 
	lb $s1,($s0)
    beqz $s1,continue
    addi $s0,$s0,1
    addi $t2,$t2,1 
    j start 

continue: 
	la $a0,nl
    li $v0,11
    syscall

loop:
	addi $s0,$s0,-1
    beqz $t2,end
    lb $s1,($s0)
    move $a0,$s1
    li $v0,11
    syscall
    addi $t2,$t2,-1
    j loop
    
end:
	li $v0,10
	syscall


