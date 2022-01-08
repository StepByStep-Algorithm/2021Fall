#include <iostream>
#include<string>
#include <list>
using namespace std;
int main()
{
	
	string a;
	cin >> a;
	int size = a.size();
	list<string>s;
	s.push_back("c=");
	s.push_back("c-");
	s.push_back("dz=");
	s.push_back("d-");
	s.push_back("lj");
	s.push_back("nj");
	s.push_back("s=");
	s.push_back("z=");
	
	list<string>::iterator iter = s.begin();
	
	for (iter = s.begin(); iter != s.end(); iter++)
	{
		string k = *iter;	
		while (1)
		{
			if (a.find(*iter) != string::npos) {
				int index = a.find(*iter);
				a.erase(index,k.size());
				a.insert(index,k.size(),' ');			
				size -= k.size() - 1;
			}
			else
			{		
				break;
			}
		}	
	}
	cout << size << endl;
   
}

