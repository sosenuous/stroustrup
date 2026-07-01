#ifndef __HEAP_H__
#define __HEAP_H__

#include <cstddef>
#include <iterator>
#include <stack>

#include "structures.h"

template <typename T>
class Heap : public Container<T> {

  T data;
  Heap<T>* left;
  Heap<T>* right;

public:
  Heap() : Container<T>(0), left(nullptr), right(nullptr) {}
  Heap(T d) : Container<T>(1), data(d), left(nullptr), right(nullptr) {}
  virtual ~Heap();

  virtual T &operator[](int i) const;

  void add(T); // adds a new element
  void pop() ;    // removes the top element
  T peek() const {
    return data;
  }

  // Read-only forward iterator over every element in the heap.
  //
  // Visits all size() elements via a pre-order tree walk. NOTE: the order is
  // NOT sorted -- a heap only guarantees the root is the minimum. Use pop()
  // or heap_sort() when you need elements in order. Const because mutating an
  // element in place would break the heap invariant.
  class const_iterator {
  public:
    using iterator_category = std::forward_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = const T*;
    using reference = const T&;

    const_iterator() = default;                    // end sentinel (cur == nullptr)
    explicit const_iterator(const Heap<T>* root) {
      if (root && root->size() > 0) pending.push(root);
      advance();
    }

    reference operator*() const { return cur->data; }
    pointer operator->() const { return &cur->data; }

    const_iterator& operator++() { advance(); return *this; }
    const_iterator operator++(int) { const_iterator tmp = *this; advance(); return tmp; }

    bool operator==(const const_iterator& o) const { return cur == o.cur; }
    bool operator!=(const const_iterator& o) const { return cur != o.cur; }

  private:
    const Heap<T>* cur = nullptr;
    std::stack<const Heap<T>*> pending;

    void advance() {
      if (pending.empty()) { cur = nullptr; return; }
      cur = pending.top();
      pending.pop();
      // push right then left so the left subtree is visited first
      if (cur->right && cur->right->size() > 0) pending.push(cur->right);
      if (cur->left && cur->left->size() > 0) pending.push(cur->left);
    }
  };

  const_iterator begin() const { return const_iterator(this); }
  const_iterator end() const { return const_iterator(); }
  const_iterator cbegin() const { return begin(); }
  const_iterator cend() const { return end(); }

private:


void add_to_children(T value) ;

};






#endif