#include <bits/stdc++.h>
using namespace std;
vector<int> relation[502]; //친구관계를 저장하는 벡터 배열(사실상 이차원 배열)
int _visit[502] = {
    0,
}; //i번째 사람의 결혼식 방문 여부를 저장하는 배열

void findFriends();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    int count = 0;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        //a와 b가 친구라면 서로의 친구 list(vector)에 서로를 넣어준다.
        relation[a].push_back(b);
        relation[b].push_back(a);
    }
    findFriends();
    for (int i = 2; i <= n + 1; i++)
    //1은 상근이 본인이므로 2번째 사람부터 탐색하여 결혼식 참여 인원을 센다.
    {
        if (_visit[i])
            count++;
    }
    cout << count;
}

void findFriends()
{
    for (int i = 0; i < relation[1].size(); i++) //상근이 친구 탐색
    {
        int tmp = relation[1][i];
        _visit[tmp] = 1;                               //상근이 친구는 무조건 참석
        for (int j = 0; j < relation[tmp].size(); j++) //친구의 친구 탐색
        {
            _visit[relation[tmp][j]] = 1;
        }
    }
}