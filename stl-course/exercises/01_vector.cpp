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

// ================================================================
//  GOING FURTHER 🔥  — for when the warm-up felt too easy
// ================================================================
//  These two go past push_back / indexing. Take your time, sketch
//  the data on paper first, and mind the edge cases. 💪

// ----------------------------------------------------------------
// Exercise 1.4  🔄  rotateLeft
// ----------------------------------------------------------------
// Return a NEW vector equal to v "rotated left" by k positions:
// each element slides k slots toward the front, and whatever falls
// off the front wraps around to the back.
//
//   rotateLeft({1,2,3,4,5}, 2) -> {3,4,5,1,2}
//   rotateLeft({10,20,30},  1) -> {20,30,10}
//
// Watch out: k can be 0, and k can be LARGER than v.size()
// (rotating by size() lands you right back where you started, so
//  a rotation by k really only depends on k % size()).
// An empty vector stays empty.
//
// Hint: the element that ends up at the front is the one currently
//       at index (k % size()). The modulo tames a big k for you. 🙂
vector<int> rotateLeft(const vector<int>& v, int k) {
    // TODO: build the rotated vector. Remember to use k % v.size()
    //       (but only when v is non-empty!).
    (void)v; (void)k;
    return {};  // placeholder: NOT rotated yet
}

// ----------------------------------------------------------------
// Exercise 1.5  🔀  transpose
// ----------------------------------------------------------------
// A matrix here is a vector of rows, each row a vector<int>, and
// every row has the SAME length. The "transpose" flips it across
// its diagonal: rows become columns and columns become rows.
//
//   transpose({{1,2,3},         {{1,4},
//              {4,5,6}})    ->    {2,5},
//                                 {3,6}}
//
// So an R-by-C matrix becomes a C-by-R matrix, and the element at
// (row r, col c) moves to (row c, col r).
//
//   transpose({{7}})           -> {{7}}
//   transpose({})              -> {}   (no rows in, no rows out)
//
// Hint: figure out C (the number of columns) from the first row,
//       then create C new rows and fill them column by column. ✍️
vector<vector<int>> transpose(const vector<vector<int>>& m) {
    // TODO: return the transposed matrix.
    (void)m;
    return {};  // placeholder: NOT transposed yet
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

    cout << "\n===== GOING FURTHER =====\n";
    check("1.4 rotateLeft({1,2,3,4,5},2) == {3,4,5,1,2}",
          rotateLeft({1, 2, 3, 4, 5}, 2) == vector<int>({3, 4, 5, 1, 2}));
    check("1.4 rotateLeft({10,20,30},1) == {20,30,10}",
          rotateLeft({10, 20, 30}, 1) == vector<int>({20, 30, 10}));
    check("1.4 rotateLeft({1,2,3},0) == {1,2,3}",
          rotateLeft({1, 2, 3}, 0) == vector<int>({1, 2, 3}));
    check("1.4 rotateLeft({1,2,3,4},6) == {3,4,1,2}  (k > size)",
          rotateLeft({1, 2, 3, 4}, 6) == vector<int>({3, 4, 1, 2}));
    check("1.5 transpose({{1,2,3},{4,5,6}}) == {{1,4},{2,5},{3,6}}",
          transpose({{1, 2, 3}, {4, 5, 6}}) ==
              vector<vector<int>>({{1, 4}, {2, 5}, {3, 6}}));
    check("1.5 transpose({{7}}) == {{7}}",
          transpose({{7}}) == vector<vector<int>>({{7}}));
    return 0;
}
