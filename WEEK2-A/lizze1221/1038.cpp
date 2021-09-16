#include <bits/stdc++.h>
using namespace std;

int n;
queue <long long> q;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    if(n >0 && n < 10) cout << n;
    else if (n < 0) cout <<"-1";
    else{
       int tmp = 0;

       for(int i=1;i<10;i++) q.push(i);
       while(++tmp < n){
           long long num = q.front();
           q.pop();

           for(int i=0;i<num;i++) q.push(num*10 + i);
       }
       cout << q.front()<<"\n";
    }
    return 0;
}