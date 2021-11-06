#include <iostream>
#include <set>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M, x;
    string oper;
    set<int> S;
    set<int>::iterator it;

    cin >> M;

    for(int i = 0 ; i < M ; i++){
        cin >> oper >> x;

        if(oper =="add"){
            S.insert(x);
        }else if(oper == "remove"){
            S.erase(x);
        }else if(oper == "check"){
            it = S.find(x);
            if( it != S.end()){
                cout << 1 << "\n";
            }else{
                cout << 0 << "\n";
            }
        }else if(oper == "toggle"){
            it = S.find(x);
            if( it != S.end()){
                S.erase(x);
            }else{
                S.insert(x);
            }
        }else if(oper == "all"){
            S.clear();

            for(int n = 1 ; n <= 20 ; n++){
                S.insert(n);
            }
        }else if(oper == "empty"){
            S.clear();
        }

    }


    return 0;
}