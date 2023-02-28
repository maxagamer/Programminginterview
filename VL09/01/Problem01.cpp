#include <iostream>

// this function calculates the
// sum of a * sum_{k = 1}^n =a * (n(n+1))/2
int returnSumOfMultiples(int a, int n){
    return a * (n*(n+1))/2;
}

int sumOfMultiples(int a, int b, int n){
    // this is so it will be < n (in our example < 10 or < 1000)
    n--;
    // sum to calculate the sum
    // first is every multiple of a < n, which is n/a
    int sum  = returnSumOfMultiples(a, n/a);
    // second the same thing with b
    sum     += returnSumOfMultiples(b, n/b);
    // now we subtract everything we calculated twice

    // (see Inclusion Exclusion), with this principle
    // it should be possible to calculate an array of
    // integers (as long as they are smaller than n)
    // and give back the sum of it
    sum     -= returnSumOfMultiples((a*b) , n/(a*b));
    return sum;
}

int defNotMain01() {

    std::cout << sumOfMultiples(3, 5, 10) << "\n";

    std::cout << sumOfMultiples(3, 5, 1000);

    return 0;
}
