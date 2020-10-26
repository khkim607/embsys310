Q1.

a) 2147483647 -> -2147483648
b) R1 = 0x7fffffff -> 0x80000000
c) N=0, V=0 --> N=1, V=1. N=1 means negative value after calculation and V=1 means overflow condition reached after calculation
0x7fffffff is the maximum integer value possible. Increasing by 1 results in overflow condition since the output value is negative which is wrong. So Application Program Status Registers N(indicating NEGATIVE) and V(indicating OVERFLOW) are set. 

Q2. 

a) -1 -> 0
b) N=0, V=0, --> N=0, V=0. 0xffffffff is -1 in decimal. increasing by 1 results in 0. This is in the normal range of operation of positive and negative intergs the system support. So the ASPR registers N/V show no abnormal flag.

Q3.

a) 2147483647 -> 2147483648 -> 2147483649
b) N=0, N=0, -> N=1, V=1, -> N=1, V=0. The values in register R1(counter variable) is considered 2's complement of signed integer. So negative flag N is set even if the variable counter is declared unsigned integer. The overflow flag V is set when the signed overflow in addition happens (0x7fffffff (2147483647)-> 0x80000000 (2147483648)), then it set to 0 at next increasement. 

Q4. 

a)4294967295 -> 0 -> 1
b) N=0, V=0 --> N=0, V=0 --> N=0, V=0. N register remains 0 since the results show the positive valued. V register also remains 0 since the results of addition of two positive values remains positive

Q5.
