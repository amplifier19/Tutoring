.data
.text
.globl main
main:

# Read an integer
li $s0,5

# Copy * char to $a0
li $s1,0
# Init $s1 loop indexer
li $a0,'*'

loop:beq $s0,$s1,exit
       li $v0, 11
       syscall
       addi $s1,$s1,1
       j loop
exit:li $v0,10
     syscall
