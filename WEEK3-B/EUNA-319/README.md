## 백준 5086 알고리즘 정리 ##
<br><br>

### 사용한 알고리즘 : 산술 ###

- 배수와 약수의 관계: a와 b
  --> a가 b의 약수일 때 b는 a의 배수
  --> a가 b의 배수일 때 b는 a의 약수
<br><br><br>

### 구현 ###
- 배수와 약수의 관계를 파악하여 품
 ```c++
string trans(unsigned int a, unsigned int b){
    if(b%a==0) return "factor";
    else if(a%b==0) return "multiple";
    else return "neither";
}

 ```

