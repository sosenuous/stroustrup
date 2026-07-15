// ============================================================
//  Lesson 1 — std::vector : the resizable array   ★ SOLUTION ★
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
// KEY IDEA: count DOWN with the loop; push_back grows the vector as we go.
vector<int> makeCountdown(int n) {
    vector<int> result;
    for (int i = n; i >= 1; --i) {
        result.push_back(i);
    }
    return result;
}

// Exercise 1.2
// Return the sum of all elements in v. (Sum of an empty vector is 0.)
// KEY IDEA: start an accumulator at 0, add each element via a range-for.
int sumVector(const vector<int>& v) {
    int total = 0;
    for (int x : v) {
        total += x;
    }
    return total;
}

// Exercise 1.3
// Return a NEW vector where every element of v has been doubled.
// e.g. {1, 2, 3} -> {2, 4, 6}.  Do not change v itself.
// KEY IDEA: copy first, then mutate the COPY with a reference loop.
vector<int> doubled(const vector<int>& v) {
    vector<int> result = v;
    for (auto& i : result) i *= 2;
    return result;
}

// ================================================================
//  GOING FURTHER 🔥  — for when the warm-up felt too easy
// ================================================================

// ----------------------------------------------------------------
// Exercise 1.4  🔄  rotateLeft
// ----------------------------------------------------------------
// Return a NEW vector equal to v "rotated left" by k positions.
//   rotateLeft({1,2,3,4,5}, 2) -> {3,4,5,1,2}
//
// KEY IDEA: reading starts at index (k % size) and wraps with another
//           modulo, so a big k (or k == size) is handled automatically.
vector<int> rotateLeft(const vector<int>& v, int k) {
    if (v.empty()) return {};                    // empty stays empty
    size_t n = v.size();
    size_t shift = static_cast<size_t>(k) % n;   // tame k >= size and k == 0
    vector<int> result;
    result.reserve(n);
    for (size_t i = 0; i < n; ++i)
        result.push_back(v[(shift + i) % n]);    // wrap-around indexing
    return result;
}

// ----------------------------------------------------------------
// Exercise 1.5  🔀  transpose
// ----------------------------------------------------------------
// Flip a rectangular matrix across its diagonal: element (r, c) -> (c, r).
//   transpose({{1,2,3},{4,5,6}}) -> {{1,4},{2,5},{3,6}}
//
// KEY IDEA: an R-by-C matrix becomes C-by-R; make C rows of length R,
//           then copy each (r,c) into position (c,r).
vector<vector<int>> transpose(const vector<vector<int>>& m) {
    if (m.empty()) return {};                    // no rows in, no rows out
    size_t rows = m.size();
    size_t cols = m[0].size();                   // C from the first row
    vector<vector<int>> result(cols, vector<int>(rows));
    for (size_t r = 0; r < rows; ++r)
        for (size_t c = 0; c < cols; ++c)
            result[c][r] = m[r][c];              // (r,c) moves to (c,r)
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
