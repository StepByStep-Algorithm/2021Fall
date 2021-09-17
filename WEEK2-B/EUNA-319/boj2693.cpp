#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a[10];
    int tc;
    cin>>tc;
    for(int i=0;i<tc;i++){
        scanf("%d %d %d %d %d %d %d %d %d %d",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5],&a[6],&a[7],&a[8],&a[9]);
        sort(a,a+10);
        cout<<a[7]<<"\n";
    }
}