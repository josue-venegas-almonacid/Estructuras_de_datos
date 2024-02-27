#include <iostream>
#include "list.h"

int main(){
  Lista P;
  P.append(1);
  P.append(2);
  P.append(3);
  P.insert(0,0);
  P.insert(-1,20);
  P.insert(-2,18);
  P.insert(-5,22);
  P.insert(-8,30);
  P.remove(0);
  P.insert(0,30);
  P.print();
  return 0;
}
