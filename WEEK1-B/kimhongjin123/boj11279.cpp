#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int main()
{
    vector<int>v;
    vector<int>q;
    int j;
    int n;
     
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> j;
    for (int i = 0; i < j; i++)
    { 
        cin >> n;
        if (n == 0)
        {
            if (v.empty())
            {
                q.push_back(0);
            }
            else {
                int max = *max_element(v.begin(), v.end());
                
                auto a = find(v.begin(), v.end(), max);
                q.push_back(max);
                 v.erase(a);
   
           }
         
        }
        else
        {
           v.push_back(n);           
        }
           
    }
    for(int i=0; i<q.size();i++)
        {
            cout<<q[i]<<'\n';
       }

    return 0;
}
