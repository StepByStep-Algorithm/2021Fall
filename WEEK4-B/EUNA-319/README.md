## 분할 정복 공부 ##
<br><br>

### 재귀 ###
- 자기 자신을 호출하는 함수
- 자신의 복사본을 호출하여 더 작은 문제를 풀게함으로써 문제를 해결
- 기본 경우: 함수가 재귀 호출을 하지 않는 것
- 재귀 경우: 자기 자신을 호출해서 하위 작업을 수행하는 것
<br><br>

### 이분 탐색 ###
- 탐색 기법 중 하나로 원하는 탐색 범위를 두 부분으로 분할해서 찾는 방식
- 원래의 전부를 탐색하는 속도에 비해 빠름
- left, right, mid 값으로 탐색하는 것
- mid의 값은 (left+right)/2으로 잡아주고 검색하고자 하는 값과 mid를 비교
- 조건: 정렬이 되어있어야 함
  ```c++
  #include <stdio.h>
  int main(void){
 
    int findN;
    int result = 0;
    //처음int는 다음 정점 마지막 int 값어치
 
    int A[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 15 };
 
    scanf("%d", &findN);
    int left = 0, right =  9;
 
 
    while (left <= right){
 
        int mid = (left + right) / 2;
        if (A[mid] > findN)
            right = mid - 1;
        else if (A[mid] < findN)
            left = mid + 1;
        else
        {
            result = mid;
            break;
        }
 
    }
 
    printf("%d\n", result);
 
    return 0;
  }
  ```


