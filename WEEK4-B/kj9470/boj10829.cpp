// BOJ 10829번 : 이진수 변환
#include <iostream>
#include <stack>
using namespace std;

int main() {
    long long n;
    cin >> n;

    stack <int> s; // 스택 선언
    while(true){ // 무한 반복
        if(n == 0) // n이 0이 되었을 때 종료
            break;
        s.push(n % 2); // 2로 나눈 나머지를 스택에 저장
        n /= 2;
    }

    while(true){ // 스택 출력
        if(s.empty()) // 스택이 비었다면 종료
            break;
        else{
            cout << s.top(); // top 출력
            s.pop(); // pop
        }
    }
}
