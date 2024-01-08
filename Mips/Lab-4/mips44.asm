.data
.text
.globl main
main:

# Read an integer
li $v0,5
syscall
# Copy the integer to $s1
move $s0,$v0

# Init $s1 loop index
li $s1,0
# Copy * char to $a0 
li $a0,'*'

loop:beq $s0,$s1,exit
       li $v0, 11
       syscall
       addi $s1,$s1,1
       j loop
exit:li $v0,10
     syscall
