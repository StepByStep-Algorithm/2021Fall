#include <bits/stdc++.h>

using namespace std;

bool check[10000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string result;
    int A, B, temp, now, n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {

        cin >> A >> B;
        memset(check, false, sizeof(check));
        queue<pair<int, string>> q;
        q.push({A, ""});
        check[A] = true;
        while (!q.empty())
        {
            now = q.front().first;
            result = q.front().second;
            q.pop();
            if (now == B)
            {
                cout << result << "\n";
                break;
            }
            //D
            temp = now * 2 % 10000;
            if (!check[temp])
            {
                check[temp] = true;
                q.push({temp, result + "D"});
            }
            //S
            //처음에 now - 1 == 0으로 해서 틀렸었는데 n == 0일 때 9999를 출력해야 하는 것이었음,,,
            temp = now - 1 < 0 ? 9999 : now - 1;
            if (!check[temp])
            {
                check[temp] = true;
                q.push({temp, result + "S"});
            }
            //L
            temp = (now % 1000) * 10 + now / 1000;
            if (!check[temp])
            {
                check[temp] = true;
                q.push({temp, result + "L"});
            }
            //R
            temp = (now % 10) * 1000 + now / 10;
            if (!check[temp])
            {
                check[temp] = true;
                q.push({temp, result + "R"});
            }
        }
    }

    return 0;
}