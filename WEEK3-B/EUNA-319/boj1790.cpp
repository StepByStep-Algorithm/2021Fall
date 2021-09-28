#include <iostream>
#include <cstring>
using namespace std;
bool checkNum[21];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie();
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        int x;
        string str;
        cin>>str;
        if (str=="add") {
            cin>>x;
            checkNum[x]=true;
        } else if (str=="remove") {
            cin>>x;
            checkNum[x]=false;
        } else if (str=="check") {
            cin>>x;
            checkNum[x] ? (puts("1")) : (puts("0"));
        } else if (str=="toggle") {
            cin>>x;
            checkNum[x] ? (checkNum[x]=false) : (checkNum[x]=true);
        } else if (str=="all") {
            memset(checkNum, true, sizeof(checkNum));
        } else {
            memset(checkNum, false, sizeof(checkNum));
        }
    }
    return 0;
}

