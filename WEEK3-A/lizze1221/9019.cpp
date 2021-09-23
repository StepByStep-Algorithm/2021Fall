#include <bits/stdc++.h>
using namespace std;

int a,b;
bool visited[10000];

string bfs(){
    queue<pair<int,string>> q;
    q.push(make_pair(a,"")); 
    visited[a]=true;

    while(!q.empty()){
        int num = q.front().first;
        string str = q.front().second;  
        q.pop();

        if(num == b) return str;

        int tmp;
        
        tmp = (2 * num) % 10000;
        if(!visited[tmp]){
            visited[tmp]=true;
            q.push(make_pair(tmp, str + "D"));
        }

        tmp = num - 1;
        if(tmp < 0) tmp = 9999;
        if(!visited[tmp]){
            visited[tmp]=true;
            q.push(make_pair(tmp, str + "S"));
        }

        tmp = (num % 1000) * 10 + (num / 1000);
        if(!visited[tmp]){
            visited[tmp]=true;
            q.push(make_pair(tmp, str + "L"));
        }

        tmp = (num % 10)*1000 + (num / 10);
        if(!visited[tmp]){
            visited[tmp]=true;
            q.push(make_pair(tmp, str + "R"));
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; 
    cin >> n;

    for(int i=0;i<n;i++){
        memset(visited, false, sizeof(visited));
        cin >> a >> b;
        cout << bfs() << "\n";
    }

    return 0;
}