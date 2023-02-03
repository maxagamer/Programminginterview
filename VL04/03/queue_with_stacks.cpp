// enable assertions in release build
#ifdef NDEBUG
#undef NDEBUG
#endif

#include <cassert>
#include <stack>
#include <iostream>

using namespace std;

/************** begin assignment **************/
// Queue insertion and deletion follows first-in, first-out semantics; stack
// insertion and deletion is last-in, first-out. How would you implement a queue
// with the help of two stacks?
//
// Of course, implementing a queue with stacks is not efficient, but it is a
// good exercise to get familiar with data structures and templates ;).
// When coding in real life use the C++ queue implementation:
// https://www.geeksforgeeks.org/queue-cpp-stl/
// Or if a problem requires it, use the priority queue implementation of std:
// https://www.geeksforgeeks.org/priority-queue-in-cpp-stl/

// simple queue implementation with two stacks
template <typename T> class Queue {
private:
  // these are the only class variables you need to implement the queue.
  stack<T> enq, deq;

public:
  void enqueue(T x) {
      // we need to move every element of enq to deq, so we can add the
      // element to the end of the list
      // after we added the element we push everything back to enq
      while(!enq.empty()){
          deq.push(enq.top());
          enq.pop();
      }
      enq.push(x);
      while(!deq.empty()){
          enq.push(deq.top());
          deq.pop();
      }
  }

  T dequeue() {
      // when the list is empty, there is nothing to return
      if(empty()) return NULL;

      // we need to store the value somewhere, because
      // for some unknown reasons(at least for me) with
      // pop() method of a stack it will only delete and
      // not give back the element therefore we have to
      // save it in a temporary variable
      T tmp = enq.top();
      enq.pop();
      return tmp;
  }

  size_t size() { return enq.size(); }
  // self-explanatory
  bool empty() { return enq.empty(); }
};
/*************** end assignment ***************/

int main() {

{
    Queue<int> my_queue;
    assert(my_queue.size() == 0);
    assert(my_queue.empty());
    my_queue.enqueue(1);
    my_queue.enqueue(2);
    my_queue.enqueue(3);
    assert(my_queue.size() == 3);
    assert(!my_queue.empty());
    assert(my_queue.dequeue() == 1);
    assert(my_queue.dequeue() == 2);
    my_queue.enqueue(7);
    assert(my_queue.size() == 2);
    assert(my_queue.dequeue() == 3);
    assert(my_queue.dequeue() == 7);
    assert(my_queue.size() == 0);
    assert(my_queue.empty());
  }
  {
    int n = 1000000;
    Queue<int> my_queue;
    for (int i = 0; i < n; ++i) {
      my_queue.enqueue(i);
    }
    assert(my_queue.size() == size_t(n));
    assert(!my_queue.empty());
    for (int i = 0; i < n / 2; ++i) {
      my_queue.dequeue();
    }
    assert(my_queue.size() == size_t(n / 2));
    assert(my_queue.dequeue() == n / 2);
    for (int i = 0; i < 10; ++i) {
      my_queue.enqueue(i);
    }
    for (int i = 0; i < n / 2 - 1; ++i) {
      assert(my_queue.dequeue() == n / 2 + 1 + i);
    }
    for (int i = 0; i < 10; ++i) {
      assert(my_queue.dequeue() == i);
    }
    assert(my_queue.size() == 0);
    assert(my_queue.empty());
  }
    cout << "all tests passed" << endl;

    return 0;
}
