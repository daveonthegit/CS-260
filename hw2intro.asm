#IVERSON

#Given C++ Statement: n = 17-19*n;
#ALLOC: n->$s0

add  $t0, $s0, $s0   # t0 = 2n
add  $t1, $t0, $t0   # t1 = 4n
add  $t1, $t1, $t1   # t1 = 8n
add  $t1, $t1, $t1   # t1 = 16n
add  $t1, $t1, $t0   # t1 = 16n + 2n = 18n
add  $t1, $t1, $s0   # t1 = 18n + n = 19n

addi $t2, $zero, 17  # Load 17 into $t2 by takin advantage of $zero and addi
sub  $s0, $t2, $t1   # s0 = 17 - 19n
