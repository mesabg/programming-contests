#include <bits/stdc++.h>
using namespace std;

/**
 * Matrix and vector creation
 */

int main(){

    //-- Creating a vector
    vector< int* > *myVector;
    myVector = new vector < int* >(5, new int(2) );
    cout << "Vector\n";
    for (int i=0; i<myVector->size(); i++)
        cout << *(myVector->at(i)) << " ";
    cout << "\n\n";

    //-- Creating a matrix
    vector< vector< int* >* >* myMatrix;
    myMatrix = new vector< vector< int* >* >(5, new vector< int* >(5, new int(4)) );
    cout << "Matrix\n";
    for (int i=0; i<myMatrix->size(); i++){
        for (int j=0; j<myMatrix->size(); j++)
            cout << *(myMatrix->at(i)->at(j)) << " ";
        cout << '\n';
    }
}