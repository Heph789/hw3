#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <iostream>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> underlying;
  int mary;
  PComparator isbetterthan;

  int getparent(int c) const;
  int bestchild(int p) const;
  void trickledown(int i);
};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c) : mary(m), isbetterthan(c)
{

}

template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap()
{

}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const
{
  return underlying.size();
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const
{
  return size() == 0;
}

template <typename T, typename PComparator>
int Heap<T,PComparator>::getparent(int c) const
{
  return (c+1 + mary-2)/mary - 1;
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item)
{
  int curr = underlying.size();
  underlying.push_back(item);
  int p = getparent(curr);
  while (curr > 0 && isbetterthan(item, underlying[p]))
  {
    underlying[curr] = underlying[p];
    underlying[p] = item;
    curr = p;
    p = getparent(curr);
  }
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("No elements in heap.");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return underlying[0];
}

// returns best child, or -1 if parent has no children or parent is better than children
template <typename T, typename PComparator>
int Heap<T,PComparator>::bestchild(int p) const
{
  size_t best = (p+1) * mary - (mary-2) - 1; // parent's first child
  if (best >= size()) return -1; // return -1 if parent has no child

  int i = 0;
  int j = 1;
  while (best+j < size() && i < mary)
  {
    if (isbetterthan(underlying[best], underlying[best+j]))
    {
      ++j;
    }
    else
    {
      best = best+j;
      j = 1;
    }
    ++i;
  }
  
  if (isbetterthan(underlying[best], underlying[p])) return best; 
  return -1;
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::trickledown(int i)
{
  int bc;
  while ((bc = bestchild(i)) > 0)
  {
    T temp = underlying[bc];
    underlying[bc] = underlying[i];
    underlying[i] = temp;
    i = bc;
  }
}

// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("No elements in heap.");
  }
  underlying[0] = underlying[size()-1];
  underlying.pop_back();
  if(size() > 1)
  {
    trickledown(0);
  }
}

#endif