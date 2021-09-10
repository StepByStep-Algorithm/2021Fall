#include <iostream>
#include<vector>

using namespace std;
int main()
{
	int j = 0;
	int k = 0;	
	vector<int>v;	
	cin >> j;
	cin >> k;
	for (int i = 1; i <= j; i++)
	{
		v.push_back(i);
	}
	int i = 0;
	int count = k;
	int m = j;
	cout << "<";
	while (true)
	{	
		if (v[i] != 0)
		{
			count--;
		}
		if (count == 0)
		{
			if (m != 1)
			{
				cout << v[i] << ", ";
				m--;
			}

			else
			{
				cout << v[i];
				break;
			}
			v[i] = 0;			
			count = k;				
		}
		i++;	
		if (i > v.size()-1)
		{	i = 0;
			
		}			
	}
	cout << ">";
	


	

  
}

