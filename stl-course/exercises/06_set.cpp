// ============================================================
//  Lesson 6 — std::set : a bag of unique, sorted things
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
    // TODO: insert every element of v into `seen`, then return seen.size()
    return 0;
}

// Exercise 6.2
// Return true if v contains any duplicate value.
// Hint: as you insert, if a value is already in the set, it's a duplicate.
//       You can compare seen.size() to how many you've inserted, OR use
//       the fact that insert(...).second is false when it was already there.
bool hasDuplicate(const vector<int>& v) {
    set<int> seen;
    // TODO: walk v; if you ever see a value already in `seen`, return true
    return false;
}

// Exercise 6.3
// Return a sorted vector of the unique values in v.
// dedupeSorted({3,1,2,3,1}) -> {1,2,3}.
// Hint: a set is already unique AND sorted — copy it into a vector.
vector<int> dedupeSorted(const vector<int>& v) {
    set<int> s;
    // TODO: insert all of v into s
    vector<int> result;
    // TODO: copy each value from s into result (a range-based for works)
    return result;
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
    return 0;
}
