// ============================================================
//  Lesson 2 — std::string : text as an object  ★ SOLUTION ★
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
#include <sstream>
#include <vector>
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
// Key idea: append s once per iteration; loop body never runs when n<=0.
string repeat(const string& s, int n) {
    string result = "";
    for (int i = 0; i < n; i++) {
        result += s;
    }
    return result;
}

// Exercise 2.2
// Count how many times the character c appears in s.
// countLetter("banana", 'a') -> 3.
// Key idea: a bool comparison converts to 0/1, so summing (ch==c) counts hits.
int countLetter(const string& s, char c) {
    int count = 0;
    for (char ch : s) count += (ch == c);

    return count;
}

// Exercise 2.3
// Return an UPPERCASE copy of s.  shout("Yes!") -> "YES!".
// Hint: toupper(c) returns the uppercase version of a char.
//       (Non-letters like '!' are left unchanged by toupper.)
// Key idea: map each char through toupper, casting the int result back to char.
string shout(const string& s) {
    string result = "";
    for (char c : s) {
        result += (char)toupper((unsigned char)c);
    }
    return result;
}

// ================================================================
//  GOING FURTHER 🔥   (for when the warm-up felt too easy)
// ================================================================
//  These two go past "count and glue". You'll be pulling a
//  sentence apart into words and putting it back together.
//
//  Handy new tool — istringstream lets you read a string word by
//  word, the same way cin reads input:
//
//      istringstream iss(text);
//      string word;
//      while (iss >> word) { ...one word at a time... }
//
//  The >> operator skips over the spaces for you, so each `word`
//  is a clean chunk with no blanks attached. 👍
// ----------------------------------------------------------------

// ---- Exercise 2.4 ----------------------------------------------
// Reverse the ORDER of the words in a sentence (not the letters).
// The result has exactly one space between words and no space at
// the ends.
//     reverseWords("the quick brown fox") -> "fox brown quick the"
//     reverseWords("hello world")         -> "world hello"
// Key idea: collect words via istringstream, then join back-to-front,
//           adding a separating space before every word except the first.
string reverseWords(const string& s) {
    istringstream iss(s);
    vector<string> words;
    string word;
    while (iss >> word) words.push_back(word);

    string result = "";
    for (size_t i = words.size(); i-- > 0;) {
        if (!result.empty()) result += " ";
        result += words[i];
    }
    return result;
}

// ---- Exercise 2.5 ----------------------------------------------
// Return the LONGEST word in a sentence. If several words tie for
// longest, return the FIRST one of them.
//     longestWord("the quick brown fox jumps") -> "quick"
//       (quick/brown/jumps are all 5 letters; quick comes first)
//     longestWord("I love programming")        -> "programming"
// Key idea: track best-so-far, replacing only on a STRICTLY longer word
//           so earlier ties keep the earlier winner.
string longestWord(const string& s) {
    istringstream iss(s);
    string word, best = "";
    while (iss >> word) {
        if (word.length() > best.length()) best = word;
    }
    return best;
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

    cout << "\n===== GOING FURTHER =====\n";
    check("2.4 reverseWords(\"the quick brown fox\") == \"fox brown quick the\"",
          reverseWords("the quick brown fox") == "fox brown quick the");
    check("2.4 reverseWords(\"hello world\") == \"world hello\"",
          reverseWords("hello world") == "world hello");
    check("2.5 longestWord(\"the quick brown fox jumps\") == \"quick\"",
          longestWord("the quick brown fox jumps") == "quick");
    check("2.5 longestWord(\"I love programming\") == \"programming\"",
          longestWord("I love programming") == "programming");
    return 0;
}
