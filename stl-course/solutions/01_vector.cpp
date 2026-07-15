// ============================================================
//  Lesson 1 — std::vector   *** SOLUTION ***
// ============================================================
#include <iostream>
#include <vector>
using namespace std;

void check(const string& name, bool ok) {
    cout << (ok ? "  [PASS] " : "  [ ?? ] ") << name << "\n";
}

void print(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i)
        cout << v[i] << (i + 1 < v.size() ? ", " : "");
    cout << "]";
}

void learn() {
    vector<int> scores;
    scores.push_back(90);
    scores.push_back(75);
    scores.push_back(88);

    cout << "We stored " << scores.size() << " scores: ";
    print(scores);
    cout << "\n";
    cout << "The first score is " << scores[0] << "\n";

    for (int& s : scores)
        s += 5;

    cout << "After a +5 bonus: ";
    print(scores);
    cout << "\n";
}

// Exercise 1.1
vector<int> makeCountdown(int n) {
    vector<int> result;
    for (int i = n; i >= 1; --i)
        result.push_back(i);
    return result;
}

// Exercise 1.2
int sumVector(const vector<int>& v) {
    int total = 0;
    for (int x : v)
        total += x;
    return total;
}

// Exercise 1.3
vector<int> doubled(const vector<int>& v) {
    vector<int> result;
    for (int x : v)
        result.push_back(x * 2);
    return result;
}

int main() {
    cout << "===== LEARN =====\n";
    learn();

    cout << "\n===== YOUR TURN =====\n";
    check("1.1 makeCountdown(5) == {5,4,3,2,1}",
          makeCountdown(5) == vector<int>({5, 4, 3, 2, 1}));
    check("1.1 makeCountdown(0) is empty",
          makeCountdown(0).empty());
    check("1.2 sumVector({4,5,6}) == 15",
          sumVector({4, 5, 6}) == 15);
    check("1.2 sumVector({}) == 0",
          sumVector({}) == 0);
    check("1.3 doubled({1,2,3}) == {2,4,6}",
          doubled({1, 2, 3}) == vector<int>({2, 4, 6}));
    return 0;
}
