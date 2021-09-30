// (1, 1) 부터 타일을 채워나가는 방식을 사용하려 함

#include <bits/stdc++.h>

using namespace std;

int MAP[128][128];

void draw(int row, int col)
{

    // ㄴ
    if (row - 1 >= 0 && col)

    // ㄱ

    // ㄱ 대칭

    // ㄴ 대칭
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(MAP, 0, sizeof(MAP));
    int k, x, y;

    cin >> k;
    cin >> x >> y;
    MAP[x][y] = -1; // 하수구 위치 표시

    return 0;
}