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
  int** table;
  table = new int*[s1len];
  for (int i=0; i < s1len; i++)
    table[i] = new int[s2len];

  for (int i=0; i < s1len; i++) {
    for (int j=0; j < s2len; j++) {
      if (s1[i]==s2[j]) {
        if (i==0 || j==0)
          table[i][j] = 1;
        else
          table[i][j] = table[i-1][j-1] + 1;
      }
      else {
        table[i][j] = 0;
      }
      if (table[i][j] > bestlen) {
        bestindex = j;
        bestlen = table[i][j];
      }
    }
  }

  s2[bestindex+1] = 0;

  cout << "Longest common substring:\n" << s2+bestindex-bestlen+1 << "\n";

  for (int i=0; i < s1len; i++)
    delete table[i];
  delete table;

  return 0;
}
