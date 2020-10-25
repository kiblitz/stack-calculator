
#include "calc.h"

int main(int argc, const char* argv[]) {
  bool stackMode = false;
  std::map<std::string, std::queue<std::string>> custom;
  for (int i = 1; i < argc; ++i) {
    if (std::strcmp(argv[i], "--stack") == 0) {
      stackMode = true;
    } else {
      read(custom, argv[i]);
    }
  }
 
  std::stack<double> stack;
  std::queue<std::string> definition;
  std::string input; 
  bool running = true;
  int skip = 0;
  bool defining = false;

  // interpreter
  while (running) {
    std::cout << std::endl << "calc >> ";
    std::getline(std::cin, input);
    
    std::istringstream iss(input);
    bool valid = true;
    while (iss && valid) {
      std::string comm;
      iss >> comm;
      if (comm == "") {
        break;
      }
    
      switch(parse(stack, comm, custom, defining, definition, skip, stackMode)) {
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

