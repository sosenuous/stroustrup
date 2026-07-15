// ============================================================
//  Lesson 11 — CLOSURES : lambdas that remember 🧠
// ============================================================
//
//  In lesson 8 a lambda was a tiny throwaway rule. Now we make lambdas
//  that CARRY STATE around with them. A lambda plus the variables it
//  captured is called a CLOSURE. Once you can build closures, you can
//  build functions that build *other* functions — a big step up.
//
//  Four new powers in this lesson:
//
//  1) A lambda can RETURN from a function and keep its captures alive:
//         auto makeAdder(int n) {
//             return [n](int x) { return x + n; };   // remembers n
//         }
//         auto add10 = makeAdder(10);
//         add10(5);   // 15
//     This is a "function factory": call it and you get a custom function.
//
//  2) `mutable` lets a lambda CHANGE its own captured copy between calls,
//     so it can keep a private counter:
//         auto tick = [n = 0]() mutable { return ++n; };
//         tick();  // 1
//         tick();  // 2   <- it remembered!
//
//  3) std::function<Ret(Args)> is a box that can hold ANY callable with
//     that signature — a lambda, a function pointer, whatever. You need it
//     when you want to STORE a closure in a variable, a vector, or return
//     it with a written-out type (from <functional>):
//         std::function<int(int)> f = makeAdder(3);
//
//  4) A lambda can even call ITSELF (recursion) if it captures a
//     std::function by reference that refers to itself:
//         function<int(int)> fac = [&](int k){ return k<=1 ? 1 : k*fac(k-1); };
//
//  Capture cheat-sheet:
//      [x]    copy of x      [&x]   reference to x
//      [=]    copy of all    [&]    reference to all
//      [n=0]  make a fresh captured variable called n
//
// ------------------------------------------------------------

#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

void check(const string& name, bool ok) {
    cout << (ok ? "  [PASS] " : "  [ ?? ] ") << name << "\n";
}

// ----------------------------------------------------------------
//  LEARN
// ----------------------------------------------------------------
void learn() {
    // (1) Function factory: makeAdder returns a closure over n.
    auto makeAdder = [](int n) {
        return [n](int x) { return x + n; };
    };
    auto add10 = makeAdder(10);
    cout << "add10(5) = " << add10(5) << "\n";          // 15
    cout << "makeAdder(100)(1) = " << makeAdder(100)(1) << "\n"; // 101

    // (2) A mutable lambda with its own private counter.
    auto tick = [count = 0]() mutable { return ++count; };
    cout << "tick,tick,tick = " << tick() << tick() << tick() << "\n"; // 123

    // (3) Storing closures in std::function, even in a vector of them.
    vector<function<int(int)>> pipeline = {
        [](int x) { return x + 1; },
        [](int x) { return x * 2; },
    };
    int val = 5;
    for (auto& step : pipeline) val = step(val);        // (5+1)*2 = 12
    cout << "pipeline(5) = " << val << "\n";

    // (4) A recursive lambda via std::function.
    function<int(int)> fac = [&](int k) { return k <= 1 ? 1 : k * fac(k - 1); };
    cout << "fac(5) = " << fac(5) << "\n";               // 120
}

// ----------------------------------------------------------------
//  YOUR TURN — build closures
// ----------------------------------------------------------------

// Exercise 11.1 — Function factory
// Return a closure that multiplies its argument by `factor`.
//   makeMultiplier(3)(4) == 12
//   makeMultiplier(0)(9) ==  0
// Hint: capture factor by copy and return a lambda taking one int.
function<int(int)> makeMultiplier(int factor) {
    // TODO: return [factor](int x){ return ...; };
    return [](int) { return 0; };
}

// Exercise 11.2 — A counter with memory
// Return a callable that yields 1 the first time it's called, 2 the next
// time, 3 after that, and so on. Each counter returned is INDEPENDENT.
//   auto c = makeCounter();  c()==1; c()==2; c()==3;
// Hint: a mutable lambda that captures its own count starting at 0.
function<int()> makeCounter() {
    // TODO: return [n = 0]() mutable { return ...; };
    return []() { return 0; };
}

// Exercise 11.3 — Running (prefix) sums
// Return a vector where element i is the sum of v[0..i].
//   runningTotals({1,2,3,4}) == {1,3,6,10}
//   runningTotals({})        == {}
// Hint: keep a running sum in a variable and, for each element, add it and
//       push the new total. A lambda capturing the sum BY REFERENCE [&sum]
//       is a clean way to do this (e.g. with std::transform or a loop).
vector<int> runningTotals(const vector<int>& v) {
    // TODO
    return {};
}

// Exercise 11.4 — Compose two functions
// Return a closure h such that h(x) == f(g(x)).  (g runs first, then f.)
//   auto addOne   = [](int x){ return x + 1; };
//   auto timesTwo = [](int x){ return x * 2; };
//   compose(addOne, timesTwo)(5) == 11   // (5*2) then +1
//   compose(timesTwo, addOne)(5) == 12   // (5+1) then *2
// Hint: capture f and g, return a lambda that calls g then f.
function<int(int)> compose(function<int(int)> f, function<int(int)> g) {
    // TODO: return [f, g](int x){ return ...; };
    return [](int x) { return x; };
}

// Exercise 11.5 — Recursive lambda: Fibonacci
// Return the n-th Fibonacci number, 0-indexed: 0,1,1,2,3,5,8,13,...
//   fib(0)==0  fib(1)==1  fib(7)==13  fib(10)==55
// Hint: inside the function, declare
//         function<int(int)> f = [&](int k){ ... f(k-1) ... f(k-2) ... };
//       then return f(n). (Slow but that's fine — it's about closures.)
int fib(int n) {
    // TODO
    return -1;
}

// ----------------------------------------------------------------
int main() {
    cout << "===== LEARN =====\n";
    learn();

    cout << "\n===== YOUR TURN =====\n";

    check("11.1 makeMultiplier(3)(4) == 12", makeMultiplier(3)(4) == 12);
    check("11.1 makeMultiplier(0)(9) == 0",  makeMultiplier(0)(9) == 0);

    auto c1 = makeCounter();
    check("11.2 counter yields 1,2,3", c1() == 1 && c1() == 2 && c1() == 3);
    auto c2 = makeCounter();  // must be independent of c1
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
