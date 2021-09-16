#include <bits/stdc++.h>
using namespace std;

int n;
int tmp = 9;
long long arr[1000001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i=1;i<10;i++) arr[i] = i;

    for(int i=1;i<=n;i++){
        for(int j=0;j<(arr[i]%10);j++){
            arr[++tmp] = arr[i]*10 + j;
        }
    }

    if(arr[n]!=0 && tmp >= n) cout << arr[n]<<"\n";
    else cout <<"-1\n";

    return 0;
}