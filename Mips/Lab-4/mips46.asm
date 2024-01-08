.data
ast: .asciiz "*"
nl: .asciiz "\n"
.text
.globl main
main:
# Loop indexes
li $s0,0
li $s3,0

# Limit of loop1 
li $v0,5
syscall
move $s1,$v0

# Limit of loop2
li $v0,5
syscall
move $s2,$v0
      
loop1:beq $s1,$s0,exit
      la $a0,nl
      li $v0,4
      syscall
      addi $s0,$s0,1
      li $s3,0
      loop2:beq $s2,$s3,loop1
             la $a0,ast
             li $v0,4
             syscall
             addi $s3,$s3,1
             j loop2
exit:li $v0,10
     syscall
