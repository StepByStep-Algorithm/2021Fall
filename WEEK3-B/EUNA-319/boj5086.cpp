#include <iostream>
#include <string>
using namespace std;

string trans(unsigned int a, unsigned int b);

int main() {
    unsigned int a, b;
    cin.sync_with_stdio(0);
    cin.tie(0);

    do {
        cin >> a >> b;
        if(a==0&&b==0) return 0;
        cout << trans(a, b)<<endl;
    }while(true);
    return 0;
}

string trans(unsigned int a, unsigned int b){
    if(b%a==0) return "factor";
    else if(a%b==0) return "multiple";
    else return "neither";
}
