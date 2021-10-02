// BOJ 1769번 : 3의 배수
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int count = 0;
    while(s.size() > 1){ // 문자열 자릿수가 1보다 클 때
        int sum = 0; // 합
        for(int i = 0; i < s.size(); i++){ // 문자열 자릿수만큼 반복
            sum += s[i] - '0'; // 문자 숫자로 변환해 sum에 저장
        }
        s = to_string(sum); // 숫자 문자로 변환해 s에 저장
        count++;
    }

    cout << count << "\n"; // 변환할 때 걸린 횟수 출력
    if(stoi(s) % 3 == 0) // s가 3의 배수일 때
        cout << "YES";
    else
        cout << "NO";
}
