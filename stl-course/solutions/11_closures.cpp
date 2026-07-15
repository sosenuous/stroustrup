// ============================================================
//  Lesson 11 — CLOSURES  ★ SOLUTION ★
// ============================================================
//  Worked answers. Try the exercise version first — struggling is how the
//  learning sticks. This file should compile and print [PASS] everywhere.
// ------------------------------------------------------------

#include <iostream>
#include <string>
#include <vector>
#include <functional>
using namespace std;

void check(const string& name, bool ok) {
    cout << (ok ? "  [PASS] " : "  [ ?? ] ") << name << "\n";
}

// 11.1 — Function factory: capture factor by copy, return a closure.
function<int(int)> makeMultiplier(int factor) {
    return [factor](int x) { return x * factor; };
}

// 11.2 — A mutable lambda keeps its own private count between calls.
function<int()> makeCounter() {
    return [n = 0]() mutable { return ++n; };
}

// 11.3 — Prefix sums: a lambda capturing the running total BY REFERENCE.
vector<int> runningTotals(const vector<int>& v) {
    vector<int> out;
    out.reserve(v.size());
    int sum = 0;
    for (int x : v) {
        sum += x;
        out.push_back(sum);
    }
    return out;
}

// 11.4 — Compose: run g first, then feed its result to f.
function<int(int)> compose(function<int(int)> f, function<int(int)> g) {
    return [f, g](int x) { return f(g(x)); };
}

// 11.5 — Recursive lambda via a std::function it captures by reference.
int fib(int n) {
    function<int(int)> f = [&](int k) { return k < 2 ? k : f(k - 1) + f(k - 2); };
    return f(n);
}

// ----------------------------------------------------------------
int main() {
    cout << "===== SOLUTION 11 =====\n";

    check("11.1 makeMultiplier(3)(4) == 12", makeMultiplier(3)(4) == 12);
    check("11.1 makeMultiplier(0)(9) == 0",  makeMultiplier(0)(9) == 0);

    auto c1 = makeCounter();
    check("11.2 counter yields 1,2,3", c1() == 1 && c1() == 2 && c1() == 3);
    auto c2 = makeCounter();
    check("11.2 a fresh counter restarts at 1", c2() == 1);

    check("11.3 runningTotals({1,2,3,4}) == {1,3,6,10}",
          runningTotals({1, 2, 3, 4}) == vector<int>({1, 3, 6, 10}));
    check("11.3 runningTotals({}) == {}",
          runningTotals({}) == vector<int>({}));

    auto addOne   = function<int(int)>([](int x) { return x + 1; });
    auto timesTwo = function<int(int)>([](int x) { return x * 2; });
    check("11.4 compose(addOne, timesTwo)(5) == 11", compose(addOne, timesTwo)(5) == 11);
    check("11.4 compose(timesTwo, addOne)(5) == 12", compose(timesTwo, addOne)(5) == 12);

    check("11.5 fib(0) == 0",  fib(0) == 0);
    check("11.5 fib(7) == 13", fib(7) == 13);
    check("11.5 fib(10) == 55", fib(10) == 55);
    return 0;
}
