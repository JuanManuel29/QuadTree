#ifndef _QUADTREE_HPP
#define _QUADTREE_HPP
#include <iostream>
#include <string>

struct Node{
    Node *nw;
    Node *ne;
    Node *sw;
    Node *se;
    std::string color; //Podría ser 'char'
};

class quadtree{
private:
    Node *root;
    unsigned size; 

    //Métodos privados
    void insert_node(Node* &node, Node *p, std::string k);
    void display_node(Node *node, int count);

public:
    //Constructor y destructor
    quadtree();
    //~quadtree();

    //Metodos
    void insert(); //wrapper de insert_node
    void display(); //wrapper de display_node
};


//Implementaciones

quadtree::quadtree(){
    root = nullptr;
    size = 0;
}

//quadtree::~quadtree(){}

void quadtree::insert_node(){

}

void quadtree::display_node(){

}

void quadtree::insert(){

}

void quadtree::display(){
    
}


#endif