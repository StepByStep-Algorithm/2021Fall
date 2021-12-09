#include <bits/stdc++.h>
using namespace std;

int main(){
    int x, y;
    while(1){
        cin >> x >> y;
        if(x==0 && y==0) break;
        if(x%y==0) cout << "multiple" << '\n';
        else if(y%x==0) cout << "factor" << '\n';
        else cout << "neither" << '\n';
        }
    return 0;
}