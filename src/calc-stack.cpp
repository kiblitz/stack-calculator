
#include "calc-stack.h"

void stack_pop_nore(std::stack<double>& stack) {
  if (stack.empty()) {
    throw std::runtime_error("Not enough tokens in stack");
  }
  stack.pop();
}

double stack_pop(std::stack<double>& stack) {
  if (stack.empty()) {
    throw std::runtime_error("Not enough tokens in stack");
  }
  double val = stack.top();
  stack.pop();
  return val;
}

void stack_print(std::stack<double>& stack) {
  std::stack<double> temp;
  while (!stack.empty()) {
    temp.push(stack.top());
    stack.pop(); 
  }

  while (!temp.empty()) {
    double val = temp.top();
    stack.push(val);
    std::cout << val << " ";
    temp.pop(); 
  }
}

double stack_pick(std::stack<double>& stack, int pos) {
  std::stack<double> temp;
  for (int i = 0; i < pos; ++i) {
    if (stack.empty()) {
      while (!temp.empty()) {
        stack.push(temp.top());
        temp.pop();
      } 
      throw std::runtime_error("Not enough tokens in stack");
    }
    temp.push(stack.top());
    stack.pop();
  }
  double val = temp.top();

  while (!temp.empty()) {
    stack.push(temp.top()); 
    temp.pop();
  }
  return val;
}
