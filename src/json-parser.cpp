
#include "json-parser.h"

using json = nlohmann::json;

void read(std::map<std::string, std::queue<std::string>>& custom, const char* file) {
  try {
    std::ifstream ifs(file);
    json jf = json::parse(ifs);
    for (auto& comm : jf.items()) {
      std::queue<std::string> series;
      std::string seriesStr = comm.value();
      
      int pos = seriesStr.find(" "); 
      try {
        while (pos != -1) {
          series.push(seriesStr.substr(0, pos));
          seriesStr = seriesStr.substr(pos + 1);
          pos = seriesStr.find(" ");
        }
        series.push(seriesStr);
      } catch (std::out_of_range& e) {}
 
      custom[comm.key()] = series;
    }
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl; 
  }
}
