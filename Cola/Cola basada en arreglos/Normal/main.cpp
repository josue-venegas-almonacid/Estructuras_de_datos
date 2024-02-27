#include <iostream>
#include "queue.h"

int main(){
  Cola N;
  N.enqueue(1);
  N.enqueue(2);
  N.enqueue(3);
  N.enqueue(4);
  N.enqueue(5);
  N.dequeue();
  N.enqueue(1);
  N.print();
  return 0;
}
