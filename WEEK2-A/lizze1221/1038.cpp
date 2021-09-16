#include <bits/stdc++.h>
using namespace std;

int n;
queue <long long> q;
long long arr[1000001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i=1;i<10;i++) {
        q.push(i);
        arr[i] = i;
    }

    if(n >=0 && n < 10) cout << arr[n];
    else if (n < 0) cout <<"-1";
    else{
       int tmp = 9;

       while(tmp <= n){
           long long num = q.front();
           q.pop();

           for(int i=0;i<num;i++){
               q.push(num*10 + i);
               arr[++tmp] = num*10 + i;
           }
       }
       cout << arr[n] <<"\n";
    }
    return 0;
}