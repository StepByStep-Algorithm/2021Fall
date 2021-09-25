## 백준 5086 알고리즘 정리 ##
<br>

### 사용한 알고리즘 : 수학, 구현 ###

### 이번 문제에서 사용한 수학 개념: 배수와 약수 ###
- a와 b가 있을 때
  >> a가 b의 약수이면 b는 a의 배수임
  >> a가 b의 배수이면 b는 a의 약수임

 ```c++
  string trans(unsigned int a, unsigned int b){
    if(b%a==0) return "factor";
    else if(a%b==0) return "multiple";
    else return "neither";
  }

 ```

### 문제 풀 때 생각한 flow ###
- 단순하게 배수와 약수의 관계를 구분하는 trans 함수를 만들어 문제를 해결해봄
  <br><br>

