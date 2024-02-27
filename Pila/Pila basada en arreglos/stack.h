typedef int tElemPila;

class Pila{
  int maxSize;                  //Tamaño máximo de la pila
  int stackSize;                //Tamaño actual de la pila
  tElemPila* Array;             //Memoria dinámica para un arreglo de elementos

public:
  Pila();                       //Constructor
  ~Pila();                      //Destructor
  void clear();                 //Vacía la pila
  int push(tElemPila item);     //Inserta un elemento en el tope de la pila
  int pop();                    //Remueve el elemento en el tope de la pila
  tElemPila topValue();         //Retorna el elemento en el tope de la pila
  int length();                 //Retorna el tamaño actual de la pila
  void tnirp();                 //Imprime la pila
};

Pila::Pila(){
  maxSize = 1000000;
  Array = new tElemPila[maxSize];
  stackSize = 0;
}

Pila::~Pila(){
  delete [] Array;
}

void Pila::clear(){
  delete [] Array;
  Array = new tElemPila[maxSize];
  stackSize = 0;
}

int Pila::push(tElemPila item){
  if (stackSize == maxSize) return -1;

  Array[stackSize] = item;
  stackSize++;
  return 1;
}

int Pila::pop(){
  if (stackSize == 0) return -1;

  stackSize--;
  return 1;
}

tElemPila Pila::topValue(){
  return Array[stackSize-1];
}

int Pila::length(){
  return stackSize;
}

void Pila::tnirp(){
  if (stackSize == 0){
    printf("[ -->\n");
    return;
  }

  int i;
  printf("[");
  for (i = stackSize-1; i > 0; i--){
    printf("%i, ", Array[i]);
  }
  printf("%i-->\n", Array[i]);
}
