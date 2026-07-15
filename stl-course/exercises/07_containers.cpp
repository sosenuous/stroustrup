// ============================================================
//  Lesson 7 — std::array, std::stack, std::queue
// ============================================================
//
//  Three more containers, each with a personality.
//
//  std::array<T, N>  — a fixed-size array that knows its own size.
//      array<int, 3> a = {10, 20, 30};
//      a[0];  a.size();      // like vector, but size N is fixed forever
//
//  std::stack<T>  — Last In, First Out (LIFO). Like a stack of plates:
//      you can only touch the top one.
//      stack<int> st;
//      st.push(1); st.push(2);   // top is now 2
//      st.top();                 // peek at the top -> 2
//      st.pop();                 // remove the top (returns nothing!)
//      st.empty();  st.size();
//
//  std::queue<T> — First In, First Out (FIFO). Like a line at a shop:
//      first to arrive is first to leave.
//      queue<int> q;
//      q.push(1); q.push(2);     // front is 1, back is 2
//      q.front();                // peek at the front -> 1
//      q.pop();                  // remove the front
//
//  NOTE: stack/queue pop() does NOT return the value — read it with
//  top()/front() FIRST, then pop().
//
// ------------------------------------------------------------

#include <iostream>
#include <string>
#include <array>
#include <stack>
#include <queue>
using namespace std;

void check(const string& name, bool ok) {
    cout << (ok ? "  [PASS] " : "  [ ?? ] ") << name << "\n";
}

// ----------------------------------------------------------------
//  LEARN
// ----------------------------------------------------------------
void learn() {
    array<int, 3> rgb = {255, 128, 0};
    cout << "array size is always " << rgb.size() << ", first = " << rgb[0] << "\n";

    stack<int> st;
    st.push(1); st.push(2); st.push(3);
    cout << "Stack top (last in) is " << st.top() << "\n";   // 3
    st.pop();
    cout << "After one pop, top is " << st.top() << "\n";    // 2

    queue<int> q;
    q.push(1); q.push(2); q.push(3);
    cout << "Queue front (first in) is " << q.front() << "\n"; // 1
    q.pop();
    cout << "After one pop, front is " << q.front() << "\n";   // 2
}

// ----------------------------------------------------------------
//  YOUR TURN
// ----------------------------------------------------------------

// Exercise 7.1
// Return the sum of a fixed 5-element array.
int sumArray(const array<int, 5>& a) {
    int total = 0;
    // TODO: loop over a (range-based for works on array too) and add each up
    return total;
}

// Exercise 7.2
// Reverse a string USING A STACK.
// Push every character on, then pop them off — they come back reversed.
// reverseWithStack("abc") -> "cba".
string reverseWithStack(const string& s) {
    stack<char> st;
    // TODO: push each char of s onto st
    string result = "";
    // TODO: while st is not empty: append st.top() to result, then st.pop()
    return result;
}

// Exercise 7.3
// You have a queue of people's names in line. Serve them all and return
// the order they were served (which, for a queue, is the order they arrived).
// Given pushes A, B, C -> returns "A,B,C".
// The queue is passed BY VALUE so you're free to drain it.
string serveLine(queue<string> line) {
    string result = "";
    // TODO: while line is not empty:
    //         - if result isn't empty, append a comma ","
    //         - append line.front()
    //         - line.pop()
    return result;
}

// ----------------------------------------------------------------
int main() {
    cout << "===== LEARN =====\n";
    learn();

    cout << "\n===== YOUR TURN =====\n";
    check("7.1 sumArray({1,2,3,4,5}) == 15",
          sumArray(array<int, 5>{1, 2, 3, 4, 5}) == 15);
    check("7.2 reverseWithStack(\"abc\") == \"cba\"",
          reverseWithStack("abc") == "cba");
    check("7.2 reverseWithStack(\"stack\") == \"kcats\"",
          reverseWithStack("stack") == "kcats");

    queue<string> line;
    line.push("A"); line.push("B"); line.push("C");
    check("7.3 serveLine(A,B,C) == \"A,B,C\"", serveLine(line) == "A,B,C");
    return 0;
}
