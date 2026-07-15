// ============================================================
//  Lesson 3 — Iterators : how the STL "points" into a container
// ============================================================
//
//  The range-based for  ( for (int x : v) )  is lovely, but it hides
//  something. Underneath, the STL walks a container using ITERATORS.
//
//  An iterator is like a bookmark pointing at one element.
//      v.begin()   -> iterator to the FIRST element
//      v.end()     -> iterator to ONE PAST the last element (a stop sign)
//      *it         -> the element the bookmark points at (dereference)
//      ++it        -> move the bookmark to the next element
//
//  The classic iterator loop:
//      for (auto it = v.begin(); it != v.end(); ++it)
//          cout << *it;
//
//  `auto` just means "compiler, figure out the type for me" — handy,
//  because the real type name (vector<int>::iterator) is a mouthful.
//
//  Why care? Because ALL the STL algorithms in the next lesson speak
//  "iterator". Understanding begin()/end() unlocks the whole library.
//
// ------------------------------------------------------------

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void check(const string& name, bool ok) {
    cout << (ok ? "  [PASS] " : "  [ ?? ] ") << name << "\n";
}

// ----------------------------------------------------------------
//  LEARN
// ----------------------------------------------------------------
void learn() {
    vector<int> v = {10, 20, 30};

    // The element the first bookmark points at:
    cout << "First element via *v.begin(): " << *v.begin() << "\n";

    // Walk the whole vector with an explicit iterator loop:
    cout << "All elements: ";
    for (auto it = v.begin(); it != v.end(); ++it)
        cout << *it << " ";
    cout << "\n";

    // Iterators can edit too — add 1 to each element:
    for (auto it = v.begin(); it != v.end(); ++it)
        *it += 1;
    cout << "After +1 each: ";
    for (int x : v) cout << x << " ";
    cout << "\n";
}

// ----------------------------------------------------------------
//  YOUR TURN — use iterators (begin/end/*it/++it), not v[i] indexing
// ----------------------------------------------------------------

// Exercise 3.1
// Return the first element of v using *v.begin().
// (You may assume v is not empty.)
int firstElement(const vector<int>& v) {
    // TODO: return the element the begin() iterator points at
    return *v.begin();
}

// Exercise 3.2
// Sum every element using an iterator loop (auto it = v.begin(); ...).
int sumWithIterators(const vector<int>& v) {
    int total = 0;
    for (auto it = v.begin(); it != v.end(); ++it) {
    }
    return total;
}

// Exercise 3.3
// Return the LARGEST value in v, found by hand with an iterator loop.
// (You may assume v is not empty. Don't use library functions yet —
//  that's next lesson! Do it manually here.)
int maxWithIterators(const vector<int>& v) {
    int best = *v.begin();   
    for (auto it =v.begin(); it != v.end(); ++it )
        if (*it > best) { 
            best = *it;
        }
    return best;
}

// ----------------------------------------------------------------
int main() {
    cout << "===== LEARN =====\n";
    learn();

    cout << "\n===== YOUR TURN =====\n";
    check("3.1 firstElement({7,8,9}) == 7",     firstElement({7, 8, 9}) == 7);
    check("3.2 sumWithIterators({1,2,3,4}) == 10", sumWithIterators({1, 2, 3, 4}) == 10);
    check("3.3 maxWithIterators({3,9,2,9,1}) == 9", maxWithIterators({3, 9, 2, 9, 1}) == 9);
    check("3.3 maxWithIterators({-5,-2,-8}) == -2", maxWithIterators({-5, -2, -8}) == -2);
    return 0;
}
