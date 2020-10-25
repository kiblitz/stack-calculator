
#include <fstream>
#include <iostream>
#include <map>
#include <queue>

#include <nlohmann/json.hpp>

void read(std::map<std::string, std::queue<std::string>>& custom, const char* file);
