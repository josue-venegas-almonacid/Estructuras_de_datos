typedef int tElemLista;

class Lista{
  int maxSize;
  int listSize;
  tElemLista* Array;

public:
  //OPERACIONES DE LA LISTA
  Lista();                                  //CONSTRUCTOR
  ~Lista();                                 //DESTRUCTOR
  void clear();                             //VACÍA LA LISTA
  void print();                             //IMPRIME LA LISTA
  int length();                             //RETORNA LA LONGITUD DE LA LISTA

  //OPERACIONES DE LOS ELEMENTOS DE LA LISTA SIN NECESIDAD DE CURSOR
  tElemLista getValue(int pos);             //RETORNA EL VALOR EN DICHA POSICIÓN
  int insert(int pos, tElemLista item);     //INSERTA UN ELEMENTO EN LA POSICIÓN INDICADA
  int append(tElemLista item);              //AGREGA UN ELEMENTO AL FINAL DE LA LISTA
  int remove(int pos);                      //ELIMINA EL ELEMENTO EN DICHA POSICIÓN
};

Lista::Lista(){
  maxSize = 1000000;
  listSize = 0;
  Array = new tElemLista[maxSize];
}

Lista::~Lista(){
  delete [] Array;
}

void Lista::clear(){
  delete [] Array;
  Array = new tElemLista[maxSize];
  listSize = 0;
}

void Lista::print(){
  if (listSize == 0){
    printf("[]\n");
    return;
  }

  int i;
  printf("[");
  for (i = 0; i < listSize-1; i++){
    printf("%i, ", Array[i]);
  }
  printf("%i]\n", Array[i]);
}

int Lista::length(){
  return listSize;
}

tElemLista Lista::getValue(int pos){
  return Array[pos];
}

int Lista::insert(int pos, tElemLista item){
  if (listSize == maxSize) return -1;

  if (pos >= listSize || pos*(-1) == listSize){
    append(item);
    return 1;
  }

  else if (pos < 0){
    if (pos*(-1) < listSize) pos = listSize+pos;
    else pos = 0;
  }

  int i;
  for (i = listSize; i > pos; i--){
    Array[i] = Array[i-1];
  }

  Array[i] = item;
  listSize++;
  return 1;
}

int Lista::append(tElemLista item){
  if (listSize == maxSize) return -1;

  Array[listSize] = item;
  listSize++;
  return 1;
}

int Lista::remove(int pos){
  if (listSize == 0 || pos < 0 || pos >= listSize) return -1;
  if (pos == listSize-1){
    listSize--;
    return 1;
  }

  int i;
  for (i = pos; i < listSize-1; i++){
    Array[i] = Array[i+1];
  }
  listSize--;
  return 1;
}
