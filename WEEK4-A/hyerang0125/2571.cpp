// 일단 색종이 위치 표시하는 것 까지 함
// 최대 넓이를 그냥 모든 경우의 수를 해 봐야 하나?

#include <bits/stdc++.h>

using namespace std;

bool mapM[100][100];
int maxArea = 100;

void area_check()
{
    for (int maxX = 0; maxX < 100; maxX++)
    {
        
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

    int xMax, yMax;
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

    return 0;
}