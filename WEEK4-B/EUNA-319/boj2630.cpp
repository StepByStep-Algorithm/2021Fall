// BOJ 2630번 : 색종이 만들기
#include <iostream>
using namespace std;
void dfs(int x, int y, int size);
int arr[128][128];
int white = 0, blue = 0;

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> arr[i][j]; // 배열 입력받기

    dfs(0, 0, n);
    cout << white << "\n" << blue << "\n";
}

void dfs(int x, int y, int n){
    bool w = true, b = true; // w와 b 초깃값 true
    for(int i = x; i < x + n; i++){ // x + n까지 반복
        for(int j = y; j < y + n; j++){ // y + n까지 반복
            if(arr[i][j] == 1) // 만약 하얀색이라면
                w = false; // w를 false로
            if(arr[i][j] == 0) // 파란색이라면
                b = false; // b를 false로
        }
    }
    if(w == true){ // w가 true라면 (하얀색으로 채워진 것)
        white++; // white 증가
        return;
    }
    if(b == true){ // b가 true라면 (파란색으로 채워진 것)
        blue++; // blue 증가
        return;
    }

    // 재귀호출
    dfs(x, y, n / 2);
    dfs(x, y + n / 2, n / 2);
    dfs(x + n / 2, y, n / 2);
    dfs(x + n / 2, y + n / 2, n / 2);
}