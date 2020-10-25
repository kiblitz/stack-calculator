
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <stack>

#include "calc-stack.h"

int parse(std::stack<double>& stack, 
          std::string val, 
          std::map<std::string, std::queue<std::string>>& custom, 
          bool& defining, 
          std::queue<std::string>& definition,
          int& skip,
          bool stackMode);

void help_print();

