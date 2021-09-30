#include <bits/stdc++.h>
using namespace std;
typedef pair<int, string> is;

void func(int start, int object);
int func_D(int n);
int func_S(int n);
int func_L(int n);
int func_R(int n);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    int start, object;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> start >> object;
        func(start, object);
    }
}

void func(int start, int object) //BFS를 이용하여 경우의 수를 확장해 나가자
{
    //bfs시 쓸 큐 선언
    //큐에는 연산을 거친 후의 값과, 지금까지의 연산을 갖고 있는 문자열 pair가 들어감
    queue<is> q;
    bool visit[10000] = {
        0,
    }; //이미 나왔던 숫자가 다시 나왔을 경우 무한루프에 빠지므로 걸러준다.

    is result = is(start, "");
    //최초 push
    q.push(result);
    //front에 있는 값을 4개 연산해서 다시 push(반복)
    while (!q.empty()) //큐가 비는 순간까지 반복
    {
        result = q.front(); //맨 앞 숫자 조회
        // cout << result.first << result.second << "\n";
        if (!visit[result.first]) //한번도 나온적이 없는 숫자라면
        {
            visit[result.first] = true; //체크해주고
            //4가지 연산해서 답인지 아닌지 확인하고 push해서 넣어줌
            int d = func_D(result.first);
            int s = func_S(result.first);
            int l = func_L(result.first);
            int r = func_R(result.first);
            //답이라면 지금까지 더해온 문자열에 현재 연산 더해서 출력
            if (d == object)
            {
                cout << result.second + "D"
                     << "\n";
                return;
            }
            if (s == object)
            {
                cout << result.second + "S"
                     << "\n";
                return;
            }
            if (l == object)
            {
                cout << result.second + "L"
                     << "\n";
                return;
            }
            if (r == object)
            {
                cout << result.second + "R"
                     << "\n";
                return;
            }
            q.push(is(d, result.second + "D"));
            q.push(is(s, result.second + "S"));
            q.push(is(l, result.second + "L"));
            q.push(is(r, result.second + "R"));
        }
        q.pop(); //이미 조회한 front는 pop해서 없애줌
    }
    q = queue<is>(); //메모리 초과때문에 혹시 몰라 해주는 큐 초기화

    return;
}

int func_D(int n)
{
    return n * 2 > 9999 ? n * 2 % 10000 : n * 2;
}
int func_S(int n)
{
    return n - 1 >= 0 ? n - 1 : 9999;
}
int func_L(int n)
{
    int d[4] = {
        0,
    };
    int tmp = n;
    for (int i = 4; i >= 1; i--)
    {
        d[i] = tmp % 10;
        tmp /= 10;
    }
    return ((((d[2] * 10) + d[3]) * 10 + d[4]) * 10 + d[1]);
}

int func_R(int n)
{
    int d[4] = {
        0,
    };
    int tmp = n;
    for (int i = 4; i >= 1; i--)
    {
        d[i] = tmp % 10;
        tmp /= 10;
    }
    return ((((d[4] * 10) + d[1]) * 10 + d[2]) * 10 + d[3]);
}