#IVERSON
mask:    .word 0xFFFFF83F       # 1. Define a constant word in memory named 'mask' with the value 0xFFFFF83F

start:   la $t0, mask          # $t0 <- addr. of 'mask'
         lw $t0, 0($t0)        # $t0 <- value of 'mask'
         la $t3, shftr         # $t3 <- addr. of 'shftr'
         lw $t3, 0($t3)        # $t3 <- value of 'shftr' 
         and $t3, $t3, $t0     # $t3 <- 'mask' applied onto $t3 using bitwise AND 
         andi $t2, $t2, 0x001F # Mask the lower 5 bits of $t2 (since 0x001F = 0001 1111 in binary)
         sll $t2, $t2, 6       # $t2 <- $t2 shifted left by 6 bits (equivalent to multiplying by 64)
         or $t3, $t3, $t2      # $t3 <- Bitwise OR between $t3 and $t2 (merges modified bits into $t3)
         la $t5, shftr         # $t5 <- addr. of 'shftr'
         sw $t3, 0($t5)        # shftr <- $t3 (Changes the value located at addr. of shftr)

shftr:   sll $t3, $t1, 0       # $t3 <- t1 (shift by 0 does nothing); However, after the code runs the shift value will change 
                                #because the code is self modifying.

