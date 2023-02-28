## Exam Questions VL06

##### What is backtracking?

Backtracking is kinda like brute force, the difference is that when you're backtracking your solutions and if you find one that won't succeed you reject it. It is basically a trimmed version of brute force.

---

##### How would you proceed to compute the n-Queens problem with backtracking as fast as possible?

The fastest way to backtrack this problem is to just test every configuration and reject every configuration that won't lead to a solution.

---

##### Describe some ideas how to solve the 15-puzzle with backtracking. (Tell me what you think is important.)

---

##### Why is efficient parallelization not trivial in most divide and conquer algorithms.

Because other algorithms fail where divide and conquer shines. We can, as stated in the name, divide the problem into subproblems where each of the subproblems can be computed by a different thread, which makes it easy multithread problems this way. Also merge them together can be easy as every thread can get their own space of memory and write to that(depending on the algorithmn).

---

##### Why may decrease and conquer be a better name choice for algorithms like quickselect or recursive binary search than calling them divide and conquer ?

Because you reduce the number of possible solutions every step we make or in other words we narrow it down. 

---

##### What is dynamic programming?

Dynamic programming is, when we can use something we already computed in another computation later on. For example if you want to backtrack Fibonacci-Numbers we can cache the already calculated ones in an array and can look up if we already solved one of them, so we don't have to calculate each number again and again.

---

##### Compare the top-down approach with the bottom-up approach used in dynamic programming.

For example we can use the Fibonacci approach again. Bottom-up starts from the bottom of our fibonacci numbers as in F\[0\]= 1 annd F\[1\] = 1.
If we now search for n-th number we will start computing from the first two to n and save every solution in a vector or array. Top-down is used by searching the n number from F\[n\] = F\[n - 1\] + F\[n  - 2\] until we come to F\[0\]= 1 annd F\[1\] = 1. We also save every solution once they are computed.

---

##### Present briefly a greedy heuristic of your choice.

The non overlapping scheduling Problem has an heuristic that is easy to understand. You look up the first starting interval. From there you always pick up the closest next interval to the end of your current interval. Do this until no more intervals remain.

