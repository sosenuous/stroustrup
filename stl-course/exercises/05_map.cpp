// ============================================================
//  Lesson 5 — std::pair & std::map : key -> value lookups
// ============================================================
//
//  A std::pair bundles TWO values together:
//      pair<string,int> p = {"Ada", 90};
//      p.first   -> "Ada"
//      p.second  -> 90
//
//  A std::map is a collection of pairs where each KEY is unique and
//  maps to a VALUE. Think of a real dictionary: word -> definition,
//  or here: name -> score.
//
//      map<string,int> score;
//      score["Ada"] = 90;         // insert or update
//      score["Ben"] = 75;
//      cout << score["Ada"];      // look up -> 90
//      score.size();              // how many entries
//
//  Careful! Reading score["Zoe"] when "Zoe" doesn't exist will CREATE
//  it with value 0. To just CHECK, use:
//      score.count("Zoe")      // 1 if present, 0 if not
//      score.contains("Zoe")   // (C++20) true / false
//
//  Loop over a map (you get pairs, in sorted-by-key order):
//      for (auto& entry : score)
//          cout << entry.first << " -> " << entry.second << "\n";
//
// ------------------------------------------------------------

#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

void check(const string& name, bool ok) {
    cout << (ok ? "  [PASS] " : "  [ ?? ] ") << name << "\n";
}

// ----------------------------------------------------------------
//  LEARN
// ----------------------------------------------------------------
void learn() {
    map<string, int> score;
    score["Ada"] = 90;
    score["Ben"] = 75;
    score["Cid"] = 88;

    cout << "Ada scored " << score["Ada"] << "\n";
    cout << "There are " << score.size() << " players.\n";

    cout << "Scoreboard (sorted by name):\n";
    for (auto& entry : score)
        cout << "  " << entry.first << " -> " << entry.second << "\n";

    cout << "Is 'Zoe' present? " << (score.count("Zoe") ? "yes" : "no") << "\n";
}

// ----------------------------------------------------------------
//  YOUR TURN
// ----------------------------------------------------------------

// Exercise 5.1
// Build a map from each word to its length.
// {"hi","cat"} -> { "hi":2, "cat":3 }.
map<string, int> wordLengths(const vector<string>& words) {
    map<string, int> result;
    // TODO: for each word w, set result[w] = w.length();
    return result;
}

// Exercise 5.2
// Look up `key` in m. If present, return its value; otherwise return
// the given `fallback`. IMPORTANT: use m.count(key) to check first, so
// you don't accidentally create a new entry.
int lookupOr(const map<string, int>& m, const string& key, int fallback) {
    // TODO: if m.count(key) is nonzero, return m.at(key); else return fallback
    //       (use m.at(key) here — [] doesn't work on a const map)
    return fallback;
}

// Exercise 5.3
// Count how often each character appears in s.
// "banana" -> { 'a':3, 'b':1, 'n':2 }.
// Hint: freq[c]++ works even the first time — a missing key starts at 0.
map<char, int> charFrequency(const string& s) {
    map<char, int> freq;
    // TODO: for each char c in s, do freq[c]++;
    return freq;
}

// ----------------------------------------------------------------
//  GOING FURTHER 🔥
// ----------------------------------------------------------------

// ================================================================
// Exercise 5.4 — Invert a map
// ================================================================
// Given a map<string,int> where every VALUE is unique, build the
// "flipped" map<int,string> that turns each value into a key.
//
//   { "Ada":90, "Ben":75 }  ->  { 90:"Ada", 75:"Ben" }
//
// So looking up 90 in the result gives back "Ada".
//
// Hint: loop over m — each entry has .first (the string) and
//       .second (the int) — then set result[entry.second] = entry.first;
map<int, string> invertMap(const map<string, int>& m) {
    map<int, string> result;
    // TODO: for each entry in m, do result[entry.second] = entry.first;
    return result;
}

// ================================================================
// Exercise 5.5 — Most frequent word (alphabetical tie-break)
// ================================================================
// Given a list of words, find the one that appears MOST often.
// If several words tie for the top count, return the one that comes
// FIRST alphabetically.
//
//   {"pear","apple","pear","apple","apple"}  ->  "apple"  (3 beats 2)
//   {"dog","cat","dog","cat"}                ->  "cat"    (tie 2-2, 'cat' < 'dog')
//
// Neat trick 🎩: build a map<string,int> of counts, then loop over it.
// Because a map walks its keys in SORTED order, if you only replace the
// current best when you find a STRICTLY greater count, the first word of
// any tie (the alphabetically smallest) naturally wins.
//
// Hint: 1) map<string,int> count; for each w: count[w]++;
//       2) start best="" with bestCount=-1;
//          for each entry in count:
//              if (entry.second > bestCount) { best=entry.first; bestCount=entry.second; }
//       3) return best;
string mostFrequentWord(const vector<string>& words) {
    // TODO: replace this placeholder with the real logic described above
    return "?";
}

// ----------------------------------------------------------------
int main() {
    cout << "===== LEARN =====\n";
    learn();

    cout << "\n===== YOUR TURN =====\n";
    map<string, int> wl = wordLengths({"hi", "cat", "hello"});
    check("5.1 wordLengths: hi->2",    wl["hi"] == 2);
    check("5.1 wordLengths: hello->5", wl["hello"] == 5);

    map<string, int> m = {{"Ada", 90}, {"Ben", 75}};
    check("5.2 lookupOr present -> 90",     lookupOr(m, "Ada", -1) == 90);
    check("5.2 lookupOr missing -> fallback", lookupOr(m, "Zoe", -1) == -1);

    map<char, int> f = charFrequency("banana");
    check("5.3 charFrequency 'a' == 3", f['a'] == 3);
    check("5.3 charFrequency 'n' == 2", f['n'] == 2);
    check("5.3 charFrequency 'b' == 1", f['b'] == 1);

    cout << "\n===== GOING FURTHER =====\n";
    map<int, string> inv = invertMap({{"Ada", 90}, {"Ben", 75}});
    map<int, string> invExpected = {{90, "Ada"}, {75, "Ben"}};
    check("5.4 invertMap flips the whole map", inv == invExpected);
    check("5.4 invertMap: 90 -> Ada",          inv[90] == "Ada");

    check("5.5 mostFrequentWord clear winner",
          mostFrequentWord({"pear", "apple", "pear", "apple", "apple"}) == "apple");
    check("5.5 mostFrequentWord tie -> alphabetical",
          mostFrequentWord({"dog", "cat", "dog", "cat"}) == "cat");
    return 0;
}
