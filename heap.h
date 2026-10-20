#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <cstddef>
#include <utility>


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
  std::vector<T> items;
  int arity;
  PComparator comp;



};

// Add implementation of member functions here

template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) : arity(m), comp(c){
  if(m < 2){
    throw std::invalid_argument("Heap arity must be at least 2");
  }
}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap()
{
}
template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const{
  return items.empty();
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const{
  return items.size();
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item){
  //add the new item at the end of the vector
  items.push_back(item);

  //get the index of the new item
  size_t current = items.size() - 1;

  //move the item upward until the heap property is satisfied
  while(current > 0){
    size_t parent = (current -1)/arity;

    //if the current item has higher priority, swap
    if(comp(items[current], items[parent])){
      std::swap(items[current], items[parent]);
      current = parent;
    }else{
      break;
    }
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

    throw std::underflow_error("Heap is empty");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element

  return items[0];

}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  //check is the heap is empty
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================

    throw std::underflow_error("Heap is empty");
  }

  //move the last element to the root
  items[0] = items.back();
  items.pop_back();

  //start bubbling down from the root
  size_t current = 0;

  while(current < items.size()){
    size_t best = current;

    //check all children of the current node
    for(int i = 1; i <= arity; i++){
      size_t child = current * arity + i;
      if(child < items.size() && comp(items[child], items[best])){
        best = child;
      }
    }

    //if current already has highest priority, stop
    if(best == current){
      break;
    }

    //oterwise, swap with the highest-priority child
    std::swap(items[current], items[best]);
    current = best;

  }

}



#endif

