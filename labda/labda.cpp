#include <iostream>
#include <windows.h>
#include <stdlib.h>
#define WIDTH 40
#define HEIGHT 20
using namespace std;

struct Ball {
      int x;
      int y;
      string m;
};

void draw(Ball b) {
      for (int i = 0; i < HEIGHT+3; i++) {
            for (int o = 0; o < WIDTH+3; o++) {
                  if (i == 0 || i == HEIGHT+2 || o == WIDTH+2 || o == 0) {
                        cout<<"#";
                  } else if (i == b.y+1 && o == b.x+1) {
                        cout<<"O";
                  } else {
                        cout<<" ";
                  }
            }
            cout<<endl;
      }
}


char inverse(char c) {
      if (c == 'n') {
            return 's';
      }
      if (c == 's') {
            return 'n';
      }
      if (c == 'e') {
            return 'w';
      }
      if (c == 'w') {
            return 'e';
      }
}

void bounce(Ball& b) {
      string s = "";
      if (b.x == 0) {
            s+="w";
      }
      if (b.x == WIDTH) {
            s+="e";
      }
      if (b.y == 0) {
            s+="n";
      }
      if (b.y == HEIGHT) {
            s+="s";
      }
      for (int i = 0; i < s.length(); i++) {
            for (int o = 0; o < b.m.length(); o++) {
                  if (s[i] == b.m[o]) {
                        b.m[o] = inverse(s[i]);
                  }
            }
      }
}

void move(Ball& b) {
      if (b.x == 0 || b.x == WIDTH || b.y == 0 || b.y == HEIGHT) {
            bounce(b);
      }
      for (char c : b.m) {
            if (c == 'n') {
                  b.y--;
            }
            if (c == 'e') {
                  b.x++;
            }
            if (c == 'w') {
                  b.x--;
            }
            if (c == 's') {
                  b.y++;
            }
      }
}
int main() {
      Ball b;
      cout<<"Labda start pos:"<<endl;
      cout<<"x: ";
      cin>>b.x;
      cout<<"y: ";
      cin>>b.y;
      cout<<"Kezdo irany (nswe): ";
      cin>>b.m;
      while (true) {
      system("clear");
      move(b);
      draw(b);
      Sleep(160);
      }
      return 0;
}