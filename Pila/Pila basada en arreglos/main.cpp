#include <iostream>
#include "stack.h"

int main(){
  Pila A;
  A.push(0);
  A.push(40);
  A.pop();
  A.pop();
  A.push(1);
  printf("Printing values from stack\n");
  A.tnirp();
  printf("Stack size: %i\n", A.length());
  printf("Top value: %i\n", A.topValue());
  return 0;
}
