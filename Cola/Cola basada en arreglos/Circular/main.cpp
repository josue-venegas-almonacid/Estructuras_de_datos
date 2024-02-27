#include <iostream>
#include "queue.h"

int main(){
  Cola C;
  C.enqueue(1);
  C.enqueue(2);
  C.enqueue(3);
  C.enqueue(4);
  C.enqueue(5);
  C.dequeue();
  C.enqueue(1);
  C.print();
  return 0;
}
