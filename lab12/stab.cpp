#include "Trie.h"
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

int main() {

  Trie t;
  char s[5000];
  ifstream i("mobydick.txt");
  i.read(s, sizeof(s));
  int slen = strlen(s);
  for (int i=0; i < slen; i++) {
    t.insert(s+i,i);
  }

  char s2[5000];
  ifstream i2("startrek.txt");
  i2.read(s2, sizeof(s2));
  int s2len = strlen(s2);
  int bestindex = -1;
  int bestlen = 0;
  for (int i=0; i < s2len; i++) { 
    int temp = t.longestPrefix(s2+i);
    if (temp > bestlen) {
      bestlen = temp;
      bestindex = i;
    }
  }
  s2[bestindex+bestlen] = 0;

  cout << "Longest common substring:\n";
  cout << s2+bestindex << "\n";

  return 0;

}
