// ============================================================
//  Lesson 8 — Lambdas   *** SOLUTION ***
// ============================================================
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void check(const string& name, bool ok) {
    cout << (ok ? "  [PASS] " : "  [ ?? ] ") << name << "\n";
}

void learn() {
    vector<int> v = {4, 7, 1, 9, 2, 8};

    auto isEven = [](int x) { return x % 2 == 0; };
    cout << "isEven(4) = " << isEven(4) << ", isEven(7) = " << isEven(7) << "\n";

    int evens = count_if(v.begin(), v.end(), isEven);
    cout << "There are " << evens << " even numbers.\n";

    sort(v.begin(), v.end(), [](int a, int b) { return a > b; });
    cout << "Descending: ";
    for (int x : v) cout << x << " ";
    cout << "\n";

    int threshold = 5;
    int big = count_if(v.begin(), v.end(),
                       [threshold](int x) { return x > threshold; });
    cout << big << " numbers are greater than " << threshold << "\n";
}

// Exercise 8.1
int countEven(const vector<int>& v) {
    return count_if(v.begin(), v.end(), [](int x) { return x % 2 == 0; });
}

// Exercise 8.2
vector<string> sortByLength(vector<string> words) {
    sort(words.begin(), words.end(),
         [](const string& a, const string& b) { return a.length() < b.length(); });
    return words;
}

// Exercise 8.3
int countAbove(const vector<int>& v, int threshold) {
    return count_if(v.begin(), v.end(),
                    [threshold](int x) { return x > threshold; });
}

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
