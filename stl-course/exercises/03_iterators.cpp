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
#include <algorithm>
#include <iterator>
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

// Exercise 3.2.1 
// Write a fold expression to sum every element of v. (Hint: use std::accumulate.) where the folding
// expression is a lambda function that takes two arguments and returns their sum.
int sumWithFold(const vector<int>& v) {
    // TODO
    return -1;
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

// Exercise 3.3.1
// Return the LARGEST value in v, found by hand with accumulate and a lambda function. 
int maxWithFold(const vector<int>& v) {
    // TODO
    return -1;
}

// ================================================================
//  GOING FURTHER 🔥  — for when the above felt too easy
// ----------------------------------------------------------------
//  These are still ITERATOR exercises, but they lean on iterators
//  as first-class citizens: reverse iterators, iterator arithmetic,
//  distance, and passing a raw (begin, end) pair around. 💪
// ================================================================

// ----------------------------------------------------------------
//  Exercise 3.4  —  Reverse a vector with REVERSE iterators
// ----------------------------------------------------------------
//  Every container also hands out "backwards bookmarks":
//      v.rbegin()  -> points at the LAST element
//      v.rend()    -> the stop sign, one BEFORE the first element
//  Walking rbegin()..rend() with ++it moves you from back to front.
//
//  Build and return a NEW vector that is v read back-to-front.
//  (Do it with rbegin()/rend() — no manual index juggling.)
//
//      reversedCopy({1, 2, 3, 4})  ->  {4, 3, 2, 1}
//      reversedCopy({7})           ->  {7}
//
//  Hint: the range-constructor  vector<int>(first, last)  will happily
//        copy from a pair of iterators — and rbegin()/rend() ARE a pair.
vector<int> reversedCopy(const vector<int>& v) {
    // TODO: construct a vector from v.rbegin() to v.rend()
    return {};
}

// ----------------------------------------------------------------
//  Exercise 3.5  —  Which SLOT holds the biggest value?
// ----------------------------------------------------------------
//  Sometimes you don't want the max VALUE, you want its POSITION
//  (its 0-based index). Two iterator tools team up here:
//      max_element(begin, end)  -> an ITERATOR to the largest element
//      distance(begin, it)      -> how many steps from begin to it
//  Subtracting those (or calling distance) gives you the index. 🎯
//
//  Return the index of the largest element. If the maximum appears
//  more than once, max_element points at the FIRST one, so return
//  that first index. (Assume v is not empty.)
//
//      indexOfMax({3, 9, 2, 9, 1})  ->  1   (first 9 is at index 1)
//      indexOfMax({5})              ->  0
//      indexOfMax({-5, -2, -8})     ->  1   (-2 is the biggest)
//
//  Hint: auto it = max_element(v.begin(), v.end());
//        return distance(v.begin(), it);
int indexOfMax(const vector<int>& v) {
    // TODO: find max_element, then measure the distance from begin()
    return -1;
}

// ----------------------------------------------------------------
int main() {
    cout << "===== LEARN =====\n";
    learn();

    cout << "\n===== YOUR TURN =====\n";
    check("3.1 firstElement({7,8,9}) == 7",     firstElement({7, 8, 9}) == 7);
    check("3.2 sumWithIterators({1,2,3,4}) == 10", sumWithIterators({1, 2, 3, 4}) == 10);
    check("3.2.1 sumWithFold({1,2,3,4}) == 10", sumWithFold({1, 2, 3, 4}) == 10);
    check("3.3 maxWithIterators({3,9,2,9,1}) == 9", maxWithIterators({3, 9, 2, 9, 1}) == 9);
    check("3.3.1 maxWithFold({3,9,2,9,1}) == 9", maxWithFold({3, 9, 2, 9, 1}) == 9);
    check("3.3 maxWithIterators({-5,-2,-8}) == -2", maxWithIterators({-5, -2, -8}) == -2);

    cout << "\n===== GOING FURTHER =====\n";
    check("3.4 reversedCopy({1,2,3,4}) == {4,3,2,1}",
          reversedCopy({1, 2, 3, 4}) == vector<int>({4, 3, 2, 1}));
    check("3.4 reversedCopy({7}) == {7}",
          reversedCopy({7}) == vector<int>({7}));
    check("3.5 indexOfMax({3,9,2,9,1}) == 1", indexOfMax({3, 9, 2, 9, 1}) == 1);
    check("3.5 indexOfMax({5}) == 0",         indexOfMax({5}) == 0);
    check("3.5 indexOfMax({-5,-2,-8}) == 1",  indexOfMax({-5, -2, -8}) == 1);

    return 0;
}
