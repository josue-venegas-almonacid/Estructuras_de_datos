#include <iostream>
#include "stack.h"

int main(){
  Pila E;
  E.push(0);
  E.push(40);
  E.pop();
  E.pop();
  E.push(1);
  printf("Printing values from stack\n");
  E.tnirp();
  printf("Stack size: %i\n", E.length());
  printf("Top value: %i\n", E.topValue());

  return 0;
}
