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
    return 0;
}
