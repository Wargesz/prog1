#include <iostream>
#include <fstream>
int main() {
      std::string line,out = "";
      int salt = 17;
      std::ifstream source("lipsum.txt");
      while (getline(source,line)) {
            for (char c : line) {
                  out+=c+salt*2;
            }
      }
      source.close();
      std::ofstream output("encrypted.txt");
      output<<out;
      output.close();
      return 0;
}
