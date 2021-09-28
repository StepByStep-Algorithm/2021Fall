#include <bits/stdc++.h>

using namespace std;

struct point
{
    int prev;
    char state;
    int visited = -1;
};

char dslrArr[4] = { 'D', 'S', 'L', 'R' };

int dslrResult(int type, int num) 
{
    int tmp;
    switch (type) 
    {
        case 0 :
            return (num* 2) % 10000;
        case 1 :
            if (num == 0)
                return 9999;
        else
            return num - 1;
        case 2 :
            tmp = num / 1000;
            return (num - tmp * 1000) * 10 + tmp;
        case 3 :
            return (num % 10) * 1000 + num / 10;
    }
}

void getAnswer(vector<char>& ans, point* memo, int a, int b)
{ 
    int idx = b;
    while (1)
    {
        if (idx == a) 
        break;
        ans.push_back(memo[idx].state);
        idx = memo[idx].prev;
    }
}

int main() 
{
    // 입력 속도 업
	ios::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int A; int B;
        cin >> A >> B;

        int flag = 0;
        vector<char> answer;
        point memo[10001];
        queue<int> que; 

        que.push(A);
        memo[A].visited = 1;
        while (!que.empty()) 
        {
            int tmp = que.front(); que.pop();
            for (int i = 0; i < 4; i++)
            {
                if (tmp == 0 && i != 1) 
                    continue;

                int res = dslrResult(i, tmp);
                if (memo[res].visited != -1)
                {
                    continue;
                }

                memo[res].prev = tmp;
                memo[res].state = dslrArr[i];
                memo[res].visited = 1;

                if (res == B)
                {
                    getAnswer(answer, memo, A, B);
                    flag = 1;
                    break;
                } 
                else
                {
                    que.push(res);
                }
            }
            if (flag)
                break;
        }
        for (int i=answer.size()-1; i >= 0; i--) 
        {
            cout << answer[i];
        }
        cout << '\n';
    }
}