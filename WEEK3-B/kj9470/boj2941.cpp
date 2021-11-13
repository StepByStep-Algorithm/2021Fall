// BOJ 2941번 : 크로아티아 알파벳
#include <iostream>
#include <string>
using namespace std;

int main() {
    string alp[8] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
    string s;
    string tmp;
    getline(cin, s);
    int n = s.length();

    for(int i = 0; i < s.length(); i++){
        tmp = s.substr(i, 2); // substr 함수로 2글자 추출
        if(tmp == "dz"){ // 만약 dz라면
            tmp = s.substr(i, 3); // 3글자를 추출해서
            if(tmp == "dz="){ // dz=와 같은지 비교하고 맞다면
                n -= 2; // 3글자이므로 2 감소
                i += 2; // i는 2 증가
                tmp = s.substr(i, 2); // tmp에는 다시 2글자 넣어줌
            }
            else{
                tmp = s.substr(i, 2); // dz=가 아닐 경우 다시 2글자 넣어줌
            }
        }
        for(int j = 0; j < 8; j++){
            if(tmp == alp[j]){ // 배열 안에 있는 글자와 비교
                n--;
                i++;
                break;
            }
        }
    }
    cout << n; // n 출력력

