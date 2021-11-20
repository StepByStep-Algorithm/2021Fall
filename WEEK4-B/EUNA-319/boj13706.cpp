#include <iostream>
#include<math.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int low = 1;
    int high = n;
    int mid;

    while (1) {
        mid = (low + high); // 2
        if(pow(mid,2) == n) {
            cout<<mid;
            break;
        }
        else if(pow(mid,2) > n)
            high = mid - 1;
        else if(pow(mid,2)<n)
            low = mid + 1;
    }
}
