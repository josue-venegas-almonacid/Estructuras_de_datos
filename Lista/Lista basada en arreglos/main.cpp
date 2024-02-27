#include <iostream>
#include "list.h"

int main(){
  Lista A;
  A.append(1);
  A.append(2);
  A.append(3);
  A.insert(0,0);
  A.insert(-1,20);
  A.insert(-2,18);
  A.insert(-5,22);
  A.insert(-8,30);
  A.remove(0);
  A.insert(0,30);
  A.print();
  return 0;
}
