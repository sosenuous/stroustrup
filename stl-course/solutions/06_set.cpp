// ============================================================
//  Lesson 6 — std::set   *** SOLUTION ***
// ============================================================
#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;

void check(const string& name, bool ok) {
    cout << (ok ? "  [PASS] " : "  [ ?? ] ") << name << "\n";
}

void learn() {
    set<int> s;
    for (int x : {5, 2, 5, 9, 2, 5})
        s.insert(x);

    cout << "Inserted 6 numbers, kept " << s.size() << " unique ones: ";
    for (int x : s) cout << x << " ";
    cout << "\n";

    cout << "Have we seen 9? " << (s.count(9) ? "yes" : "no") << "\n";
    cout << "Have we seen 3? " << (s.count(3) ? "yes" : "no") << "\n";
}

// Exercise 6.1
int countUnique(const vector<int>& v) {
    set<int> seen;
    for (int x : v)
        seen.insert(x);
    return seen.size();
}

// Exercise 6.2
bool hasDuplicate(const vector<int>& v) {
    set<int> seen;
    for (int x : v) {
        if (seen.count(x))
            return true;
        seen.insert(x);
    }
    return false;
}

// Exercise 6.3
vector<int> dedupeSorted(const vector<int>& v) {
    set<int> s;
    for (int x : v)
        s.insert(x);
    vector<int> result;
    for (int x : s)
        result.push_back(x);
    return result;
}

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
