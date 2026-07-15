// ============================================================
//  Lesson 13 — BIG BOSS 👑🐉 : Approximate String Lookup
// ============================================================
//
//  This is the final boss. Everything you've learned — vectors of
//  vectors, strings, sorting with lambdas, multi-key tie-breaks — comes
//  together to build something genuinely useful: a "did you mean...?"
//  spell-suggester, the thing behind every search box and autocorrect.
//
//  The heart of it is EDIT DISTANCE (a.k.a. Levenshtein distance): the
//  smallest number of single-character edits — INSERT, DELETE, or
//  SUBSTITUTE — needed to turn one word into another.
//
//      kitten -> sitten   (substitute k->s)
//      sitten -> sittin   (substitute e->i)
//      sittin -> sitting  (insert g)
//      => editDistance("kitten","sitting") == 3
//
//  ------------------------------------------------------------
//  HOW TO COMPUTE IT — the DP table
//  ------------------------------------------------------------
//  Build a grid d with (n+1) rows and (m+1) columns, where n = a.size()
//  and m = b.size(). d[i][j] = edit distance between the first i letters
//  of a and the first j letters of b.
//
//  Base cases (turning something into "" costs one delete per letter):
//      d[i][0] = i          d[0][j] = j
//
//  Fill each remaining cell from three neighbours — pick the cheapest:
//      cost = (a[i-1] == b[j-1]) ? 0 : 1     // free if the letters match
//      d[i][j] = min( d[i-1][j]   + 1,       // delete a[i-1]
//                     d[i][j-1]   + 1,       // insert b[j-1]
//                     d[i-1][j-1] + cost )   // substitute (or match)
//
//  The answer is the bottom-right corner, d[n][m].
//
//  A worked grid for a="cat", b="cot":
//
//          ""  c   o   t
//      ""   0  1   2   3
//      c    1  0   1   2
//      a    2  1   1   2
//      t    3  2   2   1     <- d[3][3] = 1  (one substitution a->o)
//
//  Tools you'll want:
//      vector<vector<int>> d(n + 1, vector<int>(m + 1, 0));  // the grid
//      std::min({x, y, z})   // min of several values (needs <algorithm>)
//      s.size(), s[i]        // string length and indexing
//
// ------------------------------------------------------------

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void check(const string& name, bool ok) {
    cout << (ok ? "  [PASS] " : "  [ ?? ] ") << name << "\n";
}

// ----------------------------------------------------------------
//  LEARN — the base cases, so the recurrence isn't a mystery
// ----------------------------------------------------------------
void learn() {
    // Turning any word into the empty string costs one delete per letter,
    // and building it up from "" costs one insert per letter. That's the
    // whole first row and first column of the grid.
    string a = "cat";
    cout << "editDistance(\"" << a << "\", \"\") must be " << a.size() << "\n";
    cout << "editDistance(\"\", \"" << a << "\") must be " << a.size() << "\n";

    // Inside the grid, each cell asks: "did these two letters match?"
    string b = "cot";
    for (size_t i = 0; i < a.size(); ++i) {
        char x = a[i], y = b[i];
        cout << "  compare " << x << " vs " << y << " -> "
             << (x == y ? "match (cost 0)" : "differ (cost 1)") << "\n";
    }
    cout << "Fill the grid with the min of delete/insert/substitute and the\n"
         << "answer is the bottom-right corner. Now go build editDistance!\n";
}

// ----------------------------------------------------------------
//  BOSS FIGHT — build the lookup, stage by stage
// ----------------------------------------------------------------

// Exercise 13.1 — Edit distance (the core) 🗡️
// Return the Levenshtein edit distance between a and b using the DP table
// described at the top of this file.
//   editDistance("kitten", "sitting")  == 3
//   editDistance("", "abc")            == 3
//   editDistance("abc", "abc")         == 0
//   editDistance("flaw", "lawn")       == 2
//   editDistance("sunday", "saturday") == 3
// Idea: make vector<vector<int>> d(n+1, vector<int>(m+1)); fill the base
//       row/column, then every cell via min({del, ins, sub}); return d[n][m].
int editDistance(const string& a, const string& b) {
    // TODO
    return -1;
}

// Exercise 13.2 — Closest word 🛡️
// Return the word in `dict` with the SMALLEST edit distance to `query`.
// Break ties by choosing the alphabetically smallest word. `dict` is never
// empty. (Call your editDistance from 13.1 — that's the point.)
//   closestWord({"cat","car","bat","cart","dog"}, "cet") == "cat"
//   closestWord({"bat","cat"}, "at")                     == "bat"  // tie -> alphabetical
// Idea: track the best word and its distance; a candidate wins if its
//       distance is smaller, OR equal but the word sorts earlier.
string closestWord(const vector<string>& dict, const string& query) {
    // TODO
    return "";
}

// Exercise 13.3 — "Did you mean...?" suggestions 🐉  (BOSS)
// Return every word in `dict` whose edit distance to `query` is <= maxDist,
// sorted by distance (closest first), and alphabetically within the same
// distance.
//   suggestions({"cat","cot","cut","dog","cats"}, "cat", 1)
//       == {"cat","cats","cot","cut"}          // cat:0, then cats/cot/cut:1
//   suggestions({"apple","apply","ample","maple"}, "aple", 2)
//       == {"ample","apple","maple","apply"}   // three at dist 1, then apply:2
// Idea: collect {distance, word} pairs that pass the threshold, std::sort
//       them with a lambda (distance first, then word), then pull the words.
vector<string> suggestions(const vector<string>& dict, const string& query, int maxDist) {
    // TODO
    return {};
}

// ----------------------------------------------------------------
int main() {
    cout << "===== LEARN =====\n";
    learn();

    cout << "\n===== BOSS FIGHT =====\n";

    check("13.1 editDistance(kitten, sitting) == 3", editDistance("kitten", "sitting") == 3);
    check("13.1 editDistance('', abc) == 3",         editDistance("", "abc") == 3);
    check("13.1 editDistance(abc, abc) == 0",        editDistance("abc", "abc") == 0);
    check("13.1 editDistance(flaw, lawn) == 2",      editDistance("flaw", "lawn") == 2);
    check("13.1 editDistance(sunday, saturday) == 3", editDistance("sunday", "saturday") == 3);

    check("13.2 closestWord(..., cet) == cat",
          closestWord({"cat", "car", "bat", "cart", "dog"}, "cet") == "cat");
    check("13.2 closestWord({bat,cat}, at) == bat  (tie)",
          closestWord({"bat", "cat"}, "at") == "bat");

    check("13.3 suggestions(..., cat, 1) == {cat,cats,cot,cut}",
          suggestions({"cat", "cot", "cut", "dog", "cats"}, "cat", 1)
              == vector<string>({"cat", "cats", "cot", "cut"}));
    check("13.3 suggestions(..., aple, 2) == {ample,apple,maple,apply}",
          suggestions({"apple", "apply", "ample", "maple"}, "aple", 2)
              == vector<string>({"ample", "apple", "maple", "apply"}));

    cout << "\nBeat all three and you've built real autocorrect. 👑\n";
    return 0;
}
