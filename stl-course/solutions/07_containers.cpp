// ============================================================
//  Lesson 7 — std::array, std::stack, std::queue  ★ SOLUTION ★
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
#include <vector>
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
    // Key idea: range-based for iterates a std::array just like a vector.
    for (int x : a) total += x;
    return total;
}

// Exercise 7.2
// Reverse a string USING A STACK.
// Push every character on, then pop them off — they come back reversed.
// reverseWithStack("abc") -> "cba".
string reverseWithStack(const string& s) {
    stack<char> st;
    // Key idea: a stack is LIFO, so popping yields characters in reverse.
    for (char c : s) st.push(c);
    string result = "";
    while (!st.empty()) { result += st.top(); st.pop(); }
    return result;
}

// Exercise 7.3
// You have a queue of people's names in line. Serve them all and return
// the order they were served (which, for a queue, is the order they arrived).
// Given pushes A, B, C -> returns "A,B,C".
// The queue is passed BY VALUE so you're free to drain it.
string serveLine(queue<string> line) {
    string result = "";
    // Key idea: a queue is FIFO, so draining the front preserves arrival order.
    while (!line.empty()) {
        if (!result.empty()) result += ",";
        result += line.front();
        line.pop();
    }
    return result;
}

// ================================================================
//  GOING FURTHER 🔥
// ================================================================
//  Time to use these containers for the jobs they were born to do.
//  A stack isn't just for reversing strings — it's the secret weapon
//  behind calculators and code that has to remember "what came before".
// ----------------------------------------------------------------

// Exercise 7.4
// ┌──────────────────────────────────────────────────────────────┐
// │  Evaluate a Reverse Polish Notation (RPN) expression          │
// └──────────────────────────────────────────────────────────────┘
// In RPN, the operator comes AFTER its two operands, so there are no
// brackets and no precedence rules to worry about — perfect for a stack!
//
// Walk through the tokens left to right:
//   - if the token is a number, push it onto the stack
//   - if it's an operator (+ - * /), pop TWO numbers, apply the
//     operator, and push the result back
// At the end, the single number left on the stack is the answer.
//
// IMPORTANT: order matters for - and /. The first number popped is the
// RIGHT operand, the second popped is the LEFT operand:
//     left OP right     (e.g. for "-":  second_pop - first_pop)
//
// Use INTEGER arithmetic (so 13 / 5 == 2).
//
// Examples:
//   {"2","3","+"}                 -> 5        (2 + 3)
//   {"2","1","+","3","*"}         -> 9        ((2 + 1) * 3)
//   {"4","13","5","/","+"}        -> 6        (4 + (13 / 5) = 4 + 2)
//
// Hint 💡: to turn a numeric token string into an int, use stoi(token).
//          To test the operator, compare token == "+", etc.
int evalRPN(const vector<string>& tokens) {
    stack<int> st;
    // Key idea: the stack holds pending operands; an operator folds the top two.
    for (const string& token : tokens) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int right = st.top(); st.pop();   // first popped is the RIGHT operand
            int left  = st.top(); st.pop();   // second popped is the LEFT operand
            if      (token == "+") st.push(left + right);
            else if (token == "-") st.push(left - right);
            else if (token == "*") st.push(left * right);
            else                   st.push(left / right);
        } else {
            st.push(stoi(token));
        }
    }
    return st.top();
}

// Exercise 7.5
// ┌──────────────────────────────────────────────────────────────┐
// │  Reverse the first k elements of a queue                      │
// └──────────────────────────────────────────────────────────────┘
// A queue only lets you touch the FRONT — so how do you flip the order
// of its first few elements? Borrow a stack! 🥞
//
// Plan:
//   1. Pop the first k elements off the queue and PUSH them on a stack.
//   2. Pop them back OFF the stack (now reversed!) and push them onto
//      the queue — this appends them to the BACK.
//   3. The remaining (size - k) elements are still at the front; rotate
//      them to the back by popping the front and re-pushing it, once for
//      each of the remaining elements. Now everything is in order again.
//
// The queue is passed BY VALUE, so mutate it freely and return it.
//
// Example (shown front -> back):
//   [1,2,3,4,5], k = 3   ->   [3,2,1,4,5]
//   [10,20,30],  k = 2   ->   [20,10,30]
//
// Hint 💡: after step 2 the queue looks like [4,5,3,2,1]; step 3 rotates
//          the leftover 4 and 5 (size - k = 2 of them) to the back.
queue<int> reverseFirstK(queue<int> q, int k) {
    // Key idea: a stack reverses the first k; a rotation restores the tail's order.
    stack<int> st;
    for (int i = 0; i < k; ++i) { st.push(q.front()); q.pop(); }
    while (!st.empty()) { q.push(st.top()); st.pop(); }
    int remaining = static_cast<int>(q.size()) - k;
    for (int i = 0; i < remaining; ++i) { q.push(q.front()); q.pop(); }
    return q;
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

    cout << "\n===== GOING FURTHER =====\n";
    check("7.4 evalRPN({2,3,+}) == 5",
          evalRPN({"2", "3", "+"}) == 5);
    check("7.4 evalRPN({2,1,+,3,*}) == 9",
          evalRPN({"2", "1", "+", "3", "*"}) == 9);
    check("7.4 evalRPN({4,13,5,/,+}) == 6",
          evalRPN({"4", "13", "5", "/", "+"}) == 6);
    check("7.4 evalRPN({10,3,-}) == 7",
          evalRPN({"10", "3", "-"}) == 7);

    // Small helper: flatten a queue to "a,b,c" so we can eyeball the order.
    auto qToStr = [](queue<int> q) {
        string s = "";
        while (!q.empty()) {
            if (!s.empty()) s += ",";
            s += to_string(q.front());
            q.pop();
        }
        return s;
    };

    queue<int> q1;
    q1.push(1); q1.push(2); q1.push(3); q1.push(4); q1.push(5);
    check("7.5 reverseFirstK([1,2,3,4,5], 3) == [3,2,1,4,5]",
          qToStr(reverseFirstK(q1, 3)) == "3,2,1,4,5");

    queue<int> q2;
    q2.push(10); q2.push(20); q2.push(30);
    check("7.5 reverseFirstK([10,20,30], 2) == [20,10,30]",
          qToStr(reverseFirstK(q2, 2)) == "20,10,30");

    return 0;
}
