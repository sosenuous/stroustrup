// ============================================================
//  Lesson 7 — std::array, std::stack, std::queue   *** SOLUTION ***
// ============================================================
#include <iostream>
#include <string>
#include <array>
#include <stack>
#include <queue>
using namespace std;

void check(const string& name, bool ok) {
    cout << (ok ? "  [PASS] " : "  [ ?? ] ") << name << "\n";
}

void learn() {
    array<int, 3> rgb = {255, 128, 0};
    cout << "array size is always " << rgb.size() << ", first = " << rgb[0] << "\n";

    stack<int> st;
    st.push(1); st.push(2); st.push(3);
    cout << "Stack top (last in) is " << st.top() << "\n";
    st.pop();
    cout << "After one pop, top is " << st.top() << "\n";

    queue<int> q;
    q.push(1); q.push(2); q.push(3);
    cout << "Queue front (first in) is " << q.front() << "\n";
    q.pop();
    cout << "After one pop, front is " << q.front() << "\n";
}

// Exercise 7.1
int sumArray(const array<int, 5>& a) {
    int total = 0;
    for (int x : a)
        total += x;
    return total;
}

// Exercise 7.2
string reverseWithStack(const string& s) {
    stack<char> st;
    for (char c : s)
        st.push(c);
    string result = "";
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    return result;
}

// Exercise 7.3
string serveLine(queue<string> line) {
    string result = "";
    while (!line.empty()) {
        if (!result.empty())
            result += ",";
        result += line.front();
        line.pop();
    }
    return result;
}

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
