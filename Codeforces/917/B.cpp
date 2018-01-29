#include <bits/stdc++.h>
using namespace std;

vector<string> names, ip_names, command, ip_command;
int n, m;

string findName(string ip){
    if (ip[ip.size() - 1] == ';')
        ip.pop_back();
        
    for(int i=0; i<n; i++){
        if(ip == ip_names[i])
            return names[i];
    }
    return "";
}

int main(){
    cin >> n >> m;
    string name, ip;

    for(int i=0; i<n; i++){
        cin >> name >> ip;
        names.push_back(name);
        ip_names.push_back(ip);
    }


    for(int i=0; i<m; i++){
        cin >> name >> ip;
        command.push_back(name);
        ip_command.push_back(ip);
    }

    string found;
    for(int i=0; i<m; i++){
        found = findName(ip_command[i]);
        cout << command[i] << " " << ip_command[i] << " #" << found << endl;
    }
}