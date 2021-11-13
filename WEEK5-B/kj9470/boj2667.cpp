// BOJ 2667번 : 단지번호붙이기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dx[4] = {0, 1, 0, -1}; // 상 우 하 좌
int dy[4] = {-1, 0, 1, 0};
int n;
int map[26][26];
int house;
vector<int> v;

void DFS(int i, int j);

int main() {
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%1d", &map[i][j]); // 숫자 하나씩 입력받기 위해 scnaf 사용
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(map[i][j] == 1){ // 만약 집이 있다면
                house = 0; // 집 0으로 초기화
                DFS(i, j);
                v.push_back(house); // house push
            }
        }
    }
    sort(v.begin(), v.end()); // 벡터 정렬
    cout << v.size() << "\n"; // 단지의 개수 출력
    for(int i = 0; i < v.size(); i++) // 벡터 원소 출력 (단지의 집 개수)
        cout << v[i] << "\n";
}

void DFS(int i, int j){
    map[i][j] = 0; // map[i][j] 0으로 설정
    house++; // 집 수 증가
    for(int k = 0; k < 4; k++){ // 상하좌우
        if(i + dy[k] < 0 || i + dy[k] >= n || j + dx[k] < 0 || j + dx[k] >= n)
            continue; // 만약 집이 없다면 continue
        if(map[i + dy[k]][j + dx[k]] == 1) // 상하좌우 중 집이 있다면
            DFS(i + dy[k], j + dx[k]); // 재귀 호출 (그 집을 매개변수로)
    }
}
