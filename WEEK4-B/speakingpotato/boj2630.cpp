#include <iostream>

using namespace std;
int paper[128][128] = {};
int color[2] = {0, 0};

void checkpaper(int x, int y, int N){
    bool piece = true;
    int first = paper[x][y]; //first color

    for (int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if(first != paper[x + i][y + j]){
                piece = false;
                break;
            }
        }
    }

    //4등분
    if(piece != true){
        checkpaper(x, y, N / 2); // 좌하
        checkpaper(x + (N / 2), y, N / 2); // 우하
        checkpaper(x, y + (N / 2), N / 2); // 좌상
        checkpaper(x + (N / 2) , y + (N / 2), N / 2); //우상 
    }else{
        color[first] += 1; 
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cin >> paper[i][j];
        }
    }

    checkpaper(0, 0, N);

    cout << color[0] << "\n" << color[1];

    return 0;
}