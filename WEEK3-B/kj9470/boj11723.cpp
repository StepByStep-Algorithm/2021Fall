// BOJ 11723번 : 집합
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // 입출력 빠르게 해 줌
    cin.tie(NULL);
    cout.tie(NULL);

    int m;
    cin >> m;
    set<int> s;
    set<int> new_s = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

    for(int i = 0; i < m; i++){
        string com;
        int n;
        cin >> com;

        if(com == "add"){
            cin >> n;
            if(s.find(n) == s.end()) // 원소 중복이 없을 때
                s.insert(n);
        }
        else if(com == "remove"){
            cin >> n;
            if(s.find(n) != s.end()) // 원소가 있을 때
                s.erase(n);
        }
        else if(com == "check"){
            cin >> n;
            if(s.find(n) != s.end()) // 원소가 있을 때
                cout << 1 << "\n";
            else // 원소가 없을 때
                cout << 0 << "\n";
        }
        else if(com == "toggle"){
            cin >> n;
            if(s.find(n) != s.end()) // 원소가 있을 때
                s.erase(n); // 삭제
            else // 원소가 없을 때
                s.insert(n); // 삽입
        }
        else if(com == "all"){ // 원소 바꾸기
            s = new_s;
        }
        else if(com == "empty") // 공집합
            s.clear();
    }
}
