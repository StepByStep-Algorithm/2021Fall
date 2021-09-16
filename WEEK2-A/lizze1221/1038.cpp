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

    queue <long long> q;
    for(int i=1;i<10;i++) {
        arr[i] = i;
        q.push(i);
    }

     if (0 <= n && n <= 10) {
        cout << n << endl;
        return 0;
    }

    while (tmp <= n && !q.empty()){
        long long num = q.front();
        q.pop();
 
        for (int i = 0; i < num % 10; i++){
            q.push(num * 10 + i);
            arr[++tmp] = num * 10 + i;
        }
    }
 
    if (tmp >= n && arr[n] != 0) cout << arr[n] << "\n";
    else cout << "-1\n";

    return 0;
}