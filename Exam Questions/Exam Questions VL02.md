##### How can we exploit bit operations for operations with sets?

If we use bit operations we can cast the datatype (whatever it is) to just some bits that we can easily manipulate without caring about the datatype we're looking at.

---

##### Explain the difference between arithmetic and logical right shifts for negative signed integers:

If we shift arithemically we divide by 2 regardless of the sign of the value e.g. : -1 shifted by 1 or 2 bits is still -1, but if we do it logically we will fill every "new" bit with a 0, even the MSB(most significant bit), which is used to determin the sign of our integer, so a negative number becomes positve and even worse, because of the two's complement we get a completly unrelated number out of this.

---

##### Explain what the following code does (n & (n-1)) == 0:

The Code checks if $n$ is either a 0 or a power of 2.
If it is  $n=0b0000\_0000$ then $n-1=0b1111\_1111$, because of two's complement so $n\&(n-1)=0b0000\_0000$ because they have no bit in common, it is the same for any $2^n$, because it only contains 1 bit(this is defined in the binary numbers). So if you subtract one from that single bit every bit before is flipped and they have nothing in common so the result will also be 0.

---

##### Outline an algorithm to count the number of bits that are set to 1 in an integer. (no bitset or built-in functions):


```
size_t countBits(size_t n){
	size_t sum      = 0;
	size_t a        = 1;
	size_t compare  = 0;
	
	while(n != compare){
	    if(a & n) sum++;
	    n>>=(unsigned)1u;
	}
	
	return sum;
}
```

We create a sum that we will return to count all bits. We also create a variable initialized as 1 so we can compare if the LSB(least significant bit) is set, if so we add one to the sum, then we shift n one to the right(logically as explained before). The loop ends when the given value is equal to 0, therefore no bits are left.

---

##### Outline an algorithm to reverse the bits in an unsigned integer.

The easiest, but not fastest way, is to just put them into a stack and pop back every Element. You can also do this faster by just using ~ in front of the element. This will flip every bit.

---

##### Imagine you have to reorder integers in an array so that the odd entries appear first. How is this problem related to Quicksort’s partitioning function?

Well instead of comparing the numbers for larger or smaller you can just check if the modulo 2 is qual to two or not and then sort that way.

