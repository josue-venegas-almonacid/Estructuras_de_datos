typedef int tElemCola;

typedef struct Nodo{
  tElemCola info;
  struct Nodo* next;
} Nodo;

class Cola{
  Nodo* head;
  Nodo* tail;

  int queueSize;

public:
  Cola();
  ~Cola();
  void clear();
  int enqueue(tElemCola item);
  int dequeue();
  int length();
  tElemCola frontValue();
  void print();

private:
  void recursive_free();
};

void Cola::recursive_free(){
  Nodo* current = head;
  while (current != NULL){
    Nodo* sig = current->next;
    delete current;
    current = sig;
  }
}

Cola::Cola(){
  head = NULL;
  tail = NULL;
  queueSize = 0;
}

Cola::~Cola(){
  recursive_free();
}

void Cola::clear(){
  recursive_free();
  head = NULL;
  tail = NULL;
  queueSize = 0;
}

int Cola::enqueue(tElemCola item){
  Nodo* nuevo_nodo = new Nodo;
  nuevo_nodo->info = item;

  if (head == NULL){
    head = tail = nuevo_nodo;
  }

  else{
    tail->next = nuevo_nodo;
    tail = nuevo_nodo;
  }

  nuevo_nodo->next = NULL;
  queueSize++;
  return 1;
}

int Cola::dequeue(){
  if (queueSize == 0) return -1;

  Nodo* old_head = head;
  head = head->next;
  delete old_head;

  queueSize--;
  return 1;
}

int Cola::length(){
  return queueSize;
}

tElemCola Cola::frontValue(){
  return head->info;
}

void Cola::print(){
  if (queueSize == 0){
    printf("<-- <--\n");
    return;
  }

  printf("<--");
  int i;
  Nodo* current = head;
  for (i = 0; i < queueSize-1; i++){
    printf("%i, ", current->info);
    current = current->next;
  }
  printf("%i<--\n", current->info);
}
