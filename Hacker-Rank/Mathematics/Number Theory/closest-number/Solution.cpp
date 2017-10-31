
#include <bits/stdc++.h>

using namespace std;

int main(){
    int T; //-- Test cases
    cin >> T;

    int a, b, x; //-- Values for each test case
    while (T--){
        cin >> a >> b >> x;
        cout << int(pow(a, b)) << '\n';
        cout << int(pow(a, b)) % x << '\n';
    }

    return 0;
}