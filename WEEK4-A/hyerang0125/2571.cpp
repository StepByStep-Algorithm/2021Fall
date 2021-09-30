// 일단 색종이 위치 표시하는 것 까지 함
// 최대 넓이를 그냥 모든 경우의 수를 해 봐야 하나?

#include <bits/stdc++.h>

using namespace std;

bool mapM[100][100];
int maxArea = 100;

// 면적 사이에 빈칸이 있을 경우(유효한 면적이 아닐 때) flase 반환
bool check(int x, int y, int dx, int dy)
{
    for (int i = x; i <= dx; i++)
    {
        for (int j = y; j <= dy; j++)
        {
            if (!mapM[i][j])
                return false;
        }
    }
    return true;
}

// 최대 면적 계산
void area_c()
{
    for (int x = 0; x < 100; x++)
    {
        for (int y = 0; y < 100; y++)
        {
            // 색종이 구역 아니면 pass
            if (!mapM[x][y])
                continue;
            for (int dx = x + 1; dx < 100; dx++)
            {
                for (int dy = y + 1; dy < 100; dy++)
                {
                    if (!mapM[dx][dy])
                        break;
                    int tempA = (dx - x + 1) * (dy - y + 1);
                    // 계산한 면적이 maxArea 보다 작으면 검사할 필요 x
                    if (tempA <= maxArea)
                        continue;
                    if (check(x, y, dx, dy))
                        maxArea = tempA;
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x, y;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        for (int dx = 0; dx < 10; dx++)
        {
            for (int dy = 0; dy < 10; dy++)
            {
                mapM[x + dx][y + dy] = true;
            }
        }
    }

    /*
    //색종이 잘 채워졌나 확인
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (mapM[i][j])
            {
                cout << "*";
            }
            else
                cout << " ";
        }
        cout << "\n";
    }
    */

    area_c();

    cout << maxArea;

    return 0;
}