#include <bits/stdc++.h>

using namespace std;

char star[3072][6413];

void draw(int len, int row, int col)
{
    // 삼각형 높이가 3인 상태로 만들고 별 넣기
    if (len == 3)
    {
        star[row][col] = '*';
        star[row + 1][col - 1] = star[row + 1][col + 1] = '*';
        for (int i = 0; i < 5; i++)
            star[row + 2][col - 2 + i] = '*';
        return;
    }

    // 작은 삼각형으로 분할하기
    draw(len / 2, row, col);                     //위치는 똑같고 높이 줄이기
    draw(len / 2, row + len / 2, col - len / 2); // 위로 올라가고 왼쪽으로 이동 + 높이 줄이기
    draw(len / 2, row + len / 2, col + len / 2); // 위로 올라가고 오른쪽으로 이동 + 높이 줄이기
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(star, ' ', sizeof(star));
    int n;
    cin >> n;

    draw(n, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2 * n - 1; j++)
        {
            cout << star[i][j];
        }
        cout << "\n";
    }

    return 0;
}