#include<sstream>
#include <vector>
#include <iostream>
#include <string>
using namespace std;
int main()
{
	int count = 1;
	int j;
	

		string s;
		
		cin >> j;
		cin.ignore( ); // 입력 버퍼 지우기
		for(int num=0;num <j;num++)
		{
			
			
			getline(cin, s); //스페이스바 엔터 취급 x
			
			istringstream s1(s);
			string s2;
			vector<string>v;
			
			while (getline(s1, s2, ' ')) //스페이스바를 분기점을 백터에 나눠줌
			{
				v.push_back(s2);
			}
			
			
				cout << "Case #" << count << ": "; //아니 띄어쓰기 하나는 오바잖아 ......
				
				for (int i = v.size() - 1; i >= 0; i--) {
					
					if (i == 0)
					{
						cout << v[i];
					}
					else {
						cout << v[i] << " "; //여기도 마찬가지.......
					}
				}
				cout << endl;
				
				
				
			
			v.clear();
			count++;
		}
	
		return 0;
}

