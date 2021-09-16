#include <bits/stdc++.h>
using namespace std;

int n;
int tmp = 9;
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

    while(tmp <= n){
        long long num = q.front();
        q.pop();

        for(int i=0;i<num%10;i++){
            q.push(num*10 + i);
            arr[++tmp] = num*10 + i;
        }
    }

    if(!arr[n] && n) cout <<"-1\n";
    else cout << arr[n]<<"\n";
    
    return 0;
}