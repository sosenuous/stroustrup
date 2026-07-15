// ============================================================
//  Lesson 12 — STL TO THE LIMITS  ★ SOLUTION ★
// ============================================================
//  Worked answers. Each one collapses a loop into an algorithm call.
// ------------------------------------------------------------

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

void check(const string& name, bool ok) {
    cout << (ok ? "  [PASS] " : "  [ ?? ] ") << name << "\n";
}

// 12.1 — accumulate as a fold: square each element as you go.
int sumOfSquares(const vector<int>& v) {
    return accumulate(v.begin(), v.end(), 0,
                      [](int acc, int x) { return acc + x * x; });
}

// 12.2 — erase-remove idiom: remove() compacts, erase() trims.
vector<int> removeAll(vector<int> v, int value) {
    v.erase(remove(v.begin(), v.end(), value), v.end());
    return v;
}

// 12.3 — sort, then unique+erase (unique only kills ADJACENT dups).
vector<int> dedupeSorted(vector<int> v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    return v;
}

// 12.4 — binary search: count = upper_bound(hi) - lower_bound(lo).
int countInRange(const vector<int>& v, int lo, int hi) {
    return upper_bound(v.begin(), v.end(), hi) - lower_bound(v.begin(), v.end(), lo);
}

// 12.5 — nth_element positions the k-th smallest without a full sort.
int kthSmallest(vector<int> v, int k) {
    nth_element(v.begin(), v.begin() + (k - 1), v.end());
    return v[k - 1];
}

// 12.6 — sort descending, keep the first three.
vector<int> topThree(vector<int> v) {
    sort(v.rbegin(), v.rend());
    if (v.size() > 3) v.resize(3);
    return v;
}

// ----------------------------------------------------------------
int main() {
    cout << "===== SOLUTION 12 =====\n";

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
