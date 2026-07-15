// ============================================================
//  Lesson 8 — Lambdas : tiny functions you write inline
// ============================================================
//
//  Sometimes you want to give an algorithm a little rule, like
//  "count the EVEN numbers" or "sort by string length". Writing a
//  whole named function for that is overkill. A lambda is a function
//  you write right where you need it.
//
//  Shape of a lambda:
//      [ ]  ( parameters )  { body; return ...; }
//       ^        ^                ^
//    capture   inputs          what it does
//
//  Examples:
//      auto isEven = [](int x) { return x % 2 == 0; };
//      isEven(4);   // true
//
//  Used with algorithms:
//      count_if(v.begin(), v.end(), [](int x){ return x > 0; });
//      sort(v.begin(), v.end(), [](int a, int b){ return a > b; }); // descending
//
//  The [ ] can CAPTURE variables from around it, so the lambda can
//  use them:
//      int limit = 10;
//      auto isBig = [limit](int x) { return x > limit; };  // uses `limit`
//
//  count_if lives in <algorithm>.
//
// ------------------------------------------------------------

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void check(const string& name, bool ok) {
    cout << (ok ? "  [PASS] " : "  [ ?? ] ") << name << "\n";
}

// ----------------------------------------------------------------
//  LEARN
// ----------------------------------------------------------------
void learn() {
    vector<int> v = {4, 7, 1, 9, 2, 8};

    auto isEven = [](int x) { return x % 2 == 0; };
    cout << "isEven(4) = " << isEven(4) << ", isEven(7) = " << isEven(7) << "\n";

    int evens = count_if(v.begin(), v.end(), isEven);
    cout << "There are " << evens << " even numbers.\n";

    // Sort descending using a lambda comparator:
    sort(v.begin(), v.end(), [](int a, int b) { return a > b; });
    cout << "Descending: ";
    for (int x : v) cout << x << " ";
    cout << "\n";

    // A capturing lambda: count how many are above a threshold.
    int threshold = 5;
    int big = count_if(v.begin(), v.end(),
                       [threshold](int x) { return x > threshold; });
    cout << big << " numbers are greater than " << threshold << "\n";
}

// ----------------------------------------------------------------
//  YOUR TURN — use lambdas with the algorithms
// ----------------------------------------------------------------

// Exercise 8.1
// Return how many numbers in v are even, using count_if + a lambda.
int countEven(const vector<int>& v) {
    // TODO: return count_if(v.begin(), v.end(), [](int x){ return ...; });
    return -1;
}

// Exercise 8.2
// Sort the words by LENGTH, shortest first, and return the result.
// {"bbb","a","cc"} -> {"a","cc","bbb"}.
// Hint: sort with a lambda comparator that compares a.length() < b.length().
vector<string> sortByLength(vector<string> words) {
    // TODO: sort(words.begin(), words.end(),
    //            [](const string& a, const string& b){ return ...; });
    return words;
}

// Exercise 8.3
// Return how many numbers in v are strictly greater than `threshold`,
// using count_if and a lambda that CAPTURES threshold.
int countAbove(const vector<int>& v, int threshold) {
    // TODO: capture threshold in the [ ] and compare x > threshold
    return -1;
}

// ----------------------------------------------------------------
int main() {
    cout << "===== LEARN =====\n";
    learn();

    cout << "\n===== YOUR TURN =====\n";
    check("8.1 countEven({1,2,3,4,5,6}) == 3", countEven({1, 2, 3, 4, 5, 6}) == 3);
    check("8.1 countEven({1,3,5}) == 0",       countEven({1, 3, 5}) == 0);
    check("8.2 sortByLength == {a,cc,bbb}",
          sortByLength({"bbb", "a", "cc"}) == vector<string>({"a", "cc", "bbb"}));
    check("8.3 countAbove({1,5,10,15}, 5) == 2", countAbove({1, 5, 10, 15}, 5) == 2);
    check("8.3 countAbove({1,2,3}, 100) == 0",   countAbove({1, 2, 3}, 100) == 0);
    return 0;
}
