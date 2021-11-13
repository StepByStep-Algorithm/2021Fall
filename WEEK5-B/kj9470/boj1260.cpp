// BOJ 1260번 : DFS와 BFS
#include <iostream>
#include <queue>
using namespace std;
int n, m, v;
int map[1001][1001];
int visit[1001];
queue<int> que;

void reset();
void DFS(int v);
void BFS(int v);

int main() {
    cin >> n >> m >> v;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        map[a][b] = 1; // 간선 존재
        map[b][a] = 1; // 양방향이므로 반대도 고려
    }

    reset(); // 방문 노드 배열 초기화
    DFS(v);

    cout << "\n";

    reset(); // 방문 노드 배열 초기화
    BFS(v);
}

void reset(){
    for(int i = 1; i <= n; i++){
        visit[i] = 0; // 방문 노드 초기화
    }
}

void DFS(int v){ // 깊이 우선 탐색
    visit[v] = 1; // 방문한 노드 1
    cout << v << " "; // 방문 노드 출력

    for(int i = 1; i <= n; i++){
        if(map[v][i] == 1 && visit[i] == 0){ // 간선이 존재하고, 방문하지 않은 노드
            DFS(i); // 재귀호출
        }
    }
}

void BFS(int v){ // 너비 우선 탐색
    que.push(v); // 큐에 push
    visit[v] = 1; // 방문 노드 표시
    cout << v << " "; // 방문 노드 출력

    while(!que.empty()){ // 큐가 빌 때까지 반복
        v = que.front(); // v에 큐의 맨 앞을 넣음 (top)
        que.pop(); // 제거

        for(int i = 1; i <= n; i++){
            if(map[v][i] == 1 && visit[i] == 0){ // 간선이 존재하고, 방문하지 않은 노드
                que.push(i); // 큐에 push
                visit[i] = 1; // 방문 노드 표시
                cout << i << " "; // 방문 노드 출력
            }
        }
    }
}
