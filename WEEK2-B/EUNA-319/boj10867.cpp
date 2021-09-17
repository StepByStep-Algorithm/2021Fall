#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int tc;
    cin>>tc;
    int *a = new int[tc];
    for(int i=0;i<tc;i++){
        cin>>a[i];
    }
    sort(a,a+tc);
    cout<<a[0];
    for(int i=1;i<tc;i++){
        if(a[i]!=a[i-1]) cout<<" "<<a[i];
    }
}
