// BOJ 15953번 : 상금 헌터
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int p1[6] = {500, 300, 200, 50, 30, 10};
        int p2[5] = {512, 256, 128, 64, 32};
        int a, b;
        int price = 0;
        cin >> a >> b;
        if(a == 1) price += p1[0];
        else if(a >= 2 && a <= 3) price += p1[1];
        else if(a >= 4 && a <= 6) price += p1[2];
        else if(a >= 7 && a <= 10) price += p1[3];
        else if(a >= 11 && a <= 15) price += p1[4];
        else if(a >= 16 && a <= 21) price += p1[5];

        if(b == 1) price += p2[0];
        else if(b >= 2 && b <= 3) price += p2[1];
        else if(b >= 4 && b <= 7) price += p2[2];
        else if(b >= 8 && b <= 15) price += p2[3];
        else if(b >= 16 && b <= 31) price += p2[4];

        cout << price * 10000 << "\n";
    }
}
