typedef int tElemCola;

class Cola{
  int maxSize;
  int queueSize;
  tElemCola* Array;

  int head_pos;
  int tail_pos;

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
  head_pos = 0;
  tail_pos = 0;
}

Cola::~Cola(){
  delete [] Array;
}

void Cola::clear(){
  delete [] Array;
  Array = new tElemCola[maxSize];
  queueSize = 0;
  head_pos = 0;
  tail_pos = 0;
}

int Cola::enqueue(tElemCola item){
  if (queueSize == maxSize) return -1;

  if (tail_pos == maxSize) tail_pos = 0;

  Array[tail_pos] = item;
  tail_pos++;
  queueSize++;
  return 1;
}

int Cola::dequeue(){
  if (queueSize == 0) return -1;

  head_pos++;
  queueSize--;
  return 1;
}

tElemCola Cola::frontValue(){
  return Array[head_pos];
}

int Cola::length(){
  if (head_pos > tail_pos) return (head_pos-tail_pos);
  else return (tail_pos-head_pos);
}

void Cola::print(){
  if (queueSize == 0){
    printf("<-- <--\n");
  }

  else if(head_pos < tail_pos){
    printf("<--");
    int i;
    for (i = head_pos; i < tail_pos; i++){
      printf("%i, ", Array[i]);
    }
    printf("%i<--\n", Array[i]);
  }

  else{
    printf("<--");
    int i;
    for (i = head_pos; i < maxSize; i++){
      printf("%i, ", Array[i]);
    }
    for (i = 0; i < tail_pos-1; i++){
      printf("%i, ", Array[i]);
    }
    printf("%i<--\n", Array[i]);
  }
}
