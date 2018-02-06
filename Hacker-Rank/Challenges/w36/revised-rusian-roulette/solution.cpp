#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vInt;
typedef pair<int, int> pInt;

std::ostream& operator<<(std::ostream& out, const vInt& f){
    for(int i=0; i<f.size(); i++)
        out << f[i] << " ";
    return out;
}

pInt revisedRussianRoulette(vInt array){
    int min = 0;
    int max = 0;
    vInt copyArray = array;
    for (int i=0; i<array.size(); i++){
        if (copyArray[i] == 1 && i <= array.size()-2){
            if (copyArray[i+1] == 1){
                copyArray[i] = 0;
                copyArray[i+1] = 0;
            }else{
                copyArray[i] = 0;
            }
            min++;
        }else if (copyArray[i] == 1){
            copyArray[i] == 0;
            min++;
        }
    }
    copyArray = array;
    for (int i=array.size()-1; i>=0; i--){
        if (copyArray[i] == 1){
            copyArray[i] = 0;
            max++;
        }
    }
    return make_pair(min, max);
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n, value;
    vInt array;
    cin >> n;
    array.resize(n, 0);
    for(int i=0; i<n; i++)
        cin >> array[i];
    pInt result = revisedRussianRoulette(array);
    cout << result.first << " " << result.second << endl;
    return 0;
}