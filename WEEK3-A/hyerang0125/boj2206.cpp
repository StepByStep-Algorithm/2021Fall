#include <bits/stdc++.h>

using namespace std;

int n, m, cntM = 987654321;
int mapL[1000][1000];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void bfs()
{
    int x, y, mx, my, cnt;
    bool flag;
    queue<pair<int, int>> q;
    bool check[1000][1000];
    memset(check, false, sizeof(check));
    q.push({0, 0});
    check[0][0] = true;
    cnt = 0;
    while (!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        if (x == n - 1 && y == m - 1)
        {
            cntM = min(cntM, cnt);
            return;
        }
        flag = false;
        for (int i = 0; i < 4; i++) //갔다가 아닌거에서 오류남 미치겠음 그냥 내가 벽을 부수고 싶은 심정임
        {
            mx = x + dx[i];
            my = y + dy[i];
            if (0 <= mx && mx < n && 0 <= my && my < m)
            {
                if (mapL[mx][my] == 1 || check[mx][my])
                    continue;
                ++cnt;
                flag = true;
                check[mx][my] = true;
                q.push({mx, my});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mapL[i][j];
        }
    }

    bfs(); //원래 최단거리

    //벽 부수고 최단거리
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mapL[i][j] == 0)
                continue; //벽 아니면 바꿀 필요 x
            mapL[i][j] = 0;
            bfs();
            mapL[i][j] = 1;
        }
    }

    if (cntM == 987654321)
        cout << "-1";
    else
        cout << cntM;

    return 0;
}