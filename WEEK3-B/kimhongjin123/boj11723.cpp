#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	queue<int>t;
	vector<string>v;
	v.push_back("add");
	v.push_back("remove");
	v.push_back("check");
	v.push_back("toggle");
	v.push_back("all");
	v.push_back("empty");
	int n;
	cin >> n;
	while (n--)
	{
		queue<int>q;
		int a;
		string b;
		cin >> b ;
		if (b != v[4] && b != v[5])
		{
			cin >> a;
		}
		else
		{
			a = 0;
		}
		for (int i = 0; i < v.size(); i++)
		{

			if (b == v[i])
			{
				if (i == 0)
				{
					bool count = 0;
					while (1)
					{


						if (t.empty())
						{
							if (count == 0)
							{
								q.push(a);
							}

							swap(t, q);
							break;
						}

						if (t.front() == a)
						{
							q.push(t.front());
							t.pop();
							count = !count;
						}
						else
						{
							q.push(t.front());
							t.pop();
						}
					}
				}
				else if (i == 1)
				{
					while (1)
					{
						if (t.empty())
						{
							swap(t, q);
							break;
						}
						if (t.front() == a)
						{
							t.pop();
						}
						else
						{
							q.push(t.front());
							t.pop();
						}
					}
				}
				else if (i == 2)
				{
					bool count = 0;
					while (1)
					{
						if (t.empty())
						{
							cout << count << '\n';
							swap(t, q);
							break;
						}
						if (t.front() == a)
						{
							q.push(t.front());
							t.pop();
							count = !count;
						}
						else
						{
							q.push(t.front());
							t.pop();
						}
					}
				}
				else if (i == 3)
				{
					bool count = 0;
					while (1)
					{

						if (t.empty())
						{
							if (count == 0)
							{
								q.push(a);
							}
							swap(t, q);
							break;
						}
						if (t.front() == a)
						{
							t.pop();
							count = !count;
						}
						else
						{
							q.push(t.front());
							t.pop();
						}
					}
				}
				else if (i == 4)
				{
					queue<int>all({ 1, 2, 3, 4, 5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 });
					swap(t, all);

				}
				else if (i == 5)
				{
					swap(t, q);
				}
			}
		}
	}

}
