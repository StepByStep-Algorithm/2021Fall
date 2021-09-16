#include <iostream>
using namespace std;

void sorting(int* arr);

int main() {
    int v[3];
    int i=0, num;
    while(i<3){ // 3개의 수 입력받기
        cin>>num;
        v[i]=num;
        i++;
    }
    sorting(v);
}

void sorting(int* arr){ // 포인터로 함수 인자 전달
    int temp; // 수를 바꿀 때 사용
    for(int i=0;i<2;i++){ // 앞에 있는 수가 뒤에 있는 수 보다 작다면 계속해서 뒤로 밀림
        for(int j=i+1;j<3;j++){ // i보다 큰 숫자들에 대해 비교 반복
            if(arr[i]>arr[j]){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    for(int i=0;i<3;i++) {
        cout<<arr[i];
        if(i!=2) cout<<" ";
    }
    cout<<"\n";
}
