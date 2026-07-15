// ============================================================
//  Lesson 12 — STL TO THE LIMITS : let the library do the work ⚙️
// ============================================================
//
//  By now you can solve most things with a hand-written loop. This lesson
//  is about NOT doing that — reaching for the sharpest tools in <algorithm>
//  and <numeric> so a whole loop collapses into one expressive line.
//  These are the moves that separate "I can write C++" from "I know the
//  STL".
//
//  The toolbox for today:
//
//    transform  — map each element through a function into a new range
//        transform(v.begin(), v.end(), out.begin(), [](int x){ return x*x; });
//
//    accumulate — fold a range down to one value (from <numeric>)
//        accumulate(v.begin(), v.end(), 0);                 // sum
//        accumulate(v.begin(), v.end(), 1, multiplies<>{}); // product
//        accumulate(v.begin(), v.end(), 0, [](int acc, int x){ ... }); // custom
//
//    the ERASE-REMOVE idiom — actually delete elements by value/predicate
//        v.erase(remove(v.begin(), v.end(), 7), v.end());          // all 7s
//        v.erase(remove_if(v.begin(), v.end(), pred), v.end());    // by rule
//      (remove() only shuffles the keepers to the front and returns the new
//       logical end; erase() does the real trimming. You need BOTH.)
//
//    sort + unique + erase — dedupe in place
//        sort(v.begin(), v.end());
//        v.erase(unique(v.begin(), v.end()), v.end());
//
//    binary search on SORTED data (from <algorithm>)
//        lower_bound(b, e, x) — first position where x could go (>= x)
//        upper_bound(b, e, x) — first position AFTER x        (>  x)
//        so upper_bound(..hi) - lower_bound(..lo) counts items in [lo, hi].
//
//    nth_element / partial_sort — get the k smallest/largest without a
//    full sort (cheaper than sorting the whole thing).
//
//    priority_queue<int> (from <queue>) — a heap; top() is the largest.
//
// ------------------------------------------------------------

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <functional>
using namespace std;

void check(const string& name, bool ok) {
    cout << (ok ? "  [PASS] " : "  [ ?? ] ") << name << "\n";
}

// ----------------------------------------------------------------
//  LEARN
// ----------------------------------------------------------------
void learn() {
    vector<int> v = {5, 2, 8, 2, 9, 1, 5};

    // transform into a new vector of squares.
    vector<int> sq(v.size());
    transform(v.begin(), v.end(), sq.begin(), [](int x) { return x * x; });
    cout << "squares: ";
    for (int x : sq) cout << x << " ";
    cout << "\n";

    // accumulate: sum and product in one line each.
    int sum = accumulate(v.begin(), v.end(), 0);
    long prod = accumulate(v.begin(), v.end(), 1L, multiplies<long>{});
    cout << "sum = " << sum << ", product = " << prod << "\n";

    // erase-remove: delete every 2.
    vector<int> w = v;
    w.erase(remove(w.begin(), w.end(), 2), w.end());
    cout << "after removing 2s: ";
    for (int x : w) cout << x << " ";
    cout << "\n";

    // sort + unique + erase: sorted, de-duplicated.
    vector<int> u = v;
    sort(u.begin(), u.end());
    u.erase(unique(u.begin(), u.end()), u.end());
    cout << "sorted unique: ";
    for (int x : u) cout << x << " ";
    cout << "\n";

    // binary search count: how many are in [2, 8] once sorted?
    int inRange = upper_bound(u.begin(), u.end(), 8) - lower_bound(u.begin(), u.end(), 2);
    cout << "values in [2,8] = " << inRange << "\n";
}

// ----------------------------------------------------------------
//  YOUR TURN — one line where you'd have written a loop
// ----------------------------------------------------------------

// Exercise 12.1 — Sum of squares (a fold)
// Return v[0]^2 + v[1]^2 + ... using std::accumulate with a lambda that
// squares each element as it folds. NO explicit loop.
//   sumOfSquares({1,2,3}) == 14
//   sumOfSquares({})      == 0
// Hint: accumulate(begin, end, 0, [](int acc, int x){ return acc + x*x; });
int sumOfSquares(const vector<int>& v) {
    // TODO
    return -1;
}

// Exercise 12.2 — Remove every occurrence (erase-remove idiom)
// Return v with every element equal to `value` deleted, order otherwise
// preserved.
//   removeAll({1,2,1,3,1}, 1) == {2,3}
//   removeAll({4,4,4}, 4)     == {}
// Hint: v.erase(remove(v.begin(), v.end(), value), v.end());  then return v.
vector<int> removeAll(vector<int> v, int value) {
    // TODO
    return v;
}

// Exercise 12.3 — Sorted + de-duplicated
// Return the DISTINCT values of v, in ascending order.
//   dedupeSorted({3,1,2,3,1}) == {1,2,3}
//   dedupeSorted({})          == {}
// Hint: sort, then the unique+erase idiom. (unique only removes ADJACENT
//       duplicates — that's why you must sort first.)
vector<int> dedupeSorted(vector<int> v) {
    // TODO
    return v;
}

// Exercise 12.4 — Count values in a range (binary search)
// v is ALREADY SORTED ascending. Return how many elements satisfy
// lo <= x <= hi. Do it in O(log n) with lower_bound / upper_bound —
// no scanning the whole vector.
//   countInRange({1,2,4,4,5,7}, 2, 4) == 3     // 2,4,4
//   countInRange({1,2,4,4,5,7}, 6, 9) == 1     // 7
//   countInRange({1,2,4,4,5,7}, 8, 9) == 0
// Hint: upper_bound(..,hi) - lower_bound(..,lo).
int countInRange(const vector<int>& v, int lo, int hi) {
    // TODO
    return -1;
}

// Exercise 12.5 — k-th smallest (without fully sorting)
// Return the k-th smallest value (1-indexed) using std::nth_element on a
// COPY. nth_element puts the element that WOULD be at that index if sorted
// into that position, cheaply.
//   kthSmallest({7,2,5,1,9}, 1) == 1
//   kthSmallest({7,2,5,1,9}, 2) == 2
//   kthSmallest({7,2,5,1,9}, 5) == 9
// Hint: nth_element(v.begin(), v.begin() + (k-1), v.end()); return v[k-1];
int kthSmallest(vector<int> v, int k) {
    // TODO
    return -1;
}

// Exercise 12.6 — The three largest, biggest first
// Return the 3 largest values in descending order. If there are fewer than
// 3 elements, return them all (still descending).
//   topThree({4,1,7,3,9,2}) == {9,7,4}
//   topThree({5,5,5,5})     == {5,5,5}
//   topThree({8,1})         == {8,1}
// Hint: one way — sort descending and take the first min(3, size()).
//       A slicker way — partial_sort only the top 3, or a priority_queue.
vector<int> topThree(vector<int> v) {
    // TODO
    return {};
}

// ----------------------------------------------------------------
int main() {
    cout << "===== LEARN =====\n";
    learn();

    cout << "\n===== YOUR TURN =====\n";

    check("12.1 sumOfSquares({1,2,3}) == 14", sumOfSquares({1, 2, 3}) == 14);
    check("12.1 sumOfSquares({}) == 0",       sumOfSquares({}) == 0);

    check("12.2 removeAll({1,2,1,3,1}, 1) == {2,3}",
          removeAll({1, 2, 1, 3, 1}, 1) == vector<int>({2, 3}));
    check("12.2 removeAll({4,4,4}, 4) == {}",
          removeAll({4, 4, 4}, 4) == vector<int>({}));

    check("12.3 dedupeSorted({3,1,2,3,1}) == {1,2,3}",
          dedupeSorted({3, 1, 2, 3, 1}) == vector<int>({1, 2, 3}));
    check("12.3 dedupeSorted({}) == {}",
          dedupeSorted({}) == vector<int>({}));

    check("12.4 countInRange({1,2,4,4,5,7}, 2, 4) == 3",
          countInRange({1, 2, 4, 4, 5, 7}, 2, 4) == 3);
    check("12.4 countInRange({1,2,4,4,5,7}, 6, 9) == 1",
          countInRange({1, 2, 4, 4, 5, 7}, 6, 9) == 1);
    check("12.4 countInRange({1,2,4,4,5,7}, 8, 9) == 0",
          countInRange({1, 2, 4, 4, 5, 7}, 8, 9) == 0);

    check("12.5 kthSmallest({7,2,5,1,9}, 1) == 1", kthSmallest({7, 2, 5, 1, 9}, 1) == 1);
    check("12.5 kthSmallest({7,2,5,1,9}, 2) == 2", kthSmallest({7, 2, 5, 1, 9}, 2) == 2);
    check("12.5 kthSmallest({7,2,5,1,9}, 5) == 9", kthSmallest({7, 2, 5, 1, 9}, 5) == 9);

    check("12.6 topThree({4,1,7,3,9,2}) == {9,7,4}",
          topThree({4, 1, 7, 3, 9, 2}) == vector<int>({9, 7, 4}));
    check("12.6 topThree({8,1}) == {8,1}",
          topThree({8, 1}) == vector<int>({8, 1}));
    return 0;
}
