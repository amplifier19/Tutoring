.data
p: .asciiz "Positive"
n: .asciiz "Non Positive"
.text 
.globl main
main:

# Read an integer
li $v0, 5
syscall

# Zero
beq $v0,$zero,exit

# Negative
slt $a0,$v0,$zero
bne $a0,$zero,minus

# Positive
la $a0,p
li $v0,4
syscall
j exit

minus:la $a0,n
      li $v0,4
      syscall
exit:li $v0,10
     syscall