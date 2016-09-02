#include "RichPoint.h"
#include <iostream>
using namespace std;

void printScaled(RichPoint p) {
  p.scale(1.0/p.distance(RichPoint(0,0)));
  cout << p << endl;
}

int main() {

  RichPoint p(0,0);
  RichPoint q(1,1);
  cout << "p = " << p << endl;
  cout << "q = " << q << endl;

  RichPoint* pptr = &p;
  RichPoint* qptr = &q;
  cout << "pptr = " << pptr << endl;
  cout << "qptr = " << qptr << endl;

  RichPoint& pref = p;
  RichPoint& qref = q;
  cout << "pref = " << pref << endl;
  cout << "qref = " << qref << endl;

  p = q;
  cout << "p = " << p << endl;
  cout << "q = " << q << endl;
  cout << "pptr = " << &p << endl;
  cout << "qptr = " << &q << endl;

  cout << "p, scaled to unit length: ";
  printScaled(p);
  cout << "original p= " << p << endl;
}
