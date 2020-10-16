#include <iostream>
#include <sstream>
#include <stack>

bool parse(std::stack<double> stack, std::string val);

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
    while (iss && running) {
      std::string comm;
      iss >> comm;
      
      running = parse(stack, comm);
    }
  }
}

bool parse(std::stack<double> stack, std::string val) {
  if (val == "quit") {
    return false;
  }
  // Parse different commands
  return true;
}
