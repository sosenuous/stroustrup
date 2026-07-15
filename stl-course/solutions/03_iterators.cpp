// ============================================================
//  Lesson 3 — Iterators   *** SOLUTION ***
// ============================================================
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void check(const string& name, bool ok) {
    cout << (ok ? "  [PASS] " : "  [ ?? ] ") << name << "\n";
}

void learn() {
    vector<int> v = {10, 20, 30};

    cout << "First element via *v.begin(): " << *v.begin() << "\n";

    cout << "All elements: ";
    for (auto it = v.begin(); it != v.end(); ++it)
        cout << *it << " ";
    cout << "\n";

    for (auto it = v.begin(); it != v.end(); ++it)
        *it += 1;
    cout << "After +1 each: ";
    for (int x : v) cout << x << " ";
    cout << "\n";
}

// Exercise 3.1
int firstElement(const vector<int>& v) {
    return *v.begin();
}

// Exercise 3.2
int sumWithIterators(const vector<int>& v) {
    int total = 0;
    for (auto it = v.begin(); it != v.end(); ++it)
        total += *it;
    return total;
}

// Exercise 3.3
int maxWithIterators(const vector<int>& v) {
    int best = *v.begin();
    for (auto it = v.begin(); it != v.end(); ++it)
        if (*it > best)
            best = *it;
    return best;
}

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
