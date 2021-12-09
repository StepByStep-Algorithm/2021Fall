#include <bits/stdc++.h>
using namespace std;

int main(){
    int tc, x, y, money1, money2, rank;
    int ct1_reward[6] = {500, 300, 200, 50, 30, 10};
    int ct2_reward[5] = {512, 256, 128, 64, 32};

    cin >> tc;
    for(int i=0; i<tc; i++){
        rank = 0, money1=0, money2=0;
        cin >> x >> y;
        for(int j=1; j<7; j++){
            rank += j;
            if( x <= rank){
                money1 = ct1_reward[j-1];
                break;
            }
        }
        rank = 0;
        for(int j=1; j<6; j++){
            rank += pow(2, j-1);
            if( y <= rank){
                money2 = ct2_reward[j-1];
                break;
            }
        }    
        cout << (money1+money2)*10000<<'\n';
    }
    return 0;
}