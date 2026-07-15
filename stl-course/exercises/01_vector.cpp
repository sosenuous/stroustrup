// ============================================================
//  Lesson 1 — std::vector : the resizable array
// ============================================================
//
//  A plain C++ array has a fixed size you must decide up front:
//      int scores[5];        // exactly 5, forever
//
//  A std::vector is like an array that can GROW and SHRINK while
//  your program runs. It remembers its own size. It is the single
//  most useful STL container — you'll reach for it constantly.
//
//  Key moves:
//      vector<int> v;            // empty vector of ints
//      vector<int> v = {1,2,3};  // start with some values
//      v.push_back(10);          // add 10 to the end
//      v.size();                 // how many elements (an int-ish number)
//      v[0]                      // read/write the first element (index 0)
//      v.empty();                // true if size() == 0
//
//  Loop over every element with a "range-based for":
//      for (int x : v) { ... }         // x is a COPY of each element
//      for (int& x : v) { x = x * 2; }  // the & lets you CHANGE elements
//
// ------------------------------------------------------------

#include <iostream>
#include <vector>
using namespace std;

// A tiny helper that prints PASS if ok is true, otherwise [ ?? ].
void check(const string& name, bool ok) {
    cout << (ok ? "  [PASS] " : "  [ ?? ] ") << name << "\n";
}

// Handy: print a vector like  [1, 2, 3]
void print(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i)
        cout << v[i] << (i + 1 < v.size() ? ", " : "");
    cout << "]";
}

// ----------------------------------------------------------------
//  LEARN  — read this, then run the program to see what it prints
// ----------------------------------------------------------------
void learn() {
    vector<int> scores;          // start empty
    scores.push_back(90);        // add some values
    scores.push_back(75);
    scores.push_back(88);

    cout << "We stored " << scores.size() << " scores: ";
    print(scores);
    cout << "\n";

    cout << "The first score is " << scores[0] << "\n";

    // Give everyone +5 bonus points (note the & so we edit in place):
    for (int& s : scores)
        s += 5;

    cout << "After a +5 bonus: ";
    print(scores);
    cout << "\n";
}

// ----------------------------------------------------------------
//  YOUR TURN — fill in each function where you see  // TODO
// ----------------------------------------------------------------

// Exercise 1.1
// Return a countdown vector: for n = 5 return {5, 4, 3, 2, 1}.
// (If n <= 0, return an empty vector.)
vector<int> makeCountdown(int n) {
    vector<int> result;
    // TODO: push_back n, then n-1, ... down to 1
    for (int i = n; i >= 1; --i) {
        result.push_back(i);
    }

    return result;
}

// Exercise 1.2
// Return the sum of all elements in v. (Sum of an empty vector is 0.)
int sumVector(const vector<int>& v) {
    int total = 0;
    

    for (int x: v) { 
        total += x; 
    }
    return total;
}

// Exercise 1.3
// Return a NEW vector where every element of v has been doubled.
// e.g. {1, 2, 3} -> {2, 4, 6}.  Do not change v itself.
vector<int> doubled(const vector<int>& v) {
    vector<int> result = v;
    for (auto &i : result) i *= 2;
    return result;
}

// ----------------------------------------------------------------
int main() {
    cout << "===== LEARN =====\n";
    learn();

    cout << "\n===== YOUR TURN =====\n";
    check("1.1 makeCountdown(5) == {5,4,3,2,1}",
          makeCountdown(5) == vector<int>({5, 4, 3, 2, 1}));
    check("1.1 makeCountdown(0) is empty",
          makeCountdown(0).empty());
    check("1.2 sumVector({4,5,6}) == 15",
          sumVector({4, 5, 6}) == 15);
    check("1.2 sumVector({}) == 0",
          sumVector({}) == 0);
    check("1.3 doubled({1,2,3}) == {2,4,6}",
          doubled({1, 2, 3}) == vector<int>({2, 4, 6}));
    return 0;
}
