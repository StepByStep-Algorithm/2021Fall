#include <iostream>
#include <queue>
using namespace std;
int main()
{
    priority_queue<int>v;
    
    int j;
    int n;
    int count = 0;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> j;
    for (int i = 0; i < j; i++)
    { 
        cin >> n;
        if (n == 0)
        {
            if (v.empty()==true)
            {
                cout <<0<<'\n';
            }
            else {
                cout << v.top() << '\n';
                v.pop();
                 
           }
                
        }
        else
        {
            v.push(n);
        }          
    }
   

    return 0;
}
