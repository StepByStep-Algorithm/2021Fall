#include <iostream>
using namespace std;

int length(unsigned int a);

int main() {
    int n,k,len=0,i,j;
    cin>>n>>k;

    for(i=1;i<=n;i++) {
        len += length(i);
        if (len >= k) break;
    }
    if(len == k){
        cout<<i%10;
    }
    else if(k>len) cout<< -1;
    else{
        for(j=0; j<len-k; j++){
            i /= 10;
        }
        cout<<i%10;
    }
}

int length(unsigned int a){
    int sum=0;
    while(a>0){
        sum++;
        a/=10;
    }
    return sum;
}
