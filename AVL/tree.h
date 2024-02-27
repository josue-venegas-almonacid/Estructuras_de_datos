typedef int tElemArbol;

typedef struct Nodo{
  tElemArbol info;
  struct Nodo* padre;
  struct Nodo* hijo_izquierdo;
  struct Nodo* hijo_derecho;
} Nodo;

class ArbolBin{
  Nodo* raiz;
  int TreeSize;

public:
  ArbolBin();
  ~ArbolBin();
  void clear();
  int insert(tElemArbol item);
  //int remove(tElemArbol item);
  Nodo* find(tElemArbol item);
  int size();
  void preOrder();
  void inOrder();
  void postOrder();

private:
  void recursive_free(Nodo* nodo);
  void preOrderHelp(Nodo* nodo);
  void inOrderHelp(Nodo* nodo);
  void postOrderHelp(Nodo* nodo);
  Nodo* findHelp(Nodo* nodo, tElemArbol item);
  int insertHelp(Nodo* dad, Nodo* nodo, tElemArbol item, int pos);
  //removeHelp
  //Nodo* minimo(Nodo* nodo);
};

ArbolBin::ArbolBin(){
  raiz = NULL;
  size = 0;
}

ArbolBin::~ArbolBin(){
  recursive_free(raiz);
}

void ArbolBin::clear(){
  recursive_free(raiz);
  raiz = NULL;
  size = 0;
}

int ArbolBin::insert(tElemArbol item){
  if (raiz == NULL){
    Nodo* nuevo_nodo = new Nodo;
    nuevo_nodo->info = item;
    nuevo_nodo->padre = NULL;
    nuevo_nodo->hijo_izquierdo = NULL;
    nuevo_nodo->hijo_derecho = NULL;
    raiz = nuevo_nodo;
    TreeSize++;
    return 1;
  }
  if (find(item) != NULL) return -1;
  return insertHelp(raiz, raiz, item, 0);
}

int ArbolBin::insertHelp(Nodo* dad, Nodo* nodo, tElemArbol item, int pos){
  if (nodo == NULL){
    Nodo* nuevo_nodo = new Nodo;
    nuevo_nodo->info = item;
    if (pos == 0) dad->hijo_izquierdo = nuevo_nodo;
    else{
      dad->hijo_derecho = nuevo_nodo;
    }
    nuevo_nodo->padre = dad;
    nuevo_nodo->hijo_izquierdo = NULL;
    nuevo_nodo->hijo_derecho = NULL;
    TreeSize++;
    return 1;
  }
  if (item < nodo->info) return insertHelp(nodo, nodo->hijo_izquierdo, item, 0);
  else return insertHelp(nodo, nodo->hijo_derecho, item, 1);
}

int ArbolBin::size(){
  return TreeSize;
}

void ArbolBin::recursive_free(Nodo* nodo){
  if (nodo == NULL) return;
  recursive_free(nodo->hijo_izquierdo);
  recursive_free(nodo->hijo_derecho);
  delete nodo;
}

void ArbolBin::preOrder(){
  preOrderHelp(raiz);
}

void ArbolBin::inOrder(){
  inOrderHelp(raiz);
}

void ArbolBin::postOrder(){
  postOrderHelp(raiz);
}

void ArbolBin::preOrderHelp(Nodo* nodo){
  if (nodo == NULL) return;
  printf("%i\n", nodo->info);
  preOrderHelp(nodo->hijo_izquierdo);
  preOrderHelp(nodo->hijo_derecho);
}

void ArbolBin::inOrderHelp(Nodo* nodo){
  if (nodo == NULL) return;
  inOrderHelp(nodo->hijo_izquierdo);
  printf("%i\n", nodo->info);
  inOrderHelp(nodo->hijo_derecho);
}

void ArbolBin::postOrderHelp(Nodo* nodo){
  if (nodo == NULL) return;
  postOrderHelp(nodo->hijo_izquierdo);
  postOrderHelp(nodo->hijo_derecho);
  printf("%i\n", nodo->info);
}

Nodo* ArbolBin::find(tElemArbol item){
  return findHelp(raiz, item);
}

Nodo* ArbolBin::findHelp(Nodo* nodo, tElemArbol item){
  if (nodo == NULL) return NULL;
  if (nodo->info == item) return nodo;
  if (item < nodo->info) return findHelp(nodo->hijo_izquierdo, item);
  else return findHelp(nodo->hijo_derecho, item);
}

/*int ArbolBin::remove(tElemArbol item){
  if (TreeSize == 0) return -1;
  Nodo* nodo = find(item);
  return removeHelp(nodo);
}

int ArbolBin::removeHelp(Nodo* nodo){
  if (nodo == NULL) return -1;

  if (nodo->hijo_izquierdo != NULL && nodo->hijo_derecho != NULL){
    Nodo* menor = minimo(nodo->hijo_derecho);
    nodo->info = menor->info;
    removeHelp(menor);
  }

  else if (nodo->hijo_izquierdo != NULL){
    replace(nodo, nodo->hijo_izquierdo);
  }

  return 1;
}

Nodo* ArbolBin::minimo(Nodo* nodo){
  if (nodo == NULL) return NULL;
  if (nodo->hijo_izquierdo != NULL){
    return minimo(nodo->hijo_izquierdo);
  }
  return nodo;
}*/
