#include <iostream>
using namespace std;

int sorting(int* arr);

int main() {
    int v[4];
    int i=0, num;
    while(i<4){ // 4개의 수 입력받기
        cin>>num;
        v[i]=num;
        i++;
    }
    cout<<sorting(v);
}

int sorting(int* arr){ // 포인터로 함수 인자 전달
    int temp; // 수를 바꿀 때 사용
    for(int i=0;i<3;i++){ // 앞에 있는 수가 뒤에 있는 수 보다 작다면 계속해서 뒤로 밀림
        for(int j=i+1;j<4;j++){ // i보다 큰 숫자들에 대해 비교 반복
            if(arr[i]>arr[j]){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    return arr[0]*arr[2]; // 정렬된 4개의 수 중 인덱스 0번쨰와 2번째의 수를 곱한 것이 거북이가 움직인 거리로 만들 수 있는 직사각형의 크기
}