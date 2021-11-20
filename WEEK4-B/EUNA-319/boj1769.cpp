#include <iostream>
#include <string.h>
#include <string>
using namespace std;
void cal(char num[]);

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    char num[1000001];
    cin >> num;
    cal(num);
}

void cal(char num[])
{
    int count = 0;
    int sum;
    while(strlen(num)>1)
    {
        sum = 0;
        for (int i = 0; i < strlen(num); i++)
        {
            sum += num[i] - '0';
        }
        sprintf(num,"%d",sum);
        count++;
    }
    cout << count<< endl;

    if (stoi(num) != 3&&stoi(num)!=6&&stoi(num)!=9)
        cout << "NO";
    else
        cout << "YES";
}
