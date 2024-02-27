#include <iostream>
#include "queue.h"

int main(){
  Cola E;
  E.enqueue(1);
  E.enqueue(2);
  E.enqueue(3);
  E.enqueue(4);
  E.enqueue(5);
  E.dequeue();
  E.enqueue(1);
  E.print();
  return 0;
}
