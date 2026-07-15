// ============================================================
//  Lesson 9 — CHALLENGES : put it all together 🔥
// ============================================================
//
//  No new features here — just harder problems. Each one needs you to
//  COMBINE things you already know: vectors, strings, maps, sets, sort,
//  and lambdas. The hints are lighter on purpose. Think about which
//  STL tool fits before you start typing.
//
//  Reach for these headers as needed:
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

// ----------------------------------------------------------------
//  CHALLENGE 9.1 — Run-length encoding
// ----------------------------------------------------------------
// Compress a string by replacing runs of the same character with the
// character followed by how many times it repeats.
//   "aaabbc"   -> "a3b2c1"
//   "xyz"      -> "x1y1z1"
//   ""         -> ""
// Hint: walk the string; count how long each run of identical chars is.
//       std::to_string(count) turns a number into text you can glue on.
string runLengthEncode(const string& s) {
    string out = "";
    // TODO
    return out;
}

// ----------------------------------------------------------------
//  CHALLENGE 9.2 — First non-repeating character
// ----------------------------------------------------------------
// Return the first character that appears EXACTLY ONCE in s.
// If every character repeats (or s is empty), return '?'.
//   "leetcode" -> 'l'
//   "aabbc"    -> 'c'
//   "aabb"     -> '?'
// Hint: two passes. First count every character (a map<char,int>).
//       Then scan s again IN ORDER and return the first with count 1.
char firstUnique(const string& s) {
    // TODO
    return '?';
}

// ----------------------------------------------------------------
//  CHALLENGE 9.3 — Any two numbers add up to target?
// ----------------------------------------------------------------
// Return true if SOME pair of elements (at two different positions)
// sums exactly to target.
//   hasPairSum({2, 7, 4}, 9)  -> true   (2 + 7)
//   hasPairSum({1, 2, 3}, 10) -> false
// Hint: the slow way is two nested loops. The clever way uses a set:
//       for each x, have you already seen (target - x)?
bool hasPairSum(const vector<int>& v, int target) {
    // TODO
    return false;
}

// ----------------------------------------------------------------
//  CHALLENGE 9.4 — Most frequent word
// ----------------------------------------------------------------
// Return the word that appears most often. If there's a tie, return the
// one that comes first alphabetically.
//   {"cat","dog","cat","bird","dog","cat"} -> "cat"
//   {"b","a","b","a"}                      -> "a"   (tie -> alphabetical)
// Hint: count with a map<string,int>. Remember a map iterates its keys
//       in sorted (alphabetical) order — that gives you the tie-break
//       for free if you only replace the best on a STRICTLY bigger count.
string mostFrequent(const vector<string>& words) {
    // TODO
    return "";
}

// ----------------------------------------------------------------
//  CHALLENGE 9.5 — Rank the scoreboard
// ----------------------------------------------------------------
// Given (name, score) pairs, return just the names ordered by score
// HIGHEST first. On a tie, order those names alphabetically.
//   { {"Ada",90}, {"Ben",90}, {"Cid",75} } -> {"Ada","Ben","Cid"}
// Hint: std::sort with a lambda comparator. Compare scores first; only
//       if the scores are equal, compare names.
vector<string> ranking(vector<pair<string, int>> players) {
    // TODO: sort players, then pull out the names in order
    vector<string> names;
    return names;
}

// ----------------------------------------------------------------
//  CHALLENGE 9.6 — Merge two lists, unique and sorted
// ----------------------------------------------------------------
// Combine a and b into one vector containing every value that appears in
// either, with NO duplicates, in sorted order.
//   mergedUnique({3,1,2}, {2,5,1}) -> {1,2,3,5}
// Hint: a set does the dedupe AND the sorting for you. Then you can build
//       a vector straight from a set:  vector<int>(s.begin(), s.end())
vector<int> mergedUnique(const vector<int>& a, const vector<int>& b) {
    // TODO
    return {};
}

// ================================================================
//  GOING FURTHER — these bite harder. Take your time. 🧗
// ================================================================

// ----------------------------------------------------------------
//  CHALLENGE 9.7 — Count anagram groups
// ----------------------------------------------------------------
// Two words are anagrams if one is a rearrangement of the other's
// letters ("eat" and "tea"). Group the words so that anagrams land in
// the same group, then return HOW MANY groups there are.
//   {"eat","tea","tan","ate","nat","bat"} -> 3
//         ({eat,tea,ate}, {tan,nat}, {bat})
//   {"abc","cba","xyz"}                    -> 2
//   {}                                     -> 0
// Hint: what's a "fingerprint" that's identical for anagrams but
//       different otherwise? Sort the letters of each word. Feed those
//       fingerprints into a set<string> (or a map) — its size is your
//       answer, since the set collapses duplicates for you. 🔑
int countAnagramGroups(const vector<string>& words) {
    // TODO
    return -1;
}

// ----------------------------------------------------------------
//  CHALLENGE 9.8 — Top two most frequent
// ----------------------------------------------------------------
// Return the TWO values that appear most often, most frequent FIRST.
// If two values tie on frequency, the SMALLER value comes first.
// (Assume there are always at least two distinct values.)
//   {1,1,1,2,2,3}   -> {1,2}      (counts 3, 2, 1)
//   {4,4,5,5,6}     -> {4,5}      (4 and 5 tie -> smaller first)
//   {9,8,8,7,7,7}   -> {7,8}      (counts 3, 2, 1)
// Hint: count with a map<int,int>, then move the (value,count) pairs
//       into a vector and std::sort with a lambda: higher count first,
//       and on equal counts, smaller value first. Take the first two.
vector<int> topTwoFrequent(const vector<int>& v) {
    // TODO
    return {};
}

// ----------------------------------------------------------------
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

    cout << "\n===== GOING FURTHER =====\n";

    check("9.7 countAnagramGroups (eat/tea/... ) == 3",
          countAnagramGroups({"eat", "tea", "tan", "ate", "nat", "bat"}) == 3);
    check("9.7 countAnagramGroups({abc,cba,xyz}) == 2",
          countAnagramGroups({"abc", "cba", "xyz"}) == 2);
    check("9.7 countAnagramGroups({}) == 0",
          countAnagramGroups({}) == 0);

    check("9.8 topTwoFrequent({1,1,1,2,2,3}) == {1,2}",
          topTwoFrequent({1, 1, 1, 2, 2, 3}) == vector<int>({1, 2}));
    check("9.8 topTwoFrequent({4,4,5,5,6}) == {4,5}",
          topTwoFrequent({4, 4, 5, 5, 6}) == vector<int>({4, 5}));
    check("9.8 topTwoFrequent({9,8,8,7,7,7}) == {7,8}",
          topTwoFrequent({9, 8, 8, 7, 7, 7}) == vector<int>({7, 8}));
    return 0;
}
