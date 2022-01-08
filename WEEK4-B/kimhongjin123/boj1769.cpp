#include <iostream>
#include <string>
using namespace std;

string sum(string n)
{
    int sum = 0;
    for (int i = 0; i < n.length(); i++)
        sum += n[i] - '0';

    return to_string(sum);
}
int count(string t)
{
    int count = 0;

    while (t.size()>1)
    {
        t = sum(t);
        count++;
    }

    return count;
}
int main()
{
    
    string num;
    cin >> num;
    cout<<count(num)<<endl;
    int count = 0;

    while (num.size() > 1)
    {
        num = sum(num);
        count++;
    }
    if (stoi(num) % 3 == 0)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

}
