#include <bits/stdc++.h>
using namespace std;

int N;

int solve(int num)
{
    int res = 0;
    if (num >= 10)
        res += solve(num / 10);
    return res + (num % 10);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    if (N >= 54)
    {
        for (int i = N - 54; i < N; i++)
        {
            if (solve(i) + i == N)
            {
                cout << i;
                return 0;
            }
        }
    }
    else
    {
        for (int i = 1; i < N; i++)
        {
            if (solve(i) + i == N)
            {
                cout << i;
                return 0;
            }
        }
    }
    cout << "0";
    return 0;
}