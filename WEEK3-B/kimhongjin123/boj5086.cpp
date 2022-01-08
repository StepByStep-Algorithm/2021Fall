#include <iostream>
#include <list>
using namespace std;

int main()
{
	while(true)
	{	int a;
		int b;
		cin >> a >> b;
		if (a != b) 
		{
			if (b % a == 0)
			{
				cout << "factor" << '\n';
			}
			else if (a % b == 0)
			{
				cout << "multiple" << '\n';
			}
			else
			{
				cout << "neither" << '\n';
			}
			}
		else
		{
			break;
		}

		}
	
	}
   

