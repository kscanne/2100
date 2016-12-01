#include "Trie.h"
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

int main() {

  char s1[5000], s2[5000];
  ifstream i("mobydick.txt");
  i.read(s1, sizeof(s1));
  ifstream i2("startrek.txt");
  i2.read(s2, sizeof(s2));
  int s1len = strlen(s1), s2len = strlen(s2), bestindex=-1, bestlen=0;

  for (int i=0; i < s1len; i++) {
    for (int j=0; j < s2len; j++) {
      int k = 0;
      while (s1[i+k]==s2[j+k]) {
        k++;
        if (i+k==s1len || j+k==s2len) break;
      }
      if (k > bestlen) {
        bestindex = j;
        bestlen = k;
      }
    }
  }

  s2[bestindex+bestlen] = 0;

  cout << "Longest common substring:\n" << s2+bestindex << "\n";

  return 0;
}
