// ============================================================
//  Lesson 2 — std::string : text as an object
// ============================================================
//
//  In C, text is a bare array of chars that you manage by hand.
//  In C++, std::string does the work for you. It behaves a lot
//  like a vector<char> with extra text-friendly powers.
//
//  Key moves:
//      string s = "hello";
//      s.length()   or  s.size();   // number of characters
//      s[0]                          // the character 'h' (index 0)
//      s += " world";                // glue text onto the end
//      s + "!"                       // make a new joined string
//      s.substr(1, 3)                // 3 chars starting at index 1 -> "ell"
//      s.find('l')                   // index of first 'l' (here: 2)
//
//  A string is loopable just like a vector:
//      for (char c : s) { ... }
//
//  Bonus: <cctype> gives you toupper(c) / tolower(c) for single chars.
//
// ------------------------------------------------------------

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void check(const string& name, bool ok) {
    cout << (ok ? "  [PASS] " : "  [ ?? ] ") << name << "\n";
}

// ----------------------------------------------------------------
//  LEARN
// ----------------------------------------------------------------
void learn() {
    string name = "Ada";
    string greeting = "Hello, " + name + "!";
    cout << greeting << " (" << greeting.length() << " chars)\n";

    // Walk through every character:
    cout << "Spelled out: ";
    for (char c : name)
        cout << c << " ";
    cout << "\n";

    // substr and find:
    string phrase = "banana bread";
    cout << "First 6 chars: " << phrase.substr(0, 6) << "\n";
    cout << "'bread' starts at index " << phrase.find("bread") << "\n";
}

// ----------------------------------------------------------------
//  YOUR TURN
// ----------------------------------------------------------------

// Exercise 2.1
// Return s repeated n times. repeat("ab", 3) -> "ababab".
// (If n <= 0, return the empty string "".)
string repeat(const string& s, int n) {
    string result = "";
    for (int i = 0; i < n; i++) { 
        result +=s; 
    }// TODO: glue s onto result n times (hint: result += s;)
    return result;
}

// Exercise 2.2
// Count how many times the character c appears in s.
// countLetter("banana", 'a') -> 3.
int countLetter(const string& s, char c) {
    int count = 0;
    for (char ch : s) count += (ch == c) ;

    return count;
}

// Exercise 2.3
// Return an UPPERCASE copy of s.  shout("Yes!") -> "YES!".
// Hint: toupper(c) returns the uppercase version of a char.
//       (Non-letters like '!' are left unchanged by toupper.)
string shout(const string& s) {
    string result = "";
    for (char c : s) { 
        result += (char)toupper(c);
    }
    return result;
}

// ----------------------------------------------------------------
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
