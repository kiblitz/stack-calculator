
#include "parser.h"

int parse(std::stack<double>& stack, 
          std::string val, 
          std::map<std::string, std::queue<std::string>>& custom, 
          bool& defining, 
          std::queue<std::string>& definition, 
          int& skip,
          bool stackMode) {

  // global functions
  if (val == "quit") {
    return 0;
  } else if (val == "help") {
    std::cout << "help";
    return 1;
  } else if (val == "stack") {
    stack_print(stack);
    return 1;
  }

  // when defining
  if (defining) {
    if (val == ";") {
      defining = false;
      if (!definition.empty()) {
        std::string comm = definition.front(); 
        definition.pop();
        custom[comm] = std::queue<std::string>(definition);
        definition = std::queue<std::string>();
      }
      return 1;
    }
    definition.push(val);
    return 1;
  } else {
    if (val == ":") {
      defining = true;
      return 1;
    }
  }  

  // skip tokens
  if (skip > 0) {
    --skip;
    return 1;
  }

  // parser
  try {
    if (val == "noop") {                          // noop
      return 1;
    
    } else if (val == "clear") {                 // clear
      while (!stack.empty()) {
        stack_pop_nore(stack);
      }   

    } else if (val == "pop") {                     // pop 
      stack_pop_nore(stack);

    } else if (val == "popn") {                   // popn
      double a = stack_pop(stack);
      for (int i = 0; i < std::floor(a); ++i) {
        stack_pop_nore(stack);
      }

    } else if (val == "skip") {                   // skip
      int a = (int)stack_pop(stack);
      skip = a;

    } else if (val == "pick") {                   // pick
      int a = (int)stack_pop(stack);
      double n = stack_pick(stack, a);
      stack.push(n);

    } else if (val == "swap") {
      double b = stack_pop(stack);
      double a = stack_pop(stack); 
      stack.push(b);
      stack.push(a);

    } else if (val == "if") {                       // if
      double a = stack_pop(stack);
      if (a == 0) {
        skip = 3; 
      }

    } else if (val == ">") {                   // greater
      double b = stack_pop(stack);
      double a = stack_pop(stack);
      if (a > b) {
        stack.push(1);
      } else {
        stack.push(0);
      }

    } else if (val == "<") {                      // less
      double b = stack_pop(stack);
      double a = stack_pop(stack);
      if (a < b) {
        stack.push(1);
      } else {
        stack.push(0);
      }

    } else if (val == "=") {                     // equal
      double b = stack_pop(stack);
      double a = stack_pop(stack);
      if (a == b) {
        stack.push(1);
      } else {
        stack.push(0);
      }

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

    } else if (val == "ln") {                     // log 
      double a = stack_pop(stack);
      if (a <= 0) {
        throw std::runtime_error("Log of non-positive value error");
      }
      stack.push(std::log(a));
    
    } else if (val == "sin") {                     // sin
      double a = stack_pop(stack);
      stack.push(std::sin(a));
    
    } else if (val == "arcsin") {               // arcsin
      double a = stack_pop(stack);
      if (a < -1 || a > 1) {
        throw std::runtime_error("Arcsin undefined for value error");
      }
      stack.push(std::asin(a));
    
    } else if (val == "cos") {                     // cos
      double a = stack_pop(stack);
      stack.push(std::cos(a));
       
    } else if (val == "arccos") {               // arccos
      double a = stack_pop(stack);
      if (a < -1 || a > 1) {
        throw std::runtime_error("Arccos undefined for value error");
      }
      stack.push(std::acos(a));
    
    } else if (val == "tan") {                     // tan
      double a = stack_pop(stack);
      if (std::cos(a) == 0) {
        throw std::runtime_error("Tan undefined for value error");
      }
      stack.push(std::tan(a));
       
    } else if (val == "arctan") {               // arctan
      double a = stack_pop(stack);
      stack.push(std::atan(a));

    } else if (custom.count(val) != 0) {
      std::queue<std::string> series(custom[val]);
      while (!series.empty()) {
        std::string next = series.front();
        series.pop();
        bool sm = stackMode;
        if (series.empty()) {
          sm = false;
        }
        int code = parse(stack, next, custom, defining, definition, skip, sm);
        if (code != 1) {
          return code;
        } 
      }

    } else {
      try {
        double num = std::stod(val);
        stack.push(num);
      } catch (...) {
        throw std::runtime_error("Unrecognized token");
      }
    }
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
    return -1;
  }
  if (stackMode) {
    stack_print(stack);
  }
  return 1;
}

