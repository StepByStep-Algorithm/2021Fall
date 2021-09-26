#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main(){
    int tc, x;
    string func;
    int alp[21] = {0, };
    string function[6] = {"add", "remove", "check", "toggle", "all", "empty"};
    cin >> tc;
    for(int i=0; i<tc; i++){
        cin >> func;
        for(int j=0; j<6; j++){
            int idx = (func == function[i]);
            switch(idx){
                case 1:  // add
                cin >> x;
                alp[x] = 1;
                break;
                // x 있으면 continue
                case 2:  // remove
                cin >> x;
                alp[x] = 0;
                break;////
                case 3: // check
                cin >> x;
                int state = alp[x]==1 ? 1 : 0;
                cout << state << '\n';
                case 4: // toggle
                cin >> x;
                alp[x]==1 ? alp[x]=0 : alp[x]=1;
                case 5: // all
                for(int i=0; i<21; i++)
                    alp[i]=1;
                case 6: //empty
                for(int i=0; i<21; i++)
                    alp[i]=1;
            }
        }
    }
    return 0;
}
