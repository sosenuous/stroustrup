// ============================================================
//  Lesson 9 — CHALLENGES   *** SOLUTION ***
// ============================================================
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

void check(const string& name, bool ok) {
    cout << (ok ? "  [PASS] " : "  [ ?? ] ") << name << "\n";
}

// Challenge 9.1
string runLengthEncode(const string& s) {
    string out = "";
    size_t i = 0;
    while (i < s.size()) {
        char c = s[i];
        int count = 0;
        while (i < s.size() && s[i] == c) {
            ++count;
            ++i;
        }
        out += c;
        out += to_string(count);
    }
    return out;
}

// Challenge 9.2
char firstUnique(const string& s) {
    map<char, int> freq;
    for (char c : s)
        freq[c]++;
    for (char c : s)
        if (freq[c] == 1)
            return c;
    return '?';
}

// Challenge 9.3
bool hasPairSum(const vector<int>& v, int target) {
    set<int> seen;
    for (int x : v) {
        if (seen.count(target - x))
            return true;
        seen.insert(x);
    }
    return false;
}

// Challenge 9.4
string mostFrequent(const vector<string>& words) {
    map<string, int> freq;
    for (const string& w : words)
        freq[w]++;

    string best = "";
    int bestCount = 0;
    for (const auto& entry : freq) {          // map keys come out alphabetical
        if (entry.second > bestCount) {       // strictly bigger -> ties keep the earlier (alpha) word
            bestCount = entry.second;
            best = entry.first;
        }
    }
    return best;
}

// Challenge 9.5
vector<string> ranking(vector<pair<string, int>> players) {
    sort(players.begin(), players.end(),
         [](const pair<string, int>& a, const pair<string, int>& b) {
             if (a.second != b.second)
                 return a.second > b.second;   // higher score first
             return a.first < b.first;          // tie -> name ascending
         });
    vector<string> names;
    for (const auto& p : players)
        names.push_back(p.first);
    return names;
}

// Challenge 9.6
vector<int> mergedUnique(const vector<int>& a, const vector<int>& b) {
    set<int> s;
    for (int x : a) s.insert(x);
    for (int x : b) s.insert(x);
    return vector<int>(s.begin(), s.end());
}

int main() {
    cout << "===== CHALLENGES =====\n";

    check("9.1 rle(\"aaabbc\") == \"a3b2c1\"", runLengthEncode("aaabbc") == "a3b2c1");
    check("9.1 rle(\"xyz\") == \"x1y1z1\"",    runLengthEncode("xyz") == "x1y1z1");
    check("9.1 rle(\"\") == \"\"",             runLengthEncode("") == "");

    check("9.2 firstUnique(\"leetcode\") == 'l'", firstUnique("leetcode") == 'l');
    check("9.2 firstUnique(\"aabbc\") == 'c'",    firstUnique("aabbc") == 'c');
    check("9.2 firstUnique(\"aabb\") == '?'",     firstUnique("aabb") == '?');

    check("9.3 hasPairSum({2,7,4}, 9) == true",   hasPairSum({2, 7, 4}, 9) == true);
    check("9.3 hasPairSum({1,2,3}, 10) == false", hasPairSum({1, 2, 3}, 10) == false);

    check("9.4 mostFrequent (cat wins)",
          mostFrequent({"cat", "dog", "cat", "bird", "dog", "cat"}) == "cat");
    check("9.4 mostFrequent (tie -> 'a')",
          mostFrequent({"b", "a", "b", "a"}) == "a");

    check("9.5 ranking by score then name",
          ranking({{"Ada", 90}, {"Ben", 90}, {"Cid", 75}})
              == vector<string>({"Ada", "Ben", "Cid"}));

    check("9.6 mergedUnique({3,1,2},{2,5,1}) == {1,2,3,5}",
          mergedUnique({3, 1, 2}, {2, 5, 1}) == vector<int>({1, 2, 3, 5}));
    return 0;
}
