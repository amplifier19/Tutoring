.data
z: .asciiz "Zero"
n: .asciiz "Non Zero"
.text 
.globl main
main:

# Read an integer
li $v0, 5
syscall

# Zero
beq  $a0,$zero,zero

# Non Zero
la $a0,n
li $v0,4
syscall
j exit

zero:la $a0,z
      li $v0,4
      syscall
exit:li $v0,10
     syscall