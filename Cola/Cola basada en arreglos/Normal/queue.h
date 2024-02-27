typedef int tElemCola;

class Cola{
  int maxSize;
  int queueSize;
  tElemCola* Array;

public:
  Cola();
  ~Cola();
  void clear();
  int enqueue(tElemCola item);
  int dequeue();
  tElemCola frontValue();
  int length();
  void print();
};

Cola::Cola(){
  maxSize = 5;
  Array = new tElemCola[maxSize];
  queueSize = 0;
}

Cola::~Cola(){
  delete [] Array;
}

void Cola::clear(){
  delete [] Array;
  Array = new tElemCola[maxSize];
  queueSize = 0;
}

int Cola::enqueue(tElemCola item){
  if (queueSize == maxSize) return -1;

  Array[queueSize] = item;
  queueSize++;
  return 1;
}

int Cola::dequeue(){
  if (queueSize == 0) return -1;

  int i;
  for (i = 0; i < queueSize; i++){
    Array[i] = Array[i+1];
  }
  queueSize--;
  return 1;
}

tElemCola Cola::frontValue(){
  return Array[0];
}

int Cola::length(){
  return queueSize;
}

void Cola::print(){
  if (queueSize == 0){
    printf("<-- <--\n");
    return;
  }

  int i;
  printf("<--");
  for (i = 0; i < queueSize-1; i++){
    printf("%i, ", Array[i]);
  }
  printf("%i<--\n", Array[i]);
}
