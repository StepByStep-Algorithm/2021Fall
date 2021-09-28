#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
int N, M;
queue<iii> q;
int visited[1000][1000][2] = {
    0,
}; //visited는 해당 정점까지의 최단경로를 저장하며, 2는 오는 동안 벽을 부순 세계와 안 부순 세계로 나누는 역할
int _map[1000][1000] = {
    0,
};
void printArray(int a[][1000]);
void BFS();
int main()
{

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%1d", &_map[i][j]);
        }
    }
    BFS();
}

void printArray(int a[][1000])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n\n";
}
void BFS()
{
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    q.push(iii(ii(0, 0), 0));
    visited[0][0][0] = 1;

    while (!q.empty())
    {
        // printArray(visited);
        iii tmp = q.front();
        q.pop();
        if (tmp.first.first == N - 1 && tmp.first.second == M - 1)
        {
            cout << visited[tmp.first.first][tmp.first.second][tmp.second];
            return;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = tmp.first.first + dx[i];
            int ny = tmp.first.second + dy[i];
            if ((nx < 0) || (ny < 0) || (nx >= N) || (ny >= M))
                continue;
            if (visited[nx][ny][tmp.second] == 0)
            {
                //해당 공간이 비었다면 기존 벽뚫기 여부 그대로 가지고 거리만 +1
                if (_map[nx][ny] == 0)
                {
                    q.push(iii(ii(nx, ny), tmp.second));
                    visited[nx][ny][tmp.second] = visited[tmp.first.first][tmp.first.second][tmp.second] + 1;
                }

                //해당 공간이 벽이고, 벽 뚫은 적이 없다면, 벽뚫고 거리 +1
                else if (_map[nx][ny] == 1 && tmp.second == 0)
                {
                    q.push(iii(ii(nx, ny), 1));
                    visited[nx][ny][1] = visited[tmp.first.first][tmp.first.second][tmp.second] + 1;
                }
            }
        }
    }
    cout << -1;
    return;
}
