#include <iostream>
using namespace std;

struct Nodo {
  int num;
  Nodo* left;
  Nodo* right;
};

class ABB {
    Nodo* root;
  public:
    ABB(){
      root = NULL;
    }
    void insert(int num, Nodo* nodo){
      // si el nuevo nodo es menor que el nodo actual
      if (num < nodo->num) {
        // verifica si el nodo actual no tenga hijos
        if (nodo->left == NULL) {
          nodo->left = new Nodo;
          nodo->left->num = num;
        }
        // si tiene hijos, enfoca como nodo actual al hijo izquierdo
        else{
          insert(num, nodo->left);
        }
      }
      // si el nuevo nodo es mayor o igual que el nodo actual
      else{
        if (nodo->right == NULL) {
          nodo->right = new Nodo;
          nodo->right->num = num;
        }
        else {
          insert(num, nodo->right);
        }     
      }
    }
    // en caso no exite un nodo, se asigna el ingresante
    void insert(int num){
      if (root == NULL){
        root = new Nodo;
        root->num = num;
      }  
      else{
        insert(num, root);
      }
    }

    int buscar_an(Nodo* nodo, int num) {
        cout << nodo->num << "->";
        if (nodo->num == num) {
            cout << num << "-><-";
        } else if (nodo->left != NULL && nodo->right != NULL) {
            cout << "None" << endl;
        } else {
            if (nodo->left->num > num)
                buscar_an(nodo->left, num);
            else if (nodo->right->num <= num)
                buscar_an(nodo->right, num);
        }
        return 0;
    }

    void buscar(int num) { 
        buscar_an(root, num); 
    }
    
};
int main() {
  ABB arbol;
  arbol . insert (25) ;
  arbol . insert (20) ;
  arbol . insert (36) ;
  arbol . insert (10) ;
  arbol . insert (22) ;
  arbol . insert (30) ;
  arbol . insert (40) ;
  arbol . insert (5) ;
  arbol . insert (12) ;
  arbol . insert (28) ;
  arbol . insert (38) ;
  arbol . insert (48) ;
  arbol . insert (2) ;
  arbol . insert (7) ;
  arbol . insert (16) ;
  arbol . insert (26) ;
  arbol . insert (44) ;
  arbol . insert (51) ;
  arbol . buscar (7) ;
  arbol . buscar (16) ;
  arbol . buscar (44) ;
  arbol . buscar (45) ;
}