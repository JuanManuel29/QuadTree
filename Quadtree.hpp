#ifndef _QUADTREE_HPP
#define _QUADTREE_HPP
#include <iostream>
#include <string>
#include <random>

//ESTRCUTURA NODO
struct Node{
    //NW,NE,SW,SE SON LOS 4 HIJOS DE UN QUADTREE
    Node *nw;
    Node *ne;
    Node *sw;
    Node *se;
    Node *parent;

    //LIMITES DEL NODO(MATRIZ)
    bool divided;// para que un mismo nodo no se divida más de una vez
    int iniciox;
    int inicioy;
    int finalx;
    int finaly;
};

//CLASE QUADTREE QUE CREA EL ARBOL CON UNA MATRIZ Y 4 HIJOS, RESERVANDO MEMORIA DINÁMICAMENTE
class quadtree{
private:
    //ATRIBUTOS: RAIZ DEL ÁRBOL, EL TAMAÑO, EL RANGO DE TOLERANCIA DE LA DIFERENCIA ENTRE COLORES
    //PARA DECIDIR SI SE DIVIDE O NO EL NODO.
    Node *root;
    unsigned size;
    unsigned range; //rango en el que se va a evaluar si el quadtree se necesita dividir otra vez
    int ** matriz; //SE CREA UNA MATRIZ DE APUNTADORES(ESTRUCTURA SIMILAR A UNA TABLA HASH)

    //Métodos privados
    void divide_node(Node* &node); //ALGORITMO RECURSIVO QUE DIVIDE LA IMÁGEN EN 4 DEPENDIENDO DE LA 
                                   //SIMILITUD ENTRE REGIONES DE PIXELES
    void display_node(Node* node); //IMPRIME UN NODO

    
    void asignacion(Node*& node,int Ix, int Iy,int Fx, int Fy); //LE ASIGNA LOS LIMITES DENTRO DE LA MATRIZ A CADA HIJO DEL QUADTREE
    bool equal(int Ix,int Iy,int Fx, int Fy, Node* &node); //COMPARACIÓN ENTRE REGIONES DE PIXELES

public:
    //Constructor(con y sin parámetros iniciales) y destructor
    quadtree();
    quadtree(int x, int y);
    ~quadtree();

    //Metodos
    void LlenarMatriz();
    void divide(); //wrapper de divide_node
    void display(); //wrapper de display_node
};



#endif