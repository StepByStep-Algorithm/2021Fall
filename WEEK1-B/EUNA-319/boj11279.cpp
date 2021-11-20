#include<iostream>
#include<queue>
using namespace std;

int n; // 입력받을 정수의 개수
priority_queue<int> pq;
int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i=0;i<n;i++) { // 연산의 개수만큼 반복
        int x; // 연산에 대한 정보를 받아줄 변수
        cin >> x;
        if (x == 0) { //x가 0이라면 (0이 입력된 시점에서의 가장 큰 값을 출력하기 때문)
            if (pq.empty()) cout << "0\n";
                // queue가 비어있을 경우 0 출력
            else {
                cout << pq.top() << "\n";
                pq.pop();
                // 가장 위에 들어가있는 값을 출력
                // pop()을 해주면 queue의 선입선출 특징으로 맨위의 값이 나오게 됨
            }
        } else { // x가 0이 아니라면
            pq.push(x); // 입력한 숫자를 priority_queue에 삽입
        }
    }
    return 0;
}