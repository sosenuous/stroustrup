// ============================================================
//  Lesson 10 — ADVANCED : the deep end 🌊
// ============================================================
//
//  These are the hardest yet. Several are classic problems that show up
//  in real programming interviews. The hints only point at the IDEA —
//  you design the code. Expect to sketch the approach on paper first.
//
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

// ----------------------------------------------------------------
//  10.1 — Balanced brackets
// ----------------------------------------------------------------
// Return true if every bracket in s is correctly matched and nested.
// Handle three kinds:  ( )   [ ]   { }.  Ignore any other characters.
//   "([]{})"   -> true
//   "([)]"     -> false   (wrong nesting)
//   "((("      -> false   (never closed)
//   "a(b[c]d)" -> true
//   ""         -> true
// Idea: push every opening bracket on a STACK. On a closing bracket, the
//       stack's top must be the MATCHING opener — else it's unbalanced.
//       At the end the stack must be empty.
bool isBalanced(const string& s) {
    // TODO
    return false;
}

// ----------------------------------------------------------------
//  10.2 — Longest strictly-increasing streak
// ----------------------------------------------------------------
// Return the length of the longest run of consecutive elements where
// each is strictly greater than the one before it.
//   {1,2,1,2,3,4,1} -> 4   (the run 1,2,3,4)
//   {5,4,3,2}       -> 1
//   {}              -> 0
// Idea: sweep once, keeping a "current streak" length and a "best so far".
int longestIncreasingStreak(const vector<int>& v) {
    // TODO
    return 0;
}

// ----------------------------------------------------------------
//  10.3 — Top-K most frequent words
// ----------------------------------------------------------------
// Return the k most frequent words, ordered by count (highest first).
// Break ties alphabetically. Return fewer than k if there aren't enough.
//   words = {"i","love","leetcode","i","love","coding"}, k = 2
//     counts: i:2, love:2, coding:1, leetcode:1  ->  {"i","love"}
// Idea: count with a map<string,int>. Copy the entries into a
//       vector<pair<string,int>> so you can std::sort them with a lambda
//       (count descending, then word ascending). Take the first k names.
vector<string> topKFrequent(const vector<string>& words, int k) {
    // TODO
    return {};
}

// ----------------------------------------------------------------
//  10.4 — Count anagram groups
// ----------------------------------------------------------------
// Two words are anagrams if they use exactly the same letters (e.g.
// "eat" and "tea"). Return how many distinct anagram groups there are.
//   {"eat","tea","tan","ate","nat","bat"} -> 3
//     groups: {eat,tea,ate}, {tan,nat}, {bat}
// Idea: the SORTED letters of a word are the same for all its anagrams,
//       so they make a perfect "group key". Collect those keys in a set
//       and the set's size is your answer.
int countAnagramGroups(const vector<string>& words) {
    // TODO
    return 0;
}

// ----------------------------------------------------------------
//  10.5 — Median
// ----------------------------------------------------------------
// Return the median of the numbers as a double.
//   odd count  -> the middle value            median({3,1,2})   = 2.0
//   even count -> average of the two middles   median({1,2,3,4}) = 2.5
//   empty      -> 0.0
// Idea: sort a COPY, then pick by index. Watch the even case: use /2.0 so
//       you get a real average, not integer division.
double median(vector<int> v) {
    // TODO
    return 0.0;
}

// ----------------------------------------------------------------
//  10.6 — Merge overlapping intervals  (boss level 👑)
// ----------------------------------------------------------------
// Each pair {start, end} is an interval. Merge any that overlap or touch,
// and return the merged intervals sorted by start.
//   {{1,3},{2,6},{8,10},{15,18}} -> {{1,6},{8,10},{15,18}}
//   {{1,4},{4,5}}                -> {{1,5}}          (touching counts)
//   {}                           -> {}
// Idea: SORT the intervals by start first. Walk through them keeping a
//       "current" merged interval; if the next one starts at or before
//       the current end, stretch the current end to the max of the two;
//       otherwise the current interval is finished — save it and start a
//       new one. (a.first / a.second are the start / end of pair a.)
vector<pair<int, int>> mergeIntervals(vector<pair<int, int>> intervals) {
    // TODO
    return {};
}

// ----------------------------------------------------------------
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
