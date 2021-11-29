#include <iostream>
using namespace std;

char arr[3100][6200];

void draw(int row, int col)
{
    arr[row][col] = '*';
    
    arr[row + 1][col - 1] = '*';
    arr[row + 1][col + 1] = '*';
    
    for(int i = 0; i < 5; i++)
        arr[row + 2][col - 2 + i] = '*';
}

void dp(int len, int row, int col)
{
    if (len == 3)
    {
        draw(row, col);
        return; 
    }
        
    dp(len / 2, row, col); 
    dp(len / 2, row + len / 2, col - len / 2); 
    dp(len / 2, row + len / 2, col + len / 2); 
}

int main()
{
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2 * n - 1; j++)
        {
            arr[i][j] = ' ';
        }
    }
    
    dp(n, 0, n - 1);
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2 * n - 1; j++)
        {
            cout << arr[i][j];
        }
        cout << '\n';
    }

    return 0;
}