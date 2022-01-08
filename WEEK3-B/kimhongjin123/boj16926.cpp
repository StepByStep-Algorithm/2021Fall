#include <iostream>
#include<stack>
#include<vector>
#include<algorithm>
#include<deque>
using namespace std;

int main()
{

	vector<vector<int>> v;
	vector<int> l;
	vector<int>oh;
	stack<int>s;
	stack<int>s1;
	
	int x, y, r;
	cin >> x >> y >> r;
	for (int i = 0; i < x; i++)
	{
		

		for (int i = 0; i < y; i++)
		{
			int num;
			cin >> num;
			l.push_back(num);
		}
		v.push_back(l);
		
	}
	
	for (int i = 0; i < r; i++)
	{
		
		oh.clear();
		stack<int>s;
		stack<int>s1;
		
		
		int j = 0;
		int o = 2;
		int nt = 1;
		for (int i = 0; i < x; i++)
		{

			if (x % 2 == 0)
			{
				if (i > x / 2 - 1&&i!=x-1)
				{
					j = oh[i - o];
					oh.push_back(j);
					o += 2;
				}
				else if (i <= x / 2 - 1&& j<y/2)
				{
					j++;
					oh.push_back(j);
				}
				else if (i == x - 1)
				{
					j = 0;
				}
			
		
			}
			else if (x % 2 != 0)
			{

				if (i >= (x + 1) / 2 - 1 && i != x - 1)
				{
					j = oh[i - nt];
					oh.push_back(j);
					nt+= 2;
					

				}
				else if (i < (x + 1) / 2 - 1&& j<y-1/2)
				{
					j++;
					oh.push_back(j);
				}
				else if (i == x - 1)
				{
					j = 0;
				}
		
			}
		



			
				for (int nom = 0; nom < j; nom++)
				{
					s1.push(v[i].front());
					v[i].erase(v[i].begin());
					s.push(v[i + 1].back());
					v[i + 1].pop_back();

				}
				for (int nom = 0; nom < j; nom++)
				{
					v[i].push_back(s.top());
					s.pop();
				}

		
			int tt = s.size();
			if (tt != 0)
			{
				for (int nom = 0; nom < tt; nom++)
				{
					v[i].insert(v[i].begin(), s.top());
					
					s.pop();
				}
			}
			
				s1.swap(s);
			
		}

		
	}

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			
				cout << v[i][j];
				
				if (j != y - 1)
				{
					cout << ' ';
				}
				
		

		}
		cout << '\n';
		
	}
	
	return 0;

}
