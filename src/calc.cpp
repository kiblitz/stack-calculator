
#include <iostream>
#include <sstream>
#include <stack>

#include "parser.h"

int main(int argc, const char* argv[]) {
  for (int i = 1; i < argc; ++i) {
    // Run parsed files on interpreter
  }
  std::stack<double> stack;
 
  std::string input; 
  bool running = true;
  while (running) {
    std::cout << std::endl << "calc >> ";
    std::getline(std::cin, input);
    
    std::istringstream iss(input);
    bool valid = true;
    int skip = 0;
    while (iss && valid) {
      std::string comm;
      iss >> comm;
      if (comm == "") {
        break;
      }
    
      switch(parse(stack, comm, skip)) {
        case 0:
          running = false; 
          valid = false;
          break;
        case -1:
          valid = false; 
          break;
      }
    }
  }
}

