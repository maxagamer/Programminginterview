
##### What is the time complexity of the following code(big_O_examples.cpp)?

The time Complexity of "foo" in "big_O_examples.cpp" is 2n where n is the size of the vectro "vec".

---

##### For each of the following time complexities: $O(1), O(log~n),~O(n),~ ~O(n~log~n)$ and $O(n^2)$ give an algorithmic example:

#### $O(1)$:

```
int add(const int a, const int b){
return a+b;
}
```

Just add two integers and return them. 

#### $O(log~n)$:

```
struct node* search(struct node* root, int key){

    // Base Cases: root is null or key is 
    // present at root`

    if (root == NULL || root->key == key)

       return root;

    // Key is greater than root's key

    if (root->key < key)
	return search(root->right, key)

    // Key is smaller than root's key

    return search(root->left, key);

}
```
Source: https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/

In a Binary-Tree the height of the tree is $log~n$ therefore if you search for an Element you just have to follow the right path to get to your Element in $O(log~n)$ time.

#### $O(n)$

```
int retSmallest(const vector<int> &vec){
	int min = INT_MAX;
	for(int i: vec){
		if(min > i) min = i;
	}
	return min;
}
```

This function loops through every Element inside "vec". Therefore it has a runtime of $O(n)$.

#### $O(n~log~n)$
```
struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* CreateNode(int data)
{
    Node* newNode = new Node();
    if (!newNode) {
        cout << "Memory error\n";
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* InsertNode(Node* root, int data)
{
    // If the tree is empty, assign new node address to root
    if (root == NULL) {
        root = CreateNode(data);
        return root;
    }
 
    // Else, do level order traversal until we
	// find an empty
    // place, i.e. either left child or right 
    // child of some
    // node is pointing to NULL.
    queue<Node*> q;
    q.push(root);
 
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
 
        if (temp->left != NULL)
            q.push(temp->left);
        else {
            temp->left = CreateNode(data);
            return root;
        }
 
        if (temp->right != NULL)
            q.push(temp->right);
        else {
            temp->right = CreateNode(data);
            return root;
        }
    }
}


```
Source: https://www.geeksforgeeks.org/insertion-in-a-binary-tree-in-level-order/

If you create and insert every Element of an Array it has to traverse through the hole Array making it already $O(n)$ and insert has a time complexity of $O(log~n)$ which makes it $O(n~log~n)$.

#### $O(n^2)$ 

```
void printDoubles(const vector<int> &vec){
	for(int a = 0; a < vec.size(); a++){
		for(int b = 0; b < vec.size(); b++){
			if(a!=b && vec) cout << vec.at(b);
		}
	}
}
```

Checks every Element against each other if there is a double and if there is it prints it out. Checking every Element of "vec" against every Element of "vec" makes it : $n\cdot n = n^2\Rightarrow O(n^2)$ 

---
##### Describe a systematic approach for solving a problem in a programming interview.

First find an bruteforce example and after this try to improve from there.

---


