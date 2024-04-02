#include <iostream>
#include <fstream>
int main() {
      std::string line,out = "";
      int salt = 17;
      std::ifstream source("lipsum.txt");
      while (getline(source,line)) {
            for (char c : line) {
                  out+=c+salt;
                  salt+=7;
            }
      }
      source.close();

      std::ofstream output("out.txt");
      std::string reverse = "";
      salt = 17;
      for (char c : out) {
            output<<(char)(c-salt);
            salt+=7;
      }
      output.close();
      return 0;
}
