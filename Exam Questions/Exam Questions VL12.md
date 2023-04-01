
##### Describe a kernel of the k-VertexCover-Problem: figure out which nodes have to (and which don't have to) be in the VertexCover.

---

##### Design an algorithm that constructs a minimal vertex cover for graphs where all nodes have degree at most $2$. Your algorithm should run in time $O(n^c)$ where $n$ is the number of nodes in the graph, and $c$ is a constant (bonus point if you achieve $c=1$). Prove the correctness and the runtime of your algorithm.

Let A be list where you store every node inside the minimum Vertex Cover. First you look at the size of $|V|$. If $|V|$ is odd $\Rightarrow|A|=\frac{|V|-1}{2}$  if $|V|$ is even $\Rightarrow|A|=\frac{|V|}{2}$. A graph where ever node has a degree of 2 at most, has to be either a circle or a line, where there is only one path. In a circle every node has degree 2 and in a line the first and the last node have degree 1 and the rest has degree 2.

Algorithmn:

1. if $|V|\%2=1$:
		if first node.degree() = 1:
			for i in $|V| (i=\{1,2,...,|V|\}$
				if $i\%2=0$
					$A$ add node.at(i)
		else:
			for i in $|V| (i=\{1,2,...,|V|\}$
				if $i\%2=1$
					$A$ add node.at(i)
	else:
		for i in $|V| (i=\{1,2,...,|V|\}$
				if $i\%2=1$
					$A$ add node.at(i)

```
// our index here starts at 1
// i%2 is for modulo
```


The only if where it matters that $i\%2=0$ is the first one. On all other cases it is only necessary to add each second node. This has Time Complexity of $O(n)$. This works because, if the size of the vertices determines which Vertex Cover is the minimal one. 

Case odd:
The minimal Vertex Cover of an odd line or circle is adding every second vertex, by starting at the second vertex, because if you start by the first one you have$\lceil{\frac{|V|}{2}}\rceil+1$ vertices and the Complement of that has $\lceil{\frac{|V|}{2}}\rceil-1$ because the first will always also add the last and the Complement always will have those in between.

Case even:
In an even case it doesn't matter if it is a line or a circle. You can just add every second vertex. You can either start by the first or the second. In a Circle it works, because every vertex has degree 2 and if you add one you will also add two edges so you only need $\frac{|V|}{2}$ vertices. In a line it is basically the same just by starting at the first you will include the start but exclude the ending one and vice versa.

---

##### Describe your approach at this weeks programming exercise (Problem 1773-A).
How does your algorithm and a pair of valid permutations?

While looking at the Problem I discovered for every $n>3$ has a solution and that it can be found by following a "path" described by my algorithmn. In short my algorithm looks at the first entry($a[0]$) then tries the smallest possible combination $i$.(Exluding: $i \ne 0~\wedge~i\ne a[0]$). Then writing $q[a[i]]=i$. (In the first case hast $i$ to be $i\in\{0,1,2\}$), then it writes to $p[i]=0$. After the first step we remember the value $i$ and look for which $j$ is $i=a[j]$(I use a Hashmap for faster Index Recovery) to find the next entry we will work on. We now continue until we reach the end. If we somehow land on a number we already accessed this way we will skip to the next entry we haven't touched yet and continue from there. I also have special cases for $n<2$ which is impossible, $n==3$ where I hardcoded every case and for $a=\{1,2,...,n\}$.

