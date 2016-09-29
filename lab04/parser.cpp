#include <iostream>
#include <string.h>
#include "../shaffer/book.h"
#include "../shaffer/astack.h"

using namespace std;

bool valid_p(char* str) {
  AStack<char> S(100);
  int len=strlen(str);
  int i=0;
  S.push('E');
  while (i<len) {
    char c=str[i];
    if (S.length()==0) return false;
    char s=S.topValue();
    if ((c==')' && s==')') || 
        (c=='(' && s=='(') || 
        ((c=='*' || c=='+')  && s=='O')) {
      S.pop(); i++;
    }
    else if (isdigit(c) && s == 'E') {
      S.pop();
      while (isdigit(str[i]) && i<len) i++;
    }
    else if (c=='(' and s=='E') {
      S.pop();
      S.push(')'); S.push('E'); S.push('O'); S.push('E'); S.push('(');
    }
    else {
      return false;
    }
  }
  return (S.length()==0);
}

int main() {
  char inp[64];
  cout << "Enter an expression: "; 
  cin >> inp; 
  if (valid_p(inp)) {
    cout << "valid." << endl;
  }
  else {
    cout << "not valid." << endl;
  }
  return 0;
}
