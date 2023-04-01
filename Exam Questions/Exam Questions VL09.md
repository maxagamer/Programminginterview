##### Argue why topological sortings only exist for acyclic graphs.

Well if there is a cycle inside the directed Graph and you somehow reach the cycle(which has to happen sometime). You will enter the cycle and look for and end. You will be a dog chasing his own tail, as there is no end to it and you're stuck in the loop without ever leaving it.

---

##### Briefy describe how you approached and solved Project Euler Problem 1.

Well I remember that is is solvable by using inclusion exclusion and if you for: 
$x=1000,N:=\{3,5\}$ and multiples of both $3,5 = 3\cdot 5=15$
$\lfloor\frac{x}{N}\rfloor \Leftrightarrow \lfloor\frac{1000}3\rfloor=333,\lfloor\frac{1000}{5}\rfloor=200,\lfloor\frac{1000}{15}\rfloor=66$ 

$\sum_{k=1}^i a\cdot k=a\cdot\frac{i(i+1)}{2}$
$\Rightarrow 3\cdot\frac{333(333+1)}{2}+5\cdot\frac{200(200+1)}{2}-15\cdot\frac{66(66+1)}{2}$
$=234168$

---

