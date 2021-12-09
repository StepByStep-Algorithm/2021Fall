#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;
    string croatia[8] = {"c=", "c--", "dz=", "d=", "lj", "nj", "s=", "z="};
    for (int i = 0; i < 8; i++) {
        while(true){
            int idx = str.find(croatia[i]);
            if (idx == string::npos)break;
            str.replace(idx, croatia[i].length(), "a");
        }
    }
    cout << str.length();
    return 0;
}