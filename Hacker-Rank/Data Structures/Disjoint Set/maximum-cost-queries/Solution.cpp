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
    
        //-- General functions
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
        BaseGraph(){}
        BaseGraph(int size){
            this->size = new int(size);
            this->adjacency = new vector< vector< BaseNode<T>* >* >(size, new vector< BaseNode<T>* >(size, new BaseNode<T>() ) );
        }
    
        //-- General functions
        int getSize(){ return *(this->size); }
        T getWeigth(int u, int v){ return this->adjacency->at(u)->at(v)->getValue();}

        //-- Overloads
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
};





using namespace std;
using namespace Graphs;

void bfs(BaseGraph<int> graph, BaseNode<int> source){

}

int main(){
    BaseGraph<>* myGraph;
    myGraph = new BaseGraph<>(4);
    cout << *myGraph;
}