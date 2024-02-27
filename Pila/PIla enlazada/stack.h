typedef int tELemPila;

typedef struct Nodo{
  struct Nodo* prev;
  tELemPila info;
} Nodo;

class Pila{
  Nodo* current;
  Nodo* tail;

  int stackSize;

public:
  Pila();
  ~Pila();
  void clear();
  int push(tELemPila);
  int pop();
  tELemPila topValue();
  int length();
  void tnirp();

private:
  void recursive_free();
};


Pila::Pila(){
  current = NULL;
  tail = NULL;
  stackSize = 0;
}

Pila::~Pila(){
  recursive_free();
}

void Pila::clear(){
  recursive_free();
  current = NULL;
  tail = NULL;
  stackSize = 0;
}

void Pila::recursive_free(){
  current = tail;
  while (current != NULL){
    Nodo* ant = current->prev;
    delete current;
    current = ant;
  }
}

int Pila::push(tELemPila item){
  Nodo* nuevo_nodo = new Nodo;
  nuevo_nodo->info = item;

  if (tail == NULL){
    current = tail = nuevo_nodo;
    tail->prev = NULL;
  }

  else{
    nuevo_nodo->prev = tail;
    tail = nuevo_nodo;
  }

  stackSize++;
  return 1;
}

int Pila::pop(){
  current = tail;
  tail = tail->prev;
  delete current;
  stackSize--;
  return 1;
}

tELemPila Pila::topValue(){
  return tail->info;
}

int Pila::length(){
  return stackSize;
}

void Pila::tnirp(){
  if (tail == NULL) {
    printf("[ -->\n");
    return;
  }

  printf("[");
  current = tail;
  int i;
  for (i=stackSize-1; i > 0; i--){
    printf("%i, ", current->info);
    current = current->prev;
  }
  printf("%i-->\n", current->info);
}
