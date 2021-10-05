// BOJ 16926번 : 배열 돌리기 1
#include <iostream>
using namespace std;

int main() {
    int arr[301][301]; // 배열 생성
    int dx[4] = {0, 1, 0, -1}; // 우상좌하
    int dy[4] = {1, 0, -1, 0};
    int n, m, r;
    cin >> n >> m >> r;

    for(int i = 0; i < n; i++){ // 배열 입력받기
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < r; i++){ // 회전 횟수만큼 반복
        for(int j = 0; j < min(n, m) / 2; j++){ //
            int x = j;
            int y = j;
            int value = arr[x][y];
            int tmp = 0;

            while(tmp < 4){
                int nx = x + dx[tmp];
                int ny = y + dy[tmp];

                if(nx == j && ny == j) break;
                if(nx >= j && ny >= j && nx < n - j && ny < m - j){
                    arr[x][y] = arr[nx][ny];
                    x = nx;
                    y = ny;
                }
                else
                    tmp++;
            }
            arr[j + 1][j] = value;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}
