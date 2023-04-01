##### Describe the general idea of the algorithm by Edmonds & Karp in your own words.

You start with an empty sum of flow. Everytime you find a new flow from starting note to destination(target) node you will add it to the sum. You iterate through every possible flow and adjust the remaining flows accordingly to the flow you already added(subtract on the value of the edges).
You do this until there is no more flow to be found.

---

##### Describe your algorithm that solves the Problem $100$ ("$3n+1$"): what algorithmic techniques do you use?

My algorithm uses backtracking and saves every solution to a hashmap so we can lookup every solution we already calculated, so we don't have to calculate them over and over again.

---

##### Which algorithm do you use for Problem 459 ("Graph Connectivity"), and why?

First we read in n, therefore we are reading in n cases. Next we read in the first node and build up a array in which we store every character beginning by the first letter, we name it parent. In parallel we construct another array in which we fill with 0, we name it rank. We also initialize a value where we save our disjointed Sets, we name it DJSets.

We loop through every node and the edges. If we find a edge we unite them, but first look if the edge already exists. For every new edge we count down on DJSets. When we finish we will output DJSets as these has to be the number of our disjointed sets.

