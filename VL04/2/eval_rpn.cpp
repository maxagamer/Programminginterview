// enable assertions in release build
#ifdef NDEBUG
#undef NDEBUG
#endif

#include <cassert>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>

using namespace std;

    void printValues() {
        char c;
        c = '*';
        cout << c << ": " << (int) c << endl;
        c = '+';
        cout << c << ": " << (int) c << endl;
        c = '-';
        cout << c << ": " << (int) c << endl;
        c = '/';
        cout << c << ": " << (int) c << endl;
    }
    /*
     * checks if a given Char is a number between 0 - 9
     */
    bool checkIfNumber(char c) {
        int tmp = (int) c;
        if (tmp > 47 && tmp < 58) return true;
        else return false;
    }
    /*
     *  same function, but you can use integer, so we don't have to choose
     */
    bool checkIfNumber(int n) {
        if (n > 47 && n < 58) return true;
        else return false;
    }
    bool checkIfSymbol(char c) {
        return c == 42 || c == 43 || c == 45 || c == 47;
    }
    bool checkIfSymbol(int c) {
        return c == 42 || c == 43 || c == 45 || c == 47;
    }
    // src: lesson
    inline int string_to_int(const string &s) {
        bool is_negative = s[0] == '-';
        int result = 0;
        // if integer is negative start with index i = 1
        for (size_t i = is_negative; i < s.size(); ++i) {
            result = result * 10 + s[i] - '0';
        }
        return is_negative ? -result : result;
    }

    void throwError(){
        cerr << "Something went horribly wrong, your Syntax may be wrong" << endl;
    }

    void h(char c){
        cout << "here: " << c << endl;
    }

    void printStack(stack<int> stack){
        while(!stack.empty()){
            cout << stack.top() << endl;
            stack.pop();
        }
    }

/************** begin assignment **************/
// In Reverse Polish Notation, the operators follow their operands; for
// instance, to add 3 and 4, one would write 3 4 + rather than 3 + 4. If there
// are multiple operations, operators are given immediately after their second
// operands; so the expression written 3 − 4 + 5 in conventional notation would be
// written 3 4 − 5 + in reverse Polish notation: 4 is first subtracted from 3,
// hen 5 is added to it. An advantage of reverse Polish notation is that it removes
// the need for parentheses that are required by infix notation. While 3 − 4 * 5
// can also be written 3 − (4 * 5), that means something quite different from (3 − 4) * 5.
// In reverse Polish notation, the former could be written 3 4 5 * −, which
// unambiguously means 3 (4 5 *) − which reduces to 3 20 − (which can further be reduced to -17);
// the latter could be written 3 4 − 5 * (or 5 3 4 − *, if keeping similar formatting),
// which unambiguously means (3 4 −) 5 *.
// see also: https://en.wikipedia.org/wiki/Reverse_Polish_notation
//
// Write a program that takes an arithmetical expression in Reverse Polish
// Notation (RPN) and returns the signed integer that the expression evaluates
// to.
// - allowed mathematical operators are: + - * /
// - numbers (operands) and operators are separated by spaces
// - use a "stringstream" for separating the input tokens (numbers and operators)
//   https://www.geeksforgeeks.org/stringstream-c-applications/
// - use a stack<int> for stacking the numbers


// char:
//    48 - 57 <==> 0 - 9

int eval_rpn_old(const string &rpn_expression) {
    stack<int> numbers;
    //stringstream ss{rpn_expression};
    int sum = 0;

    if(rpn_expression.length() == 1){
        if(checkIfNumber(rpn_expression[0]))    return rpn_expression[0];
        else                                       throwError();
    }

    for(int i = 0; i < rpn_expression.length(); i++){
        char c = rpn_expression[i];
        switch(c){
            case '-':{
                // so we don't check further then the last index
                if(i != (rpn_expression.length() - 1)){
                    if(checkIfNumber(rpn_expression[i+1])){
                        string s = "";
                        for(int j = i+1; j < rpn_expression.length(); j++){
                            char b = rpn_expression[j];
                            if(b == ' '){
                                // we want to continue on the next number/symbol
                                i=j+1;
                                // save the number to the stack
                                // don't forget to make it negative, because we started with -
                                numbers.push((-1)*string_to_int(s));
                            }else s.push_back(b);
                        }
                    }
                }else{
                    return 0; //TODO Calculation
                }
            }
            case '+':{

                break;
            }
                // number cases
                {
                    case '0': {
                        if (i != (rpn_expression.length() - 1)) {
                            string s = "0";
                            for (int j = i; j < rpn_expression.length(); j++) {
                                char b = rpn_expression[j];
                                if (b == ' ') {
                                    i = j + 1;
                                    numbers.push((-1) * string_to_int(s));
                                } else s.push_back(b);
                            }
                        }
                    }
                    case '1': {
                        if (i != (rpn_expression.length() - 1)) {
                            string s = "1";
                            for (int j = i; j < rpn_expression.length(); j++) {
                                char b = rpn_expression[j];
                                if (b == ' ') {
                                    i = j + 1;
                                    numbers.push((-1) * string_to_int(s));
                                } else s.push_back(b);
                            }
                        }
                    }
                    case '2': {
                        if (i != (rpn_expression.length() - 1)) {
                            string s = "2";
                            for (int j = i; j < rpn_expression.length(); j++) {
                                char b = rpn_expression[j];
                                if (b == ' ') {
                                    i = j + 1;
                                    numbers.push((-1) * string_to_int(s));
                                } else s.push_back(b);
                            }
                        }
                    }
                    case '3': {
                        if (i != (rpn_expression.length() - 1)) {
                            string s = "3";
                            for (int j = i; j < rpn_expression.length(); j++) {
                                char b = rpn_expression[j];
                                if (b == ' ') {
                                    i = j + 1;
                                    numbers.push((-1) * string_to_int(s));
                                } else s.push_back(b);
                            }
                        }
                    }
                    case '4': {
                        if (i != (rpn_expression.length() - 1)) {
                            string s = "4";
                            for (int j = i; j < rpn_expression.length(); j++) {
                                char b = rpn_expression[j];
                                if (b == ' ') {
                                    i = j + 1;
                                    numbers.push((-1) * string_to_int(s));
                                } else s.push_back(b);
                            }
                        }
                    }
                    case '5': {
                        if (i != (rpn_expression.length() - 1)) {
                            string s = "5";
                            for (int j = i; j < rpn_expression.length(); j++) {
                                char b = rpn_expression[j];
                                if (b == ' ') {
                                    i = j + 1;
                                    numbers.push((-1) * string_to_int(s));
                                } else s.push_back(b);
                            }
                        }
                    }
                    case '6': {
                        if (i != (rpn_expression.length() - 1)) {
                            string s = "6";
                            for (int j = i; j < rpn_expression.length(); j++) {
                                char b = rpn_expression[j];
                                if (b == ' ') {
                                    i = j + 1;
                                    numbers.push((-1) * string_to_int(s));
                                } else s.push_back(b);
                            }
                        }
                    }
                    case '7': {
                        if (i != (rpn_expression.length() - 1)) {
                            string s = "7";
                            for (int j = i; j < rpn_expression.length(); j++) {
                                char b = rpn_expression[j];
                                if (b == ' ') {
                                    i = j + 1;
                                    numbers.push((-1) * string_to_int(s));
                                } else s.push_back(b);
                            }
                        }
                    }
                    case '8': {
                        if (i != (rpn_expression.length() - 1)) {
                            string s = "8";
                            for (int j = i; j < rpn_expression.length(); j++) {
                                char b = rpn_expression[j];
                                if (b == ' ') {
                                    i = j + 1;
                                    numbers.push((-1) * string_to_int(s));
                                } else s.push_back(b);
                            }
                        }
                    }
                    case '9': {
                        if (i != (rpn_expression.length() - 1)) {
                            string s = "9";
                            for (int j = i; j < rpn_expression.length(); j++) {
                                char b = rpn_expression[j];
                                if (b == ' ') {
                                    i = j + 1;
                                    numbers.push((-1) * string_to_int(s));
                                } else s.push_back(b);
                            }
                        }
                    }
                }

            default:{
                throwError();
                break;
            }
        }
    }


    return 0;
}

int eval_rpn(const string &rpn_expression){
    stack<int> numbers;
    bool isInNumber = false;

    string tmpS = "";

    // first we got to read in all numbers
    // question is: how we are going to do
    // it and how do we know it is a number
    // or a calculation most specifically if we get a '-'

    // if it only contains one int we can catch it here
        if(rpn_expression.length() == 1){
            // only if it is a number
            if (checkIfNumber(rpn_expression[0]))   return string_to_int(rpn_expression);
            else                                    throwError();
        }



    for(int i = 0; i < rpn_expression.length(); i++) {
        char tmpC = rpn_expression[i];
        // if we get a ' ' as character, and we are in a
        // Number we know the number is over, and we can
        // save it to the stack
        if ((tmpC == ' ' && isInNumber)) {
            isInNumber = false;
            numbers.push(string_to_int(tmpS));
            tmpS = "";
        }
            // if we are in a Number AND the char
            // (the one we're currently looking at)
            // is NOT ' ' we can just add the number
            // , but we have to throw Error
            // if it is not a number, because this
            // would be a syntax error of the rpn
        else if (isInNumber) {
            if (checkIfNumber(tmpC)) tmpS += tmpC;
            else{
                // we need to exit here, because
                // the syntax given is wrong
                // wrong Syntax given
                throwError();
                return 0;
            }
        } else if (checkIfNumber(tmpC)) {
            tmpS += tmpC;
            isInNumber = true;
        }else switch(tmpC){
            case '+':{
                if(numbers.size() > 1){
                    int a = numbers.top();
                    numbers.pop();
                    int b = numbers.top();
                    numbers.pop();
                    numbers.push(b + a);
                }else{
                    // wrong Syntax given
                    throwError();
                    return 0;
                }
                break;
            }
            case '-':{
                // when it is the last index of
                // rpn_expression it can not be a negative number
                if(rpn_expression[i + 1] == '\0' || rpn_expression[i + 1] == ' '){
                    if(numbers.size() > 1){
                        int a = numbers.top();
                        numbers.pop();
                        int b = numbers.top();
                        numbers.pop();
                        numbers.push(b - a);
                    }else{
                        // wrong Syntax given
                        throwError();
                        return 0;
                    }
                }else if(checkIfNumber(rpn_expression[i + 1])){
                    // not +=, because it should always be at
                    // the start of a number, or we might encounter some bugs
                    tmpS = "-";
                }else{
                    // wrong Syntax given
                    throwError();
                    return 0;
                }
                // else if(rpn_expression[i+1] == ' ')
                break;
            }
            case '*':{
                if(numbers.size() > 1){
                    int a = numbers.top();
                    numbers.pop();
                    int b = numbers.top();
                    numbers.pop();
                    numbers.push(b * a);
                }else{
                    // wrong Syntax given
                    throwError();
                    return 0;
                }
                break;
            }
            case '/':{
                if(numbers.size() > 1){
                    int a = numbers.top();
                    numbers.pop();
                    int b = numbers.top();
                    numbers.pop();
                    numbers.push(b / a);
                }else{
                    // wrong Syntax given
                    throwError();
                    return 0;
                }
                break;
            }
            // next iteration
            case ' ':{
                break;
            }

            // wrong Syntax given
            default:{
                throwError(); return 0;
            }
        }
    }

    // this check is an edge case, if the last char was an number this will finally add the number
    if (isInNumber && checkIfNumber(rpn_expression[rpn_expression.length() - 1])) {
        numbers.push(string_to_int(tmpS));
    }

    if(numbers.size() > 1){
        throwError();
        return 0;
    }else return numbers.top();

}

/*************** end assignment ***************/

int main() {

  {
    string rpn_expression = "5";
    assert(eval_rpn(rpn_expression) == 5);
  }
  {
    string rpn_expression = "6 7 -";
    assert(eval_rpn(rpn_expression) == -1);
  }
  {
    string rpn_expression = "1 2 +";
    assert(eval_rpn(rpn_expression) == 3);
  }
  {
    string rpn_expression = "6 2 *";
    assert(eval_rpn(rpn_expression) == 12);
  }
  {
    string rpn_expression = "12 2 /";
    assert(eval_rpn(rpn_expression) == 6);
  }
  {
    string rpn_expression = "12 2 /";
    assert(eval_rpn(rpn_expression) == 6);
  }
  {
    string rpn_expression = "3 4 + 2 * 1 +"; // (3 + 4) * 2 + 1
    assert(eval_rpn(rpn_expression) == 15);
  }
  {
    string rpn_expression = "3 2 1 + *"; // (1 + 2) * 3
    assert(eval_rpn(rpn_expression) == 9);
  }
  {
    string rpn_expression =
        "4 2 5 * + 1 3 2 * + /"; // (4 + 2 * 5) / (1 + 3 * 2)
    assert(eval_rpn(rpn_expression) == 2);
  }
  {
    string rpn_expression =
        "2 5 * 4 + 3 2 * 1 + /"; // (2 * 5 + 4 ) / (3 * 2 + 1)
    assert(eval_rpn(rpn_expression) == 2);
  }
  {
    string rpn_expression = "3 5 6 + * 12 4 / -"; // ((5 + 6) * 3) - (12 / 4)
    assert(eval_rpn(rpn_expression) == 30);
  }
  {
    string rpn_expression =
        "100 10 2 -7 * * + 41 +"; // ((2 * (-7)) * 10) + 100 + 41
    assert(eval_rpn(rpn_expression) == 1);
  }
  {
    string rpn_expression = "-12 -56 -";
    assert(eval_rpn(rpn_expression) == 44);
  }
  cout << "all tests passed" << endl;

}