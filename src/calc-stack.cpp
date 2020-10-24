
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

