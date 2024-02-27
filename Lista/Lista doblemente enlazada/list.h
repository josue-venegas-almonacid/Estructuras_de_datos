typedef int tElemLista;

typedef struct Nodo {
  struct Nodo* prev;    // DIRECCIÓN DE MEMORIA AL ELEMENTO ANTERIOR
  tElemLista info;      // ELEMENTO
  struct Nodo* next;    // DIRECCIÓN DE MEMORIA AL ELEMENTO SIGUIENTE
} Nodo;

class Lista {
  Nodo* head;           // DIRECCIÓN DE MEMORIA DE LA CABEZA DE LA LISTA
  Nodo* current;        // DIRECCIÓN DE MEMORIA DEL ELEMENTO ACTUAL
  Nodo* tail;           // DIRECCIÓN DE MEMORIA DEL FINAL DE LA LISTA
  int listSize;         // TAMAÑO DE LA LISTA

public:
  Lista();                                // CONSTRUCTOR
  ~Lista();                               // DESTRUCTOR
  void clear();                           // LIMPIA LA LISTA
  void print();                           // IMPRIME LA LISTA
  void tnirp();                           // IMPRIME LA LISTA AL REVÉS
  int length();                           // RETORNA LA CANTIDAD DE ELEMENTOS EN LA LISTA

  tElemLista getValue(int pos);           // RETORNA EL ELEMENTO EN DICHA POSICIÓN
  int insert(int pos, tElemLista item);   // INSERTA UN ELEMENTO EN DICHA POSICIÓN
  int append(tElemLista item);            // INSERTA UN ELEMENTO AL FINAL DE LA LISTA
  int remove(int pos);                    // REMUEVE EL ELEMENTO EN DICHA POSICIÓN

private:
  void recursive_free();                  // AUXILIAR. ELIMINA LA LISTA DE MANERA RECURSIVA
  Nodo* moveToPos(int pos);               // AUXILIAR. CAMBIA *CURRENT A LA DIRECCIÓN DE MEMORIA DEL ELEMENTO DESEADO

};

Lista::Lista(){
  head = NULL;
  current = NULL;
  tail = NULL;
  listSize = 0;
}

Lista::~Lista(){
  recursive_free();
}

void Lista::clear(){
  recursive_free();
  head = NULL;
  current = NULL;
  tail = NULL;
  listSize = 0;
}

void Lista::recursive_free(){
  current = head;
  while (current != NULL){
    Nodo* sig = current->next;
    delete current;
    current = sig;
  }
}

void Lista::print(){
  if (head == NULL) {
    printf("[]\n");
    return;
  }

  printf("[");
  current = head;
  int i;
  for (i=0; i < listSize-1; i++){
    printf("%i, ", current->info);
    current = current->next;
  }
  printf("%i]\n", current->info);
}

void Lista::tnirp(){
  if (head == NULL) {
    printf("[]\n");
    return;
  }

  printf("[");
  current = tail;
  int i;
  for (i=listSize-1; i > 0; i--){
    printf("%i, ", current->info);
    current = current->prev;
  }
  printf("%i]\n", current->info);
}


int Lista::insert(int pos, tElemLista item){

  if ((head == NULL) || (pos >= listSize) || (pos*(-1) == listSize)){
    append(item);
    return 1;
  }

  Nodo* nuevo_nodo = new Nodo;
  nuevo_nodo->info = item;
  current = moveToPos(pos);

  if (current == head){
    nuevo_nodo->next = current;
    current->prev = nuevo_nodo;
    head = nuevo_nodo;
  }

  else{
    current->prev->next = nuevo_nodo;
    nuevo_nodo->next = current;
    nuevo_nodo->prev = current->prev;
    current->prev = nuevo_nodo;
  }

  listSize++;
  return 1;
}

int Lista::append(tElemLista item){
  Nodo* nuevo_nodo = new Nodo;
  nuevo_nodo->info = item;

  if (head == NULL){
    head = current = tail = nuevo_nodo;
    head->prev = head->next = NULL;
    tail->prev = tail->next = NULL;
  }

  else{
    tail->next = nuevo_nodo;
    nuevo_nodo->prev = tail;
    nuevo_nodo->next = NULL;
    tail = nuevo_nodo;
  }

  listSize++;
  return 1;
}

int Lista::remove(int pos){
  if (listSize == 0 || pos < 0 || pos >= listSize) return -1;

  current = moveToPos(pos);

  if (current == head){
    current->next->prev = NULL;
    head = current->next;
  }
  else if (current == tail){
    current->prev->next = NULL;
    tail = current->prev;
  }
  else{
    current->prev->next = current->next;
    current->next->prev = current->prev;
  }

  delete current;
  listSize--;
  return 1;
}

tElemLista Lista::getValue(int pos){
  if (pos < 0 || pos >= listSize) return -1;
  current = moveToPos(pos);
  return current->info;
}

int Lista::length(){
  return listSize;
}

Nodo* Lista::moveToPos(int pos){
  if (pos >= listSize) return NULL;

  else if (pos == listSize-1) return tail;

  else if (pos < 0){
    if (pos*(-1) < listSize) pos = listSize+pos;
    else pos = 0;
  }

  current = head;
  int i;
  for (i = 0; i < pos; i++){
    current = current->next;
  }
  return current;
}
