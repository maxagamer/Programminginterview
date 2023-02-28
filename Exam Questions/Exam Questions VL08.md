## Exam Questions VL08

##### If you need to find the shortest path between two nodes in a graph where all edges have length 1, which algorithm would you use and why?

I would use Dijkstra to solve this, because it is an simple task and everything else would be overkill.

---

##### Assume that you need to find a shortest path in a relatively small graph with  arbitrary edge lengths, and you have to have a working algorithm very soon. Which algorithm would you choose and why?

I would use Floyd-Warshall algorithm, because it is easy to implement and will compute a bit faster than Dijkstra. It will find the fastest path in the fastest time.

---

##### Why does Dijkstra's algorithm not work with negative edge lengths?

If we try Dijkstra on a Graph with a negative weight it will compute infinity as a Distance for those distances which is wrong.

---
