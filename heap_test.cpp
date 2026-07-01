// Tests for Heap<T> (heap.h / heap.cpp) and heap_sort (heapsort.h).
//
// Minimal, dependency-free harness: each CHECK records a pass/failure and
// main() prints a summary and returns non-zero if anything failed.
//
//   make test          # via the Makefile target
//   g++ -std=c++20 -Wall -Wextra heap_test.cpp -o heap_test && ./heap_test

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "heap.h"
#include "heap.cpp"
#include "heapsort.h"

static int g_checks = 0;
static int g_failures = 0;

#define CHECK(cond)                                                        \
  do {                                                                     \
    ++g_checks;                                                            \
    if (!(cond)) {                                                         \
      ++g_failures;                                                        \
      std::cout << "  FAIL [" << __LINE__ << "]: " << #cond << "\n";       \
    }                                                                      \
  } while (0)

template <typename T>
static void check_eq(const std::vector<T> &got, const std::vector<T> &want,
                     const char *what) {
  ++g_checks;
  if (got != want) {
    ++g_failures;
    std::cout << "  FAIL: " << what << "\n    got:  ";
    for (const T &x : got) std::cout << x << " ";
    std::cout << "\n    want: ";
    for (const T &x : want) std::cout << x << " ";
    std::cout << "\n";
  }
}

// Sorts a copy with the standard library for use as the expected result.
template <typename T>
static std::vector<T> sorted(std::vector<T> v) {
  std::sort(v.begin(), v.end());
  return v;
}

// ---- heap_sort tests --------------------------------------------------------

static void test_heap_sort() {
  std::cout << "test_heap_sort\n";

  check_eq(heap_sort(std::vector<int>{}), std::vector<int>{}, "empty");
  check_eq(heap_sort(std::vector<int>{42}), std::vector<int>{42}, "single");
  check_eq(heap_sort(std::vector<int>{5, 3, 8, 1, 9, 2, 7, 4, 6, 0}),
           std::vector<int>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, "mixed");
  check_eq(heap_sort(std::vector<int>{1, 2, 3, 4, 5}),
           std::vector<int>{1, 2, 3, 4, 5}, "already sorted");
  check_eq(heap_sort(std::vector<int>{9, 8, 7, 6, 5, 4, 3, 2, 1}),
           std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9}, "reverse sorted");
  check_eq(heap_sort(std::vector<int>{3, 3, 3, 1, 2, 2}),
           std::vector<int>{1, 2, 2, 3, 3, 3}, "duplicates");
  check_eq(heap_sort(std::vector<int>{-3, 5, -1, 0, -10, 7}),
           std::vector<int>{-10, -3, -1, 0, 5, 7}, "negatives");

  // A larger, pseudo-random-ish input compared against std::sort.
  std::vector<int> big;
  int x = 1;
  for (int i = 0; i < 500; ++i) {
    x = (x * 1103515245 + 12345) & 0x7fffffff;  // deterministic LCG
    big.push_back(x % 1000);
  }
  check_eq(heap_sort(big), sorted(big), "large deterministic input");

  // Works for other comparable types too.
  check_eq(heap_sort(std::vector<std::string>{"pear", "apple", "fig", "kiwi"}),
           std::vector<std::string>{"apple", "fig", "kiwi", "pear"}, "strings");
  check_eq(heap_sort(std::vector<double>{2.5, -1.0, 3.14, 0.0}),
           std::vector<double>{-1.0, 0.0, 2.5, 3.14}, "doubles");
}

// ---- Heap direct-API tests --------------------------------------------------

static void test_heap_add_size() {
  std::cout << "test_heap_add_size\n";

  Heap<int> h;
  CHECK(h.size() == 0);
  h.add(10);
  CHECK(h.size() == 1);
  CHECK(h.peek() == 10);
  h.add(5);
  h.add(20);
  CHECK(h.size() == 3);
  CHECK(h.peek() == 5);  // min bubbles to the top
  h.add(1);
  CHECK(h.size() == 4);
  CHECK(h.peek() == 1);
}

static void test_heap_pop_order() {
  std::cout << "test_heap_pop_order\n";

  Heap<int> h;
  for (int v : {5, 3, 8, 1, 9, 2, 7, 4, 6, 0}) h.add(v);
  CHECK(h.size() == 10);

  std::vector<int> out;
  while (h.size() > 0) {
    out.push_back(h.peek());
    h.pop();
  }
  check_eq(out, std::vector<int>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, "pop order");
  CHECK(h.size() == 0);
}

static void test_heap_pop_empty_throws() {
  std::cout << "test_heap_pop_empty_throws\n";

  Heap<int> h;
  bool threw = false;
  try {
    h.pop();
  } catch (const std::out_of_range &) {
    threw = true;
  }
  CHECK(threw);

  // Draining exactly to empty, then one more pop, should throw.
  h.add(1);
  h.add(2);
  h.pop();
  h.pop();
  CHECK(h.size() == 0);
  threw = false;
  try {
    h.pop();
  } catch (const std::out_of_range &) {
    threw = true;
  }
  CHECK(threw);
}

static void test_heap_interleaved() {
  std::cout << "test_heap_interleaved\n";

  // Interleave adds and pops; the minimum present must always be on top.
  Heap<int> h;
  h.add(7);
  h.add(3);
  CHECK(h.peek() == 3);
  h.pop();            // removes 3
  CHECK(h.peek() == 7);
  h.add(5);
  h.add(1);
  CHECK(h.peek() == 1);
  h.pop();            // removes 1
  CHECK(h.peek() == 5);
  h.add(6);
  h.pop();            // removes 5
  CHECK(h.peek() == 6);
  h.pop();            // removes 6
  CHECK(h.peek() == 7);
  CHECK(h.size() == 1);
}

static void test_heap_all_equal() {
  std::cout << "test_heap_all_equal\n";

  Heap<int> h;
  for (int i = 0; i < 6; ++i) h.add(4);
  CHECK(h.size() == 6);
  int count = 0;
  while (h.size() > 0) {
    CHECK(h.peek() == 4);
    h.pop();
    ++count;
  }
  CHECK(count == 6);
}

static void test_heap_iterator() {
  std::cout << "test_heap_iterator\n";

  // Empty heap: begin() == end(), range-for body never runs.
  Heap<int> empty;
  CHECK(empty.begin() == empty.end());
  for ([[maybe_unused]] int x : empty) CHECK(false);

  // The iterator visits every element exactly once. Order is unspecified
  // (heap only guarantees the root is smallest), so we compare the multiset
  // of visited values against the input, sorted.
  std::vector<int> input{5, 3, 8, 1, 9, 2, 7, 4, 6, 0, 3, 3};
  Heap<int> h;
  for (int v : input) h.add(v);

  std::vector<int> visited;
  for (int x : h) visited.push_back(x);          // range-based for
  CHECK(visited.size() == static_cast<std::size_t>(h.size()));
  check_eq(sorted(visited), sorted(input), "iterator visits all elements");

  // The smallest element is the root, i.e. the first one begin() yields.
  CHECK(*h.begin() == 0);

  // Iterating does not modify the heap.
  CHECK(h.size() == static_cast<int>(input.size()));
  CHECK(h.peek() == 0);

  // Manual increment (prefix and postfix) and operator-> behave.
  auto it = h.begin();
  CHECK(*it == 0);
  auto same = it++;
  CHECK(*same == 0);          // postfix returned the pre-increment value
  std::size_t n = 1;          // already consumed the first element
  for (; it != h.end(); ++it) ++n;
  CHECK(n == input.size());

  // cbegin()/cend() work too.
  std::size_t c = 0;
  for (auto i = h.cbegin(); i != h.cend(); ++i) ++c;
  CHECK(c == input.size());
}

int main() {
  test_heap_sort();
  test_heap_add_size();
  test_heap_pop_order();
  test_heap_pop_empty_throws();
  test_heap_interleaved();
  test_heap_all_equal();
  test_heap_iterator();

  std::cout << "\n"
            << (g_checks - g_failures) << "/" << g_checks << " checks passed";
  if (g_failures) {
    std::cout << " -- " << g_failures << " FAILED\n";
    return 1;
  }
  std::cout << " -- all passed\n";
  return 0;
}
