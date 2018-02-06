#include <bits/stdc++.h>
using namespace std;

int fib[20];
void fibonacci(){
    int f0 = 0;
    int f1 = 1;
    int temp = 0;
    fib[0] = f0;
    fib[1] = f1;
    for(int i=2; i<20; i++){
        temp = f0 + f1;
        f0 = f1;
        f1 = temp;
        fib[i] = f1;
    }
}

bool inFib(int i){
    return 
        i==0 || 
        i==1 ||
        i==2 ||
        i==3 ||
        i==5 ||
        i==8 ||
        i==13 ||
        i==21 ||
        i==34 ||
        i==55 ||
        i==89 ||
        i==144 ||
        i==233 ||
        i==377 ||
        i==610 ||
        i==987;
}

int main(){
    int n;
    cin >> n;
    string name;
    for(int i=1; i<=n; i++){
        if ( inFib(i) ) name += "O";
        else name += "o";
    }
    cout << name << endl;
}