// ============================================================
//  Lesson 4 — <algorithm>   *** SOLUTION ***
// ============================================================
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;

void check(const string& name, bool ok) {
    cout << (ok ? "  [PASS] " : "  [ ?? ] ") << name << "\n";
}

void learn() {
    vector<int> v = {5, 2, 9, 2, 7};

    sort(v.begin(), v.end());
    cout << "Sorted: ";
    for (int x : v) cout << x << " ";
    cout << "\n";

    cout << "Biggest: " << *max_element(v.begin(), v.end()) << "\n";
    cout << "Smallest: " << *min_element(v.begin(), v.end()) << "\n";
    cout << "How many 2s: " << count(v.begin(), v.end(), 2) << "\n";
    cout << "Sum: " << accumulate(v.begin(), v.end(), 0) << "\n";

    if (find(v.begin(), v.end(), 9) != v.end())
        cout << "Yes, 9 is in there.\n";
}

// Exercise 4.1
vector<int> sortedCopy(vector<int> v) {
    sort(v.begin(), v.end());
    return v;
}

// Exercise 4.2
int howMany(const vector<int>& v, int target) {
    return count(v.begin(), v.end(), target);
}

// Exercise 4.3
int largest(const vector<int>& v) {
    return *max_element(v.begin(), v.end());
}

// Exercise 4.4
int total(const vector<int>& v) {
    return accumulate(v.begin(), v.end(), 0);
}

// Exercise 4.5
bool contains(const vector<int>& v, int target) {
    return find(v.begin(), v.end(), target) != v.end();
}

int main() {
    cout << "===== LEARN =====\n";
    learn();

    cout << "\n===== YOUR TURN =====\n";
    check("4.1 sortedCopy({3,1,2}) == {1,2,3}",
          sortedCopy({3, 1, 2}) == vector<int>({1, 2, 3}));
    check("4.2 howMany({1,2,2,3,2}, 2) == 3", howMany({1, 2, 2, 3, 2}, 2) == 3);
    check("4.3 largest({4,11,7}) == 11",       largest({4, 11, 7}) == 11);
    check("4.4 total({10,20,30}) == 60",       total({10, 20, 30}) == 60);
    check("4.5 contains({1,2,3}, 2) == true",  contains({1, 2, 3}, 2) == true);
    check("4.5 contains({1,2,3}, 9) == false", contains({1, 2, 3}, 9) == false);
    return 0;
}
