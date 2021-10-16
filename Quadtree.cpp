#include "Quadtree.hpp"

quadtree::quadtree(){
    root=new Node;
    //size = 0;
    //range=25;
    root->nw= nullptr;
    root->ne= nullptr;
    root->sw= nullptr;
    root->se= nullptr;
    root->divided = false;
    root->iniciox = 0;
    root->inicioy= 0;
    root->finalx = 10; //420; //SE LE DEFINEN LOS LIMITES MANUELAMNETE
    root-> finaly = 10;//420;
    matriz = new int*[root->finaly];
    for(int i = 0; i<root->finaly; i++)
        matriz[i]= new int[root->finalx]; 

}
quadtree::quadtree(int x, int y ){
    root=new Node;
    //size = 0;
    //range=25;
    root->nw= nullptr;
    root->ne= nullptr;
    root->sw= nullptr;
    root->se= nullptr;
    root->divided = false;
    root->iniciox = 0;
    root->inicioy= 0;
    root->finalx= x;
    root->finaly = y;
    int** matriz;
    matriz = new int*[y];// reserva memoria para el numero de columnas
    for(int i = 0; i<y; i++)
        matriz[i]= new int[x]; // reserva memoria para el numero de filas  
}

quadtree::~quadtree(){ 
    for(int i = 0; i<root->finaly; i++)
        delete matriz[i];
    delete matriz; 
}

void quadtree::LlenarMatriz(){
    int Desde=0, Hasta=100;
    for(int i = 0; i< 10; i++){
        for(int j = 0; j<10; j++){
            matriz[i][j]= rand()%(Hasta-Desde+1)+Desde;
        } 
    }
}


void quadtree::asignacion(Node*& node,int Ix, int Iy,int Fx, int Fy){
    node= new Node;
    node->iniciox = Ix;
    node->inicioy = Iy;
    node->finalx = Fx;
    node->finaly = Fy;
    node->divided = false;

}
bool quadtree::equal(int Ix,int Iy,int Fx, int Fy, Node* &node){
    if(Ix != Fx && Iy != Fy){
        for( int i = Ix; i<Fx;i++){
            for(int j = Iy; i<Fy; j++){
                if (matriz[i][j]!=matriz[i][j+1])
                    return false;
            }
        }
    }
    return true;
}

void quadtree::divide(){
    divide_node(root);
}

void quadtree::divide_node(Node* &node){
    if(!(node->divided)){
        asignacion(node->nw,node->iniciox, node->finaly, node->finalx/2,node->finaly/2);
        asignacion(node->ne,node->finalx, node->finaly, node->finalx/2,node->finaly/2);
        asignacion(node->sw, node->iniciox, node->inicioy,node->finalx/2, node->finaly/2);
        asignacion(node->se,node->finalx/2,node->inicioy,node->finalx,node->finaly/2);

        node->nw->parent = node;
        node->ne->parent = node;
        node->sw->parent = node;
        node->se->parent = node;
        node->divided=true;
        //se le sacan los hijos
        
        // if(!equal(node->nw,){
        //     divide_node(node->nw,);
        // }
        // if(node->ne->width>range){
        //     divide_node(node->ne);
        // }
        // if(node->sw->width>range){
        //     divide_node(node->sw);
        // }
        // if(node->se->width>range){
        //     divide_node(node->se);
        // }
    }
}

void quadtree::display_node(Node* node){
    // if(node!=nullptr){
    //     count++;
    //     display_node(node->nw,count);
    //     display_node(node->ne,count);
    //     display_node(node->sw,count);
    //     display_node(node->se,count);
    if(node){
        for(int i=0;i<node->finalx;i++){
            std::cout << "[ ";
            for(int j=0;j<node->finaly;j++){
                std::cout << "(" << matriz[i][j] << ") ";
            }
            std::cout << "] " << std::endl;
        }
    }
    std::cout << "Intento imprimir hijo: " << std::endl;
    display_node(node->nw);
    //display_node(node->ne);
    //display_node(node->sw);
    //display_node(node->se);
    
}


void quadtree::display(){
    //int count=0;
    std::cout << "Se imprime la matriz: " << std::endl;
    display_node(root);
}