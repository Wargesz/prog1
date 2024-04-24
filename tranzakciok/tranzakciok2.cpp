#include <iostream>
#include <fstream>
#include <vector>
#include <map>
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
      map<string,int> strings;
      for (struct Tranzakcio t : tranzakciok) {
            strings[t.items] = 0;
      }
      for (struct Tranzakcio t : tranzakciok) {
            strings[t.items]++;
      }
      for (pair<string,int> p : strings) {
            cout<<(float)p.second/(float)tranzakciok.size()<<" "<<p.first<<endl;
      }
      return 0;
}