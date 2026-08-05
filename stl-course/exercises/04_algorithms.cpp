// ============================================================
//  Lesson 4 — <algorithm> : don't reinvent the wheel
// ============================================================
//
//  Now the payoff. The STL ships dozens of ready-made algorithms
//  that work on ANY container, using the begin()/end() iterators
//  you met in Lesson 3. You almost never write a sort by hand again.
//
//  From <algorithm>:
//      sort(v.begin(), v.end());               // ascending order
//      sort(v.bcegin(), v.end(), greater<int>()); // descending order
//      reverse(v.begin(), v.end());            // flip the order
//      count(v.begin(), v.end(), 7);           // how many 7s?
//      find(v.begin(), v.end(), 7);            // iterator to first 7 (or end())
//      max_element(v.begin(), v.end());        // iterator to the biggest
//      min_element(v.begin(), v.end());        // iterator to the smallest
//
//  From <numeric>:
//      accumulate(v.begin(), v.end(), 0);      // sum, starting from 0
//
//  NOTE: find / max_element / min_element return an ITERATOR.
//  To get the value, dereference it:  *max_element(v.begin(), v.end())
//  To check find() succeeded, compare against v.end():
//      if (find(...) != v.end())  // found it!
//
// ------------------------------------------------------------

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>   // sort, find, count, max_element, ...
#include <numeric>     // accumulate
#include <utility>     // pair, make_pair
using namespace std;

void check(const string& name, bool ok) {
    cout << (ok ? "  [PASS] " : "  [ ?? ] ") << name << "\n";
}

// ----------------------------------------------------------------
//  LEARN
// ----------------------------------------------------------------
void learn() {
    vector<int> v = {5, 2, 9, 2, 7};

    sort(v.begin(), v.end());
    cout << "Sorted: ";
    for (int x : v) cout << x << " ";
    cout << "\n";

    cout << "Biggest: " << *max_element(v.begin(), v.end()) << "\n";
    cout << "Smallest: " << *min_element(v.begin(), v.end()) << "\n";
    cout << "How many 2s: " << count(v.begin(), v.end(), 2) << "\n";
    cout << "Sum: " << accumulate(v.begin(), v.end(), 0) << "\n";

    if (find(v.begin(), v.end(), 9) != v.end())
        cout << "Yes, 9 is in there.\n";
}

// ----------------------------------------------------------------
//  YOUR TURN — use the algorithms above, not hand-written loops
// ----------------------------------------------------------------

bool comp(int a , int b ) {return a >= b; }


// Exercise 4.1
// Return a sorted (ascending) copy of v. Do not change the original.
// Hint: make a copy first, then sort the copy.
vector<int> sortedCopy(vector<int> v) {   // note: taken BY VALUE = already a copy
    sort(v.begin(), v.end()); 
    return v;
}
vector<int> sortedCopyRev(vector<int> v) {   // note: taken BY VALUE = already a copy
    sort(v.begin(), v.end(), greater<int>()); 
    return v;
}



// Exercise 4.2
// Return how many times `target` appears in v. Use std::count.
int howMany(const vector<int>& v, int target) {

    return count_if(v.begin(), v.end(), [target](int x) {return (x == target);});
}


int howManyIf(const vector<int>& v, bool (*pred)(int)) {

    return count_if(v.begin(), v.end(), pred);
}

// Exercise 4.3
// Return the largest value in v using std::max_element.
// (You may assume v is not empty.) Remember to dereference (*).
int largest(const vector<int>& v) {
    // TODO: return the value max_element points at
    return *std::max_element(v.begin(), v.end()); 
}

// Exercise 4.4
// Return the sum of v using std::accumulate (start the sum at 0).
int total(const vector<int>& v) {
    // TODO: return accumulate(v.begin(), v.end(), 0)
    return accumulate(v.begin(), v.end(), 0);
}

// Exercise 4.5
// Return true if `target` is present anywhere in v, using std::find.
bool contains(const vector<int>& v, int target) {
  auto it = std::find(v.begin(), v.end(), target); 
  return it != v.end();
}

// Exercise 4.5.1
// Write a containsIf function that returns true if a test function returns true for any element of v, using std::find_if.
bool containsIf(const vector<int>& v, bool (*pred)(int)) {
    auto it = std::find_if(v.begin(), v.end(), pred); 
    return it != v.end() ;
}

// contains2 
bool containsIf2OrMore(const vector<int>& v, bool (*pred)(int)) {
//   3, -1, 4, 5, -1 , 9 
//     ^    %    ^
    auto losingsanity = std::find_if(v.begin(), v.end(), pred);
    return (losingsanity != v.end()) && (std::find_if(losingsanity + 1, v.end(), pred)!= v.end());
    
    return std::find_if(find_if(v.begin(), v.end(),pred) +1, v.end(), pred) != v.end();
}

// ================================================================
//  GOING FURTHER 🔥  — combine algorithms, not loops
// ================================================================
//
//  These two ask you to reach for slightly fancier tools and
//  chain ideas together. Same rule as before: no hand-written
//  loops — let the STL do the walking. 🚶
//
//  New faces:
//      minmax_element(v.begin(), v.end())
//          returns a std::pair of ITERATORS: {min_it, max_it}
//          in ONE pass. Dereference each to get the values.
//
//      accumulate(v.begin(), v.end(), init, binaryOp)
//          the 4-argument form: instead of just summing, you hand
//          it your own combiner (a lambda!) and a starting value.
//              sum     -> init 0, op  a + b
//              product -> init 1, op  a * b
//
// ----------------------------------------------------------------

// Exercise 4.6
// Return BOTH the smallest and largest value of v as a pair {min, max},
// in a SINGLE pass, using std::minmax_element.
// (You may assume v is not empty.)
//   minMax({4, 1, 9, 2})   -> {1, 9}
//   minMax({5})            -> {5, 5}
//   minMax({-3, -3, 0})    -> {-3, 0}
// Hint: auto p = minmax_element(...);  then return {*p.first, *p.second};
pair<int, int> minMax(const vector<int>& v) {
    // TODO: use minmax_element and dereference both iterators
    return {0, 0};   // placeholder — replace me
}

// Exercise 4.7
// Return the PRODUCT of all elements of v, using std::accumulate with
// a lambda as the combiner. (Empty vector -> 1, the multiplicative identity.)
//   product({2, 3, 4})    -> 24
//   product({5, -1, 2})   -> -10
//   product({})           -> 1
// Hint: accumulate(v.begin(), v.end(), 1, [](int a, int b){ return a * b; });
int product(const vector<int>& v) {
    // TODO: fold the vector down with multiplication, starting from 1
    return -1;   // placeholder — replace me
}

// ----------------------------------------------------------------

int main() {
    cout << "===== LEARN =====\n";
    learn();

    cout << "\n===== YOUR TURN =====\n";
    check("4.1 sortedCopy({3,1,2}) == {1,2,3}",
          sortedCopy({3, 1, 2}) == vector<int>({1, 2, 3}));
    check("4.1.1 sortedCopyRev({3,1,2}) == {3,2,1}",
            sortedCopyRev({3, 1, 2}) == vector<int>({3, 2, 1}));
    check("4.2 howMany({1,2,2,3,2}, 2) == 3", howMany({1, 2, 2, 3, 2}, 2) == 3);
    check("4.2.1 howManyIf({1,2,2,3,2}, [](int x){return (x == 3);}) == 3", howManyIf({1, 2, 2, 3, 2}, [](int x) { return (x == 2);}) == 3);    
    check("4.3 largest({4,11,7}) == 11",       largest({4, 11, 7}) == 11);
    check("4.4 total({10,20,30}) == 60",       total({10, 20, 30}) == 60);
    check("4.5 contains({1,2,3}, 2) == true",  contains({1, 2, 3}, 2) == true);
    check("4.5 contains({1,2,3}, 9) == false", contains({1, 2, 3}, 9) == false);
    check("4.5.1 containsIf({1,2,3}, [](int x){return (x == 2);}) == true", containsIf({1, 2, 3}, [](int x) { return (x == 2); }) == true);

    cout << "\n===== GOING FURTHER =====\n";
    check("4.6 minMax({4,1,9,2}) == {1,9}",  minMax({4, 1, 9, 2}) == make_pair(1, 9));
    check("4.6 minMax({5}) == {5,5}",        minMax({5}) == make_pair(5, 5));
    check("4.6 minMax({-3,-3,0}) == {-3,0}", minMax({-3, -3, 0}) == make_pair(-3, 0));
    check("4.7 product({2,3,4}) == 24",      product({2, 3, 4}) == 24);
    check("4.7 product({5,-1,2}) == -10",    product({5, -1, 2}) == -10);
    check("4.7 product({}) == 1",            product(vector<int>{}) == 1);
    return 0;
}
