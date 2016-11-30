#include "Trie.h"
#include <iostream>
#include <string.h>
using namespace std;

bool findSubstring(const char* big, const char* small) {
  Trie t;
  int biglen = strlen(big);
  for (int i=0; i < biglen; i++) {
    t.insert(big+i,i);
  }
  return t.longestPrefix(small) == strlen(small);
}

int main() {

  char b[128];
  char s[128];

  cout << "Big string to search in: ";
  cin >> b;
  cout << "Smaller string to search for: ";
  cin >> s;

  if (findSubstring(b,s)) {
    cout << "Found it!\n";
  }
  else {
    cout << "Not found.\n";
  }

  return 0;

}
