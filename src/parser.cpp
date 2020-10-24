
#include "parser.h"

int parse(std::stack<double>& stack, std::string val) {
  try {
    if (val == "quit") {
      return 0;
    
    } else if (val == "help") {
      std::cout << "help";

    } else if (val == "stack") {
      stack_print(stack);

    } else if (val == "+") {                      // plus
      double b = stack_pop(stack);
      double a = stack_pop(stack);
      stack.push(a + b);

    } else if (val == "-") {                     // minus
      double b = stack_pop(stack);
      double a = stack_pop(stack); 
      stack.push(a - b);

    } else if (val == "*")  {                    // times
      double b = stack_pop(stack);
      double a = stack_pop(stack);
      stack.push(a * b);

    } else if (val == "/") {                    // divide
      double b = stack_pop(stack);
      if (b == 0) {
        throw std::runtime_error("Divide by zero error");
      }
      double a = stack_pop(stack);
      stack.push(a / b);

    } else if (val == "//") {               // int divide
      double b = stack_pop(stack);
      if (b == 0) {
        throw std::runtime_error("Divide by zero error");
      }
      double a = stack_pop(stack);
      stack.push(std::floor(a / b));

    } else if (val == "%") {                      // mod
      double b = stack_pop(stack);
      if (b == 0) {
        throw std::runtime_error("Divide by zero error");
      }
      double a = stack_pop(stack);
      if (b > a) {
        stack.push(a);
      } else {
        stack.push(a - std::floor(a / b) * b);
      }

    } else if (val == "^") {                  // exponent
      double b = stack_pop(stack);
      double a = stack_pop(stack);
      stack.push(std::pow(a, b)); 

    } else if (val == "e") {                       // exp
      stack.push(exp(1)); 

    } else if (val == "pi") {                       // pi
      stack.push(2 * std::acos(0));

    } else {
      try {
        double num = std::stod(val);
        stack.push(num);
      } catch (...) {
        throw std::runtime_error("Unrecognized token");
      }
    }
  } catch (std::exception& e) {
    std::cout << e.what();
    return -1;
  }
  // Parse different commands
  return 1;
}

