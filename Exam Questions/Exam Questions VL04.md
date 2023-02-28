## Exam Questions VL04

##### How to delete a (non-tail) node from a singly linked list without knowing its predecessor in O(1) time?

We just copy the data from the successor Data into the node that has to be deleted. We then point to the next node of the successor and after this we delete the successor.

---

##### Explain the runner technique using a linked list example.

You could use two points $p_1,p_2$ where $p_1$ moves to the next Element while $p_2$ moves two each times $p_1$ moves one. When you reach the end with $p_2$ you know $p_1$ is at the middle. ($p_2$ has to start)

---

##### If you were to tune the code for speed, how would you implement a stack?

```
struct Node{
	int data;
	Node node *last;
};

class Stack{
	Node head;
	public:
		Stack(){
			head = NULL;
		}
		push(int n){
			if(head == NULL){
				head.data = n;
				head->last= NULL;
			}else{
				Node node;
				node.data = head->data;
				node.last= head->last;
				head.data = n;
				head.last = *node;
			}
		}
		int pop(){
			if(head != NULL){
				Node node = head->last;
				int tmp = head->data;
				delete head;
				head = node;
				return tmp;
			}else return NULL;
		}
}
```

Everytime I add an Element I will link to the last Element before. When pushing an Element we differentiate between an empty stack or pushing a a new Element. If it is empty we create the head if not we will copy everything from head to a new node and then create a new head with the new data pointing to the old information. When we pop we check if the Stack is empty. If not we will create a pointer to the node before and safe the information in a temporary integer. We then delete the head and reasign it to the node we saved earlier. After this we can finally return the data stored in the old head.

---

##### How can we use a std::list in C++ as a queue?

In a Queue utilizes the FIFO(first-in first-out). If we only use pop_front() and push_back(data d) we can use it as a queue.

---

##### How does a binary tree and a binary search tree differ?

Binary search tree's are sorted where each element left of a node is smaller and every element on the right of a binary search tree is larger. In a Binary Search Tree Each Element has to only appear once, while in a binary tree you can have multiple of one value. Operations on binary tree's are usally slower and the reason for that is that they are unsorted.

---

##### Describe the different types of binary tree traversals.

In pre order you print the node you starded from and go to the lift print this and go again to the left until you reach NULL after this you start from the last visited node and go to the right until you reach null again. You print each node upon visit. In order you go to the left until you reach NULL following this you will print the node and go to the right of the last visited node until you get to NULL. You repeat this until you reach NULL for the last right node. In this order every node printed is the one from the left to the right starting by the last left going to the last right node.

---

##### How does a trie and a radix tree differ?

The radix tree is more space efficient as it saves string/word parts as information, but only refers to it's parent and is therefore not as versatile as a trie. The trie saves each character of words used and terminates on NULL nodes. For that reason it is not as space efficient but can save more unique strings/words and is in my opinion better fort autocompletion.

---


