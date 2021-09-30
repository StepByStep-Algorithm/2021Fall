#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

int _map[8][8] = {
    0,
};
queue<ii> birus;
queue<ii> startbirus;
vector<ii> zero;
int N, M;

int WALL();
int birusCnt(int a[][8]);
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //N은 세로크기 M은 가로크기
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> _map[i][j];
            if (_map[i][j] == 2)
                //확산될 최초 바이러스 저장
                startbirus.push(ii(i, j));
            if (_map[i][j] == 0)
                //벽세울 수 있는 후보 저장
                zero.push_back(ii(i, j));
        }
    }
    cout << WALL();
}

//nextpermutation stl을 활용한 벽 세울 수 있는 모든 경우의 수 탐색
int WALL()
{
    //원형 보존을 위해 copy
    int copymap[8][8];
    copy(&_map[0][0], &_map[0][0] + 64, &copymap[0][0]);

    //permutation 돌 vector
    vector<int> tempVector;

    int max = 0;
    for (int i = 0; i < 3; i++)
    {
        tempVector.push_back(1);
    }

    for (int i = 0; i < zero.size() - 3; i++)
    {
        tempVector.push_back(0);
    }

    sort(tempVector.begin(), tempVector.end());

    do
    {
        for (int i = 0; i < tempVector.size(); i++)
        {
            if (tempVector[i] == 1)
            {
                //해당조합에 대해서 map에서 벽을 세워줌
                copymap[zero[i].first][zero[i].second] = 1;
            }
        }
        //count
        int tmp = birusCnt(copymap);
        //max update
        if (tmp > max)
        {
            max = tmp;
        }
        //copymap 초기화
        copy(&_map[0][0], &_map[0][0] + 64, &copymap[0][0]);
    } while (next_permutation(tempVector.begin(), tempVector.end()));
    return max;
}

// BFS를 이용한 바이러스 확산 및 안전구역 개수 세기
int birusCnt(int a[][8])
{
    int copymap[8][8];
    int count = 0;
    //원형 보존을 위한 큐 복사
    birus = startbirus;
    // 배열도 마찬가지
    copy(&a[0][0], &a[0][0] + 64, &copymap[0][0]);

    //확산할 바이러스가 없을 때까지
    while (!birus.empty())
    {
        //큐에서 첫번째 원소 좌표 꺼내오기
        int x = birus.front().first;
        int y = birus.front().second;
        birus.pop();
        //그 좌표의 상하좌우 검사 후 해당하면 push
        if (x < N - 1 && copymap[x + 1][y] == 0)
        {
            copymap[x + 1][y] = 2;
            birus.push(ii(x + 1, y));
        }
        if (x > 0 && copymap[x - 1][y] == 0)
        {
            copymap[x - 1][y] = 2;
            birus.push(ii(x - 1, y));
        }
        if (y < M - 1 && copymap[x][y + 1] == 0)
        {
            copymap[x][y + 1] = 2;
            birus.push(ii(x, y + 1));
        }
        if (y > 0 && copymap[x][y - 1] == 0)
        {
            copymap[x][y - 1] = 2;
            birus.push(ii(x, y - 1));
        }
        // cout << "\n\n";
        // for (int i = 0; i < N; i++)
        // {

        //     for (int j = 0; j < M; j++)
        //     {
        //         cout << copymap[i][j] << " ";
        //         if (copymap[i][j] == 2)
        //         {
        //             count++;
        //         }
        //     }
        //     cout << "\n";
        // }
    }
    // cout << "\n\n";

    //0의 개수 세기 (안전구역 면적 구하기)
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            // cout << copymap[i][j] << " ";
            if (copymap[i][j] == 0)
            {
                count++;
            }
        }
        // cout << "\n";
    }
    return count;
}
