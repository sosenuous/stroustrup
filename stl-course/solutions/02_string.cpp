// ============================================================
//  Lesson 2 — std::string   *** SOLUTION ***
// ============================================================
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void check(const string& name, bool ok) {
    cout << (ok ? "  [PASS] " : "  [ ?? ] ") << name << "\n";
}

void learn() {
    string name = "Ada";
    string greeting = "Hello, " + name + "!";
    cout << greeting << " (" << greeting.length() << " chars)\n";

    cout << "Spelled out: ";
    for (char c : name)
        cout << c << " ";
    cout << "\n";

    string phrase = "banana bread";
    cout << "First 6 chars: " << phrase.substr(0, 6) << "\n";
    cout << "'bread' starts at index " << phrase.find("bread") << "\n";
}

// Exercise 2.1
string repeat(const string& s, int n) {
    string result = "";
    for (int i = 0; i < n; ++i)
        result += s;
    return result;
}

// Exercise 2.2
int countLetter(const string& s, char c) {
    int count = 0;
    for (char ch : s)
        if (ch == c)
            ++count;
    return count;
}

// Exercise 2.3
string shout(const string& s) {
    string result = "";
    for (char c : s)
        result += (char)toupper(c);
    return result;
}

int main() {
    cout << "===== LEARN =====\n";
    learn();

    cout << "\n===== YOUR TURN =====\n";
    check("2.1 repeat(\"ab\", 3) == \"ababab\"", repeat("ab", 3) == "ababab");
    check("2.1 repeat(\"x\", 0) == \"\"",        repeat("x", 0) == "");
    check("2.2 countLetter(\"banana\",'a') == 3", countLetter("banana", 'a') == 3);
    check("2.2 countLetter(\"banana\",'z') == 0", countLetter("banana", 'z') == 0);
    check("2.3 shout(\"Yes!\") == \"YES!\"",      shout("Yes!") == "YES!");
    return 0;
}
