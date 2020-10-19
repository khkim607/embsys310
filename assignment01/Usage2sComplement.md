### Why use two’s complement to represent negative numbers?
In computer hardware, it requires to have an effective way of representing negative numbers and a way of computation involving subtraction since numbers are represented only by sequence of bits of **0** and **1** without extra symbols. Two's complement of integers is adopted to represents a negative counterpart **'-a'** of an integer **'a'** because it is more efficient than other alternative methods of one's complements or "sign-and magnitude" method.

It is came from mathematical technique known as "method of complements." Method of complements positions range of positive and negative integers in a symmetric way that they can use the same algorithm for addition throughout the whole range. For a given number of places, of the total 16 places of 2^4 = 16 in case of 4-bit operation,  half of the possible representations of numbers encode the positive numbers, the other half represents their respective "additive inverses"[link to Wikipedia!](https://en.wikipedia.org/wiki/Additive_inverse). Means **'b'** is an additive inverse of **'a'** if **'a'+'b'=0**. 
Therefore a subtraction of a number is achieved by adding two's complement of the number instead. 

One's complement is similar way of subtraction by adding complement of the number. But, the difference is the carry must be added to LSB of the result in one's complement method while the carry can simply be ignored in two's complement operation.
While one's complement waste representation space due to **-0**, two's complement use additional space of **-8**.
 
* For 4-bit representation:

0 | 1 | 2 | 3 | 4 | 5 | 6 | Integer
-- | -- | -- | -- | -- | -- | -- | --
0000	| 0001	| 0010	| 0011	| 0100	| 0101	| 0110	| 0111	
1111	| 1110	| 1101	| 1100	| 1011	| 1010	| 1001	| 1000	
-0	| -1	| -2	| -3	| -4	| -5	| -6	| -7	| 1's complement
-1	| -2	| -3	| -4	| -5	| -6	| -7	| -8	| 2's complement

In summary,
* Computer hardware need a way to represent negative numbers
* Method of complement is an effective way of representing a set of positive and negative integers as "additive inverse" pairs.
* Two's complement is more efficient than one's complement in saving storage and computing less 

