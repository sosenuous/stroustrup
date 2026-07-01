#ifndef __HEAPSORT_H__
#define __HEAPSORT_H__

#include <vector>

#include "heap.h"
#include "heap.cpp"   // template definitions must be visible to instantiate

// Sorts the elements of `v` in ascending order using a min-Heap.
//
// Every element is inserted into the heap, then repeatedly popped: since
// Heap is a min-heap, peek()/pop() yields the elements smallest-first, so
// pushing them back gives an ascending sequence. O(n log n) on average.
template <typename T>
std::vector<T> heap_sort(std::vector<T> const &v) {
  Heap<T> h;
  for (std::size_t i = 0; i < v.size(); ++i)
    h.add(v[i]);

  std::vector<T> result;
  result.reserve(v.size());
  while (h.size() > 0) {
    result.push_back(h.peek());
    h.pop();
  }
  return result;
}

#endif
