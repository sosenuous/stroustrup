// ============================================================
//  Lesson 6 — std::set : a bag of unique, sorted things  ★ SOLUTION ★
// ============================================================
//
//  A std::set stores values with two special rules:
//    1. No duplicates — insert the same value twice, it's stored once.
//    2. Always sorted — iterating gives you the values in order.
//
//      set<int> s;
//      s.insert(5);
//      s.insert(5);      // ignored, 5 is already there
//      s.insert(2);
//      s.size();         // 2   (just 5 and 2)
//      s.count(5);       // 1 if present, 0 if not
//      s.contains(5);    // (C++20) true / false
//
//  Great for questions like "how many DIFFERENT items?" or
//  "have I seen this before?".
//
//  Loop just like the others (values come out sorted):
//      for (int x : s) cout << x << " ";
//
// ------------------------------------------------------------

#include <iostream>
#include <string>
#include <set>
#include <vector>
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
    set<int> s;
    for (int x : {5, 2, 5, 9, 2, 5})
        s.insert(x);

    cout << "Inserted 6 numbers, kept " << s.size() << " unique ones: ";
    for (int x : s) cout << x << " ";     // prints in sorted order: 2 5 9
    cout << "\n";

    cout << "Have we seen 9? " << (s.count(9) ? "yes" : "no") << "\n";
    cout << "Have we seen 3? " << (s.count(3) ? "yes" : "no") << "\n";
}

// ----------------------------------------------------------------
//  YOUR TURN
// ----------------------------------------------------------------

// Exercise 6.1
// Return how many DIFFERENT values are in v.
// countUnique({1,2,2,3,3,3}) -> 3.
int countUnique(const vector<int>& v) {
    set<int> seen;
    // Key idea: a set silently drops duplicates, so its size is the unique count.
    for (int x : v) seen.insert(x);
    return static_cast<int>(seen.size());
}

// Exercise 6.2
// Return true if v contains any duplicate value.
// Hint: as you insert, if a value is already in the set, it's a duplicate.
//       You can compare seen.size() to how many you've inserted, OR use
//       the fact that insert(...).second is false when it was already there.
bool hasDuplicate(const vector<int>& v) {
    set<int> seen;
    // Key idea: insert(...).second is false when the value was already present.
    for (int x : v)
        if (!seen.insert(x).second) return true;
    return false;
}

// Exercise 6.3
// Return a sorted vector of the unique values in v.
// dedupeSorted({3,1,2,3,1}) -> {1,2,3}.
// Hint: a set is already unique AND sorted — copy it into a vector.
vector<int> dedupeSorted(const vector<int>& v) {
    set<int> s;
    // Key idea: the set makes values unique + sorted; then copy them straight out.
    for (int x : v) s.insert(x);
    vector<int> result;
    for (int x : s) result.push_back(x);
    return result;
}

// ================================================================
//  GOING FURTHER 🔥
// ----------------------------------------------------------------
//  Two sets, side by side, unlock a whole family of "set operations":
//    intersection (in BOTH), difference (in one but not the other),
//    and the subset test (is everything in A also in B?).
//
//  The STL ships these as algorithms in <algorithm>:
//      set_intersection, set_difference, includes, ...
//  They all share one golden rule: 🔑 the INPUT ranges must be SORTED.
//  Lucky us — a std::set always iterates in sorted order, so a set's
//  begin()/end() satisfies that requirement for free.
//
//  The "output" algorithms write results one-by-one; hand them a
//  back_inserter(v) so each result gets push_back'd onto your vector:
//      set_intersection(a.begin(), a.end(),
//                       b.begin(), b.end(),
//                       back_inserter(out));
// ================================================================

// Exercise 6.4
// Return the INTERSECTION of a and b — the values present in BOTH —
// as a sorted vector<int>.
// intersect({1,2,3,4}, {3,4,5,6}) -> {3,4}
// intersect({1,2},    {3,4})      -> {}    (nothing in common)
// Hint: std::set_intersection with back_inserter(result). Because a and b
//       are std::set, their begin()/end() are already sorted — perfect input.
vector<int> intersect(const set<int>& a, const set<int>& b) {
    vector<int> result;
    // Key idea: set_intersection over two sorted ranges, collected via back_inserter.
    set_intersection(a.begin(), a.end(), b.begin(), b.end(),
                     back_inserter(result));
    return result;
}

// Exercise 6.5
// Return true if EVERY element of small is also in big
// (i.e. small is a subset of big). The empty set is a subset of anything.
// isSubset({2,3}, {1,2,3,4}) -> true
// isSubset({2,5}, {1,2,3,4}) -> false   (5 is missing from big)
// isSubset({},    {1,2,3})   -> true
// Hint: std::includes(big..., small...) returns true when the SECOND range
//       is fully contained in the FIRST. Mind the argument order: big first!
//       Both come from std::set, so both ranges are already sorted.
bool isSubset(const set<int>& small, const set<int>& big) {
    // Key idea: includes(big, small) is true iff small is fully contained in big.
    return includes(big.begin(), big.end(), small.begin(), small.end());
}

// ----------------------------------------------------------------
int main() {
    cout << "===== LEARN =====\n";
    learn();

    cout << "\n===== YOUR TURN =====\n";
    check("6.1 countUnique({1,2,2,3,3,3}) == 3", countUnique({1, 2, 2, 3, 3, 3}) == 3);
    check("6.1 countUnique({}) == 0",            countUnique({}) == 0);
    check("6.2 hasDuplicate({1,2,3}) == false",  hasDuplicate({1, 2, 3}) == false);
    check("6.2 hasDuplicate({1,2,1}) == true",   hasDuplicate({1, 2, 1}) == true);
    check("6.3 dedupeSorted({3,1,2,3,1}) == {1,2,3}",
          dedupeSorted({3, 1, 2, 3, 1}) == vector<int>({1, 2, 3}));

    cout << "\n===== GOING FURTHER =====\n";
    check("6.4 intersect({1,2,3,4},{3,4,5,6}) == {3,4}",
          intersect({1, 2, 3, 4}, {3, 4, 5, 6}) == vector<int>({3, 4}));
    check("6.4 intersect({1,2},{3,4}) == {}",
          intersect({1, 2}, {3, 4}) == vector<int>({}));
    check("6.5 isSubset({2,3},{1,2,3,4}) == true",
          isSubset({2, 3}, {1, 2, 3, 4}) == true);
    check("6.5 isSubset({2,5},{1,2,3,4}) == false",
          isSubset({2, 5}, {1, 2, 3, 4}) == false);
    check("6.5 isSubset({},{1,2,3}) == true",
          isSubset({}, {1, 2, 3}) == true);
    return 0;
}
