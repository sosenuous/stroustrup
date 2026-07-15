// ============================================================
//  Lesson 13 — BIG BOSS : Approximate String Lookup  ★ SOLUTION ★
// ============================================================
//  Worked answers for the final boss. If you got here after beating it
//  yourself — congratulations, you built autocorrect. 👑
// ------------------------------------------------------------

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void check(const string& name, bool ok) {
    cout << (ok ? "  [PASS] " : "  [ ?? ] ") << name << "\n";
}

// 13.1 — Levenshtein edit distance via the classic DP table.
int editDistance(const string& a, const string& b) {
    int n = a.size(), m = b.size();
    vector<vector<int>> d(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; ++i) d[i][0] = i;   // delete all of a's prefix
    for (int j = 0; j <= m; ++j) d[0][j] = j;   // insert all of b's prefix
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int cost = (a[i - 1] == b[j - 1]) ? 0 : 1;
            d[i][j] = min({d[i - 1][j] + 1,        // delete
                           d[i][j - 1] + 1,        // insert
                           d[i - 1][j - 1] + cost} // substitute / match
            );
        }
    }
    return d[n][m];
}

// 13.2 — nearest word; ties broken by the alphabetically smaller word.
string closestWord(const vector<string>& dict, const string& query) {
    string best;
    int bestDist = -1;
    for (const string& w : dict) {
        int dd = editDistance(w, query);
        if (bestDist == -1 || dd < bestDist || (dd == bestDist && w < best)) {
            bestDist = dd;
            best = w;
        }
    }
    return best;
}

// 13.3 — every word within maxDist, sorted by (distance, then word).
vector<string> suggestions(const vector<string>& dict, const string& query, int maxDist) {
    vector<pair<int, string>> hits;
    for (const string& w : dict) {
        int dd = editDistance(w, query);
        if (dd <= maxDist) hits.push_back({dd, w});
    }
    sort(hits.begin(), hits.end(),
         [](const pair<int, string>& a, const pair<int, string>& b) {
             return a.first != b.first ? a.first < b.first : a.second < b.second;
         });
    vector<string> out;
    for (const auto& p : hits) out.push_back(p.second);
    return out;
}

// ----------------------------------------------------------------
int main() {
    cout << "===== SOLUTION 13 =====\n";

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
    return 0;
}
