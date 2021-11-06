#include <iostream>
#include <stack>

using namespace std;

stack<int> bin;
long long N;
void makeBin(long long N);

int main(){
    cin >> N;
    makeBin(N);

    if (bin.top() == 0) bin.pop();

    while(bin.empty() != 1){
        cout << bin.top();
        bin.pop();
   }

    return 0;
}

void makeBin(long long N){
    if(N == 0) return;
    
    bin.push(N % 2);
    N /= 2;
    makeBin(N);
}