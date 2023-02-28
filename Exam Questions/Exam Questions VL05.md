## Exam Questions VL05

##### Describe briefly the heap data structure.

A heap is a priority queue rigid structure which means it has a shape that is very consistant. This shape is that there will be no node in depth x when there is at least one space in depth x - 1. Every child of every node is also smaller as their parent counter part. 

---

##### How would you find the k longest words in a data stream? (You cannot back up to read an earlier value.)

I would use a minimum heap to store the strings I'm reading in. When every if find a word longer than the smallest element in the heap I would just exchange them by pop() the last element and then push the ne word onto it.

---

##### How would you address the problem of merging multiple sorted files that are too large for RAM?

I would solve it by divide and conquer. I start by using a fraction of both arrays (1 of both would also be enough) and merge them together after that delete the first space of both files and then continue until it is completly merged.

---

##### What are sorting networks?

Sorting networks can be interpreted as sorting algorithms that designed like logic gates that have constant sorting times because of the way they compare each element.

---

##### Why sorting may speed up set operations?

An easy example would be above where it is asked to find the k longest words in a stream. If you're looking to accomplish a specific goal a specific order of your items/elements may be necessary. The example above wants to store the k elements that are the largest ones appearing. If you just add them to a list you always have to look if every word you already have is bigger or smaller as the new one. For comparison the simpler algorithm explained would have a runtime of $O(n\cdot k)$ which is significantly higher than $O(n\cdot log(k))$.

---

##### What is a minimal perfect hash?

A minimal perfect hash is when every produced hash has a place without collision. That means you get your key and hash it put it into another list or table and this new list/table is the exact same size of your original table. No collision means if you hash your key another key won't produce the same hash as all the other ones you already produced.

---
