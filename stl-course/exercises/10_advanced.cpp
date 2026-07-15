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
//  10.7 — Longest substring without repeating characters  (boss level 👑)
// ----------------------------------------------------------------
// Return the LENGTH of the longest contiguous substring of s in which no
// character repeats.
//   "abcabcbb" -> 3   (the substring "abc")
//   "bbbbb"    -> 1   (the substring "b")
//   "pwwkew"   -> 3   (the substring "wke", NOT "pwke" — must be contiguous)
//   "dvdf"     -> 3   (the substring "vdf")
//   ""         -> 0
// Idea: slide a WINDOW [left..right] across the string. Extend right one
//       character at a time. If that character is already inside the window,
//       shrink from the left until it isn't. The answer is the largest
//       window width you ever see. A set<char> (or a last-seen map) tells you
//       whether a character is currently in the window.
int longestUniqueSubstring(const string& s) {
    // TODO
    return 0;
}

// ----------------------------------------------------------------
//  10.8 — Maximum subarray sum (Kadane's algorithm)  (boss level 👑)
// ----------------------------------------------------------------
// Return the largest sum obtainable from any NON-EMPTY contiguous subarray.
// Note the numbers can be negative, so you cannot just add the positives.
//   {-2,1,-3,4,-1,2,1,-5,4} -> 6    (the run {4,-1,2,1})
//   {1}                     -> 1
//   {-1,-2,-3}              -> -1    (best you can do is one element)
//   {5,4,-1,7,8}            -> 23    (the whole array)
// Idea: sweep once. Keep a "best sum ending exactly here". At each element
//       you either EXTEND the previous run or START FRESH at this element —
//       whichever gives a bigger sum. Track the best value seen anywhere.
//       (Seed both trackers with the first element so all-negative works.)
int maxSubarraySum(const vector<int>& v) {
    // TODO
    return 0;
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

    cout << "\n===== GOING FURTHER (BOSS LEVEL 👑) =====\n";

    check("10.7 longestUniqueSubstring(\"abcabcbb\") == 3",
          longestUniqueSubstring("abcabcbb") == 3);
    check("10.7 longestUniqueSubstring(\"bbbbb\") == 1",
          longestUniqueSubstring("bbbbb") == 1);
    check("10.7 longestUniqueSubstring(\"pwwkew\") == 3",
          longestUniqueSubstring("pwwkew") == 3);
    check("10.7 longestUniqueSubstring(\"dvdf\") == 3",
          longestUniqueSubstring("dvdf") == 3);

    check("10.8 maxSubarraySum({-2,1,-3,4,-1,2,1,-5,4}) == 6",
          maxSubarraySum({-2, 1, -3, 4, -1, 2, 1, -5, 4}) == 6);
    check("10.8 maxSubarraySum({1}) == 1",
          maxSubarraySum({1}) == 1);
    check("10.8 maxSubarraySum({-1,-2,-3}) == -1",
          maxSubarraySum({-1, -2, -3}) == -1);
    check("10.8 maxSubarraySum({5,4,-1,7,8}) == 23",
          maxSubarraySum({5, 4, -1, 7, 8}) == 23);
    return 0;
}
