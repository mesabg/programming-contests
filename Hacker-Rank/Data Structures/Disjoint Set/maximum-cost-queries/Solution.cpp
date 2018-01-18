#include <bits/stdc++.h>

namespace Graphs {
    using namespace std;

    /**
     * BaseNode Class definition
     */
    template <typename T = int>
    class BaseNode{
    private:
        T* value;
        
    public:
        //-- Initialization
        BaseNode(){ this-> value = new T(); }
        BaseNode(T value){ this->value = new T(value); }
    
        //-- getters & setters
        T getValue(){ return *(this->value); }
        void setValue(T value){ this->value = new T(value); }
    };


    /**
     * BaseGraph class definition
     */
    template <typename T = int>
    class BaseGraph{
    private:
        vector< vector< BaseNode<T>* >* >* adjacency;
        int* size;
    
    public:
        //-- Initialization
        BaseGraph(int size = 0){
            this->size = new int(size);
            this->adjacency = new vector< vector< BaseNode<T>* >* >();
            for(int i=0; i<size; i++){
                vector< BaseNode<T>* > *col = new vector< BaseNode<T>* >();
                for (int j=0; j<size; j++)
                    col->push_back( new BaseNode<T>() );
                this->adjacency->push_back( col );
            }
        }
    
        //-- getters & setters 
        int getSize(){ return *(this->size); }
        T getWeigth(int u, int v){ return this->adjacency->at(u)->at(v)->getValue(); }
        void setWeigth(int u, int v, T weigth){ this->adjacency->at(u)->at(v)->setValue(weigth); }

        //-- general functions
        vector<int>* getAdjacents(int u, T exclude){
            vector<int> *result = new vector<int>();
            for (int i=0; i<this->getSize(); i++)
                if (this->getWeigth(u, i) != exclude)
                    result->push_back(i);
            return result;
        }

        //-- Overloads
        //-- print (<< function)
        friend std::ostream& operator<<(std::ostream& os, const BaseGraph<T>& baseGraph){
            int size = *(baseGraph.size);
            for(int u=0; u<size; u++){
                for(int v=0; v<size; v++)
                    os << baseGraph.adjacency->at(u)->at(v)->getValue() << ' ';
                os << "\n";
            }
            return os;
        }
    };


    /**
     * SetNode Class definition
     */
    template <typename T = int>
    class SetNode{
    public:
        T data;
        SetNode<T*> *parent;
        int rank;
        int elements;

        SetNode(){
            this->parent = NULL;
            this->rank = 0;
            this->elements = 0;
        }
    };
    

    /**
     * DisjointSet Class definition <T>
     */
    template <typename T = int>
    class DisjointSet{
    private:
        map< T, SetNode<T>* > hashMap;
    
        SetNode<T>* findSet(SetNode<T> *node){
            if (node == NULL) return NULL;
    
            SetNode<T>* parent = node->parent;
            if (parent == node) return parent;
            node->parent = this->findSet(node->parent);
            return node->parent;
        }
    public:
        DisjointSet(){}
    
        void makeSet(T data){
            SetNode<T>* node = new SetNode<T>();
            node->data = data;
            node->parent = node;
            node->rank = 0;
            node->elements = 1;
            this->hashMap[data] = node;
        }
    
        void makeUnion(T data1, T data2){
            SetNode<T> *node1 = this->hashMap[data1];
            SetNode<T> *node2 = this->hashMap[data2];
    
            SetNode<T> *parent1 = this->findSet(node1);
            SetNode<T> *parent2 = this->findSet(node2);
    
            if (parent1 == parent2) return;
    
            if (parent1->rank >= parent2->rank){
                parent1->rank = (parent1->rank == parent2->rank) ? parent1->rank + 1 : parent1->rank;
                parent1->elements += parent2->elements;
                parent2->parent = parent1;
            }else{
                parent2->elements += parent1->elements;
                parent1->parent = parent2;
            }
        }
    
        T findSet(T data){
            SetNode<T> *set = this->findSet(this->hashMap[data]);
            return set == NULL ? NULL : set->data;
        }
    
        int size(T data){
            SetNode<T> *set = this->findSet(this->hashMap[data]);
            return set->elements;
        }
    };
};



#define INFINITO INT_MAX
#define VISITADO true
using namespace std;
using namespace Graphs;

DisjointSet<int>* dfs(BaseGraph<int>* graph, int source){
    int size = graph->getSize();

    //-- declarations
    vector<bool> estado(size, !VISITADO);
    vector<int> distancia(size, INFINITO);
    DisjointSet<int>* maxCost;

    //-- Initial states
    estado[source] = VISITADO;
    distancia[source] = 0;
    maxCost = new DisjointSet<int>();

    stack<int> S;
    S.push(source);

    int u;
    vector<int> *adjacents;
    while (!S.empty()){
        u = S.top();
        S.pop();
        adjacents = graph->getAdjacents(u, 0);
        
        //-- Process each adjacent
        for (int v : *adjacents){
            if (estado[v] == !VISITADO){
                estado[v] = VISITADO;
                distancia[v] = max( distancia[u], graph->getWeigth(u, v) );
                //maxCost->
                S.push(v);
            }
        }
    }

    return maxCost;
}

int main(){
    BaseGraph<>* T;
    vector<int>* maxCost;
    int N, Q;
    int U, V, W;
    int L, R;

    //-- Read size and amount of queries
    scanf("%d %d", &N, &Q);
    T = new BaseGraph<>(N);
    

    //-- Read Graph T
    for (int i=0; i<N-1; i++){
        scanf("%d %d %d", &U, &V, &W);
        T->setWeigth(U-1, V-1, W);
        T->setWeigth(V-1, U-1, W);
    }

    DisjointSet<int> *set = dfs(T, 0);

    map< int, int* > hashMap;
    //cout << hashMap[0] << endl;

    //-- Read queries
    for (int i=0; i<Q; i++){
        scanf("%d %d", &L, &R);
    }

    cout << *T;
}