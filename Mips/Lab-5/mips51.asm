.data
	str: .space 16
.text
.globl main 
main:
	la $a0,str
	li $a1,16
	li $v0,8
	syscall
	move $t3,$a0
	
	lb $t1,($t3)
	li $t2,0
count:  
	beqz $t1,exit
	addi $t2,$t2,1
	addi $t3,$t3,1
	lb $t1,($t3)
	j count
	

exit:	
	move $a0,$t2
	li $v0,1
	syscall
	li $v0,10
	syscall
	