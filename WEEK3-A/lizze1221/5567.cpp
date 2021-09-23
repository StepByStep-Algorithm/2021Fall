#include <bits/stdc++.h>
using namespace std;

int n,m;
int arr[501][501];
bool visited[501];
bool isFriend[501];
int cnt = 0;

void bfs(){
    for(int i=2;i<=n;i++){
        if(arr[1][i] == 1) {
            visited[i] = true;
            isFriend[i] = true;
        }
    } //상근이 친구
    for(int i=2;i<=n;i++){
        if(isFriend[i]){
            for(int j = 1; j<=n;j++){
                if(arr[i][j] == 1) visited[j] = true;
            }
        }
    }
    for(int i=2;i<=n;i++){
        if(visited[i] == true) cnt++;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    cin >> m;
    while(m-- > 0){
        int a, b;
        cin >> a >> b;
        arr[a][b] = arr[b][a] = 1;
    }

    bfs();
    cout << cnt;

    return 0;
}