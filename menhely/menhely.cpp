#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct Allat{
	string nev;
	string fajta;
	string kor;
	string szin;
};

void operator>>(fstream& in, struct Allat& a) {
	in>>a.nev>>a.fajta>>a.kor>>a.szin;
}

void operator<<(ostream& out, struct Allat a) {
	cout<<a.nev<<": "<<a.fajta<<", "<<a.kor<<", "<<a.szin<<endl;
}

string operator<(struct Allat a, string s) {
      if (s == "név") {
            return a.nev;
      } else if (s == "kor") {
            return a.kor;
      } else if (s == "szín") {
            return a.szin;
      } else if (s == "fajta") {
            return a.fajta;
      } else return "";
}

void search(vector<struct Allat> v) {
	string atr,ert;
	cout<<"Attribútum: ";
	cin>>atr;
	cout<<"Érték: ";
	cin>>ert;
	for (struct Allat a : v) {
            if (a<atr == ert) {
                  cout<<a;
            }
	}
}

int main() {
	fstream in("menhely.txt");
	if (!in) {
        cout << "File error" << endl;
        return 1;
    }
	vector<struct Allat> v;
	struct Allat a;
	string row;
	while (!in.eof()) {
		in>>a;
		v.push_back(a);
	}
	search(v);
	in.close();
	return 0;
}
