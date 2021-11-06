#include <iostream>

using namespace std;
int num, temp, call;

int is3(int N);

int main(){
    cin >> num;
    call = 0;
    
    int isMultipleof3 = is3(num);

    cout << call << "\n";
    if(isMultipleof3 == 1) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}

int is3(int N){
    temp = 0;

    if(N < 10){
        if ( N == 3 || N == 6 || N == 9 ) return 1;
        else return 0;
    }

    while(N > 0){
        temp += N % 10;
        N /=10;
    }
    
    call++;
    is3(temp);

    return -1;
}