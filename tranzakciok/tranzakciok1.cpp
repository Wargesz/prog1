#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Tranzakcio {
      int id;
      string items;
};

void operator>>(string s, struct Tranzakcio& t) {
      t.id = stoi(s.substr(0,s.find(" ")));
      t.items = s.substr(s.find(" ")+1,s.length()-1);
}

int main() {

      vector<struct Tranzakcio> tranzakciok;
      struct Tranzakcio t;
      ifstream in("tranzakciok.dat");
      string s;
      while (!in.eof()) {
            getline(in,s);
            s>>t;
            tranzakciok.push_back(t);
      }
      in.close();
      //tej 0 kenyer 1 chips 2
      int itemCount[3] = {0};
      string items[3] = {"Tej","Kenyer","Chips"};
      for (struct Tranzakcio t : tranzakciok) {
            for (int i = 0; i < 3; i++) {
                  if (t.items.find(items[i]) != string::npos) {
                        itemCount[i]++;
                  }
            }
      }
      for (int i = 0; i < 3; i++) {
            cout<<items[i]<<": "<<(float)itemCount[i]/(float)tranzakciok.size()<<endl;
      }
      return 0;
}