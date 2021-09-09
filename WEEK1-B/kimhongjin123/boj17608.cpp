
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int j;
    int count = 1;
    vector <int> v;
    cin >> j;

    for (int i = 0; i < j; i++)
    {
        int num = 0;
        cin >> num;
        v.push_back(num);
    }
    
    for (int i = j; i>= 2; i--)
    {
        if (v[i - 1] < v[i - 2])
        {
            count++;
        }
        else
        {
            v[i - 2] = v[i - 1];
            
        }
        
    }
    cout << count;
}

