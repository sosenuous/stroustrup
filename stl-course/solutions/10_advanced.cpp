// ============================================================
//  Lesson 10 — ADVANCED   *** SOLUTION ***
// ============================================================
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <algorithm>
using namespace std;

void check(const string& name, bool ok) {
    cout << (ok ? "  [PASS] " : "  [ ?? ] ") << name << "\n";
}

// 10.1
bool isBalanced(const string& s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (st.empty()) return false;
            char open = st.top();
            st.pop();
            if ((c == ')' && open != '(') ||
                (c == ']' && open != '[') ||
                (c == '}' && open != '{'))
                return false;
        }
        // any other character is ignored
    }
    return st.empty();
}

// 10.2
int longestIncreasingStreak(const vector<int>& v) {
    if (v.empty()) return 0;
    int best = 1, cur = 1;
    for (size_t i = 1; i < v.size(); ++i) {
        if (v[i] > v[i - 1]) cur++;
        else cur = 1;
        best = max(best, cur);
    }
    return best;
}

// 10.3
vector<string> topKFrequent(const vector<string>& words, int k) {
    map<string, int> freq;
    for (const string& w : words)
        freq[w]++;

    vector<pair<string, int>> items(freq.begin(), freq.end());
    sort(items.begin(), items.end(),
         [](const pair<string, int>& a, const pair<string, int>& b) {
             if (a.second != b.second)
                 return a.second > b.second;   // higher count first
             return a.first < b.first;          // tie -> alphabetical
         });

    vector<string> result;
    for (int i = 0; i < k && i < (int)items.size(); ++i)
        result.push_back(items[i].first);
    return result;
}

// 10.4
int countAnagramGroups(const vector<string>& words) {
    set<string> keys;
    for (string w : words) {           // copy so we can sort its letters
        sort(w.begin(), w.end());
        keys.insert(w);
    }
    return keys.size();
}

// 10.5
double median(vector<int> v) {
    if (v.empty()) return 0.0;
    sort(v.begin(), v.end());
    int n = v.size();
    if (n % 2 == 1)
        return v[n / 2];
    return (v[n / 2 - 1] + v[n / 2]) / 2.0;
}

// 10.6
vector<pair<int, int>> mergeIntervals(vector<pair<int, int>> intervals) {
    sort(intervals.begin(), intervals.end());   // by start, then end
    vector<pair<int, int>> merged;
    for (const auto& iv : intervals) {
        if (!merged.empty() && iv.first <= merged.back().second)
            merged.back().second = max(merged.back().second, iv.second);
        else
            merged.push_back(iv);
    }
    return merged;
}

int main() {
    cout << "===== ADVANCED =====\n";

    check("10.1 isBalanced(\"([]{})\") == true",  isBalanced("([]{})") == true);
    check("10.1 isBalanced(\"([)]\") == false",   isBalanced("([)]") == false);
    check("10.1 isBalanced(\"(((\") == false",    isBalanced("(((") == false);
    check("10.1 isBalanced(\"a(b[c]d)\") == true", isBalanced("a(b[c]d)") == true);

    check("10.2 longestIncreasingStreak({1,2,1,2,3,4,1}) == 4",
          longestIncreasingStreak({1, 2, 1, 2, 3, 4, 1}) == 4);
    check("10.2 longestIncreasingStreak({5,4,3,2}) == 1",
          longestIncreasingStreak({5, 4, 3, 2}) == 1);
    check("10.2 longestIncreasingStreak({}) == 0",
          longestIncreasingStreak({}) == 0);

    check("10.3 topKFrequent(..., 2) == {i, love}",
          topKFrequent({"i", "love", "leetcode", "i", "love", "coding"}, 2)
              == vector<string>({"i", "love"}));

    check("10.4 countAnagramGroups(...) == 3",
          countAnagramGroups({"eat", "tea", "tan", "ate", "nat", "bat"}) == 3);

    check("10.5 median({3,1,2}) == 2.0",   median({3, 1, 2}) == 2.0);
    check("10.5 median({1,2,3,4}) == 2.5", median({1, 2, 3, 4}) == 2.5);

    vector<pair<int, int>> want = {{1, 6}, {8, 10}, {15, 18}};
    check("10.6 mergeIntervals(...) == {{1,6},{8,10},{15,18}}",
          mergeIntervals({{1, 3}, {2, 6}, {8, 10}, {15, 18}}) == want);
    check("10.6 mergeIntervals({{1,4},{4,5}}) == {{1,5}}",
          mergeIntervals({{1, 4}, {4, 5}}) == vector<pair<int, int>>({{1, 5}}));
    return 0;
}
