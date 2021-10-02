#include <iostream>
#include <stack>

using  namespace std;

int main() {
    stack <int> s;
    long a;
    cin>>a;
    do{
        s.push(a%2);
        a/=2;
    }while(a!=0);

    do{
        cout<<s.top();
        s.pop();
    }while(!s.empty());
}
