#include <iostream>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int s[21] = {0,};
    int M, x;
    string oper;

    cin >> M;

    for(int i = 0 ; i < M ; i++){
        cin >> oper;
        //cout << oper << "\n";

        if(oper =="add"){
            cin >> x;
            s[x] = 1;

        }else if(oper == "remove"){
            cin >> x;
            s[x] = 0;

        }else if(oper == "check"){
            cin >> x;
            if( s[x] == 1){
                cout << 1 << "\n";
            }else{
                cout << 0 << "\n";
            }

        }else if(oper == "toggle"){
            cin >> x;

            if( s[x] == 1){
                s[x] = 0;
            }else{
                s[x] = 1;
            }

        }else if(oper == "all"){
            for(int n = 1 ; n <= 20 ; n++){
                s[n] = 1;
            }

        }else if(oper == "empty"){
            for(int n = 1 ; n <= 20 ; n++){
                s[n] = 0;
            }

        }

    }


    return 0;
}