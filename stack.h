#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>
#include <cstddef>

// Stack inherits privately from std::vector
template <typename T>
class Stack : private std::vector<T>
{
public:
  // Constructor
  Stack() : std::vector<T>() {}

  // Destructor
   ~Stack() {}

  // Check if stack is empty
  bool empty() const{
    return std::vector<T>::empty();
  }

  // Return number of elements
  size_t size() const{
    return std::vector<T>::size();
  }

  // Add an item to the top
  void push(const T& item){
    this->push_back(item);
  }

  // Remove the top item
  void pop(){
    if(empty()){
      throw std::underflow_error("Stack is empty");
    }
    this->pop_back();
  }

  // Return the top item without removing it
  const T& top() const{
    if(empty()){
      throw std::underflow_error("Stack is empty");
    }
    return this->back();
  }
};

#endif
