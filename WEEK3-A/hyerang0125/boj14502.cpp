#include <bits/stdc++.h>

using namespace std;

int n, m, cntM = 0;
int mapL[8][8];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void bfs()
{
    int x, y, mx, my, cnt;
    int virus[8][8];
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            virus[i][j] = mapL[i][j];
            if (virus[i][j] == 2)
            { //바이러스 위치 저장
                q.push({i, j});
            }
        }
    }
    while (!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) //바이러스 상하좌우로 이동
        {
            mx = x + dx[i];
            my = y + dy[i];
            if (0 <= mx && mx < n && 0 <= my && my < m)
            {
                if (virus[mx][my] == 1 || virus[mx][my] == 2) //감염상태거나 벽이면 continue
                    continue;
                virus[mx][my] = 2; //감염
                q.push({mx, my});
            }
        }
    }
    cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (virus[i][j] == 0)
                ++cnt;
        }
    }
    cntM = max(cntM, cnt); //안전지대 최대값 저장
}

void make_wall(int cnt)
{
    if (cnt == 3) //벽은 무조건 3개 세우는 것이므로 3개가 되었을 때 안전지대 검사
    {
        bfs();
        return;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mapL[i][j] == 2 || mapL[i][j] == 1)
                continue;
            mapL[i][j] = 1;
            make_wall(cnt + 1);
            mapL[i][j] = 0;
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

    make_wall(0);

    cout << cntM;

    return 0;
}