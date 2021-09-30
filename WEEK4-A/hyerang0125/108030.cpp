#include <bits/stdc++.h>

using namespace std;

long long matrix[5][5];
long long temp[5][5];
long long result[5][5];
long long N, B;

// 행렬 곱셈 구현
void matrix_m(long long m1[5][5], long long m2[5][5]){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            temp[i][j] = 0;
            for(int k=0; k<N; k++){
                temp[i][j] += m1[i][k] * m2[k][j];
            }
            temp[i][j] %= 1000;
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            m1[i][j] = temp[i][j];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> B;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> matrix[i][j];
        }
        result[i][i] = 1;
    }
    
    //빠른 거듭제곱 알고리즘
    while(B){
        // B가 홀수이면 matrix^B를 matrix * matrix^(B-1)로 바꾸고 matrix를 결과값에 곱한다.
        // B가 짝수이면 matrix^B를 (matrix^2)^(B/2) -> matrix를 제곱하고 B를 2로 나눈다.
        // B가 0이면 종료
        if(B % 2 == 1) 
            matrix_m(result, matrix);
        matrix_m(matrix, matrix);
        B /= 2;
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << result[i][j] <<" ";
        }
        cout <<"\n";
    }

    return 0;
}