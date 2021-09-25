// BOJ 5086번 : 배수와 약수
#include <iostream>
using namespace std;

int main() {
    while(true){ // 무한 반복문
        int a, b;
        cin >> a >> b;
        if(a == 0 && b == 0) break; // 둘 다 0을 입력받으면 종료
        if(a % b == 0 && a / b > 0) cout << "multiple" << "\n"; // 나머지가 0이고 a / b가 0보다 클 때는 배수
        else if(b % a == 0 && b / a > 0) cout << "factor" << "\n"; // 나머지가 0이고 b / a거 0보다 클 때는 약수
        else cout << "neither" << "\n"; // 둘 다 아닐 때
    }
}
