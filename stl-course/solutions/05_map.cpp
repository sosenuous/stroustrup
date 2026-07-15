// ============================================================
//  Lesson 5 — std::pair & std::map   *** SOLUTION ***
// ============================================================
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

void check(const string& name, bool ok) {
    cout << (ok ? "  [PASS] " : "  [ ?? ] ") << name << "\n";
}

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

// Exercise 5.1
map<string, int> wordLengths(const vector<string>& words) {
    map<string, int> result;
    for (const string& w : words)
        result[w] = w.length();
    return result;
}

// Exercise 5.2
int lookupOr(const map<string, int>& m, const string& key, int fallback) {
    if (m.count(key))
        return m.at(key);
    return fallback;
}

// Exercise 5.3
map<char, int> charFrequency(const string& s) {
    map<char, int> freq;
    for (char c : s)
        freq[c]++;
    return freq;
}

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
    return 0;
}
