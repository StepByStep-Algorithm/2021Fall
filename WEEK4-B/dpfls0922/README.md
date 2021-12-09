> # WEEK4-분할정복
#### 1. 재귀
#### 2. 이분 탐색
#### 3. 큰 수 연산
</br>

# 1️⃣ 재퀴
## 정의
* 재귀(recursion)는 어떤 것을 정의할 때 자기 자신을 참조하는 것을 뜻함
* 재귀 함수 : 재귀 호출(recursive call)을 사용하는 함수
* 재귀 호출 : 어떤 함수가 내부에서 자기 자신을 다시 호출하는 것
* 재귀 호출을 사용할 경우 언제 호출을 그만둘 것인지를 정의해야 함. 그렇지 않으면 무한루프처럼 계속 자기 자신을 호출하게 됨
 
## 장단점
* 장점
* * 일반적인 수학의 점화식을 그대로 표현가능한 능력을 가지고 있어 복잡한 문제를 간단하고 논리적으로 표현할 수 있음 
* * 변수의 사용을 줄일 수 있음
* * 프랙탈, 분할 반복 등에서 엄청난 효율을 보여줌

* 단점
* * 함수의 call이 반복되므로 stack의 메모리를 많이 사용하여 stack overflow의 위험이 큼

 

# 2️⃣ 이분 탐색
## 정의
* 오름차순으로 정렬된 리스트에서 특정한 값의 위치를 찾는 알고리즘
* 오름차순으로 정렬된 리스트의 중간 값을 임의의 값으로 선택하여, 찾고자 하는 Key 값과 비교하는 동작을 반복함
* 순차적으로 탐색하는 일반 탐색 기법과 달리, 이분 탐색은 탐색 대상을 절반씩 없애며 탐색함
* 데이터의 양이 많아질 수록 이분 탐색이 효율적인 알고리즘이 됨

## 장단점
* 장점
* * 검색이 될때마다 선형탐색(Linear Search)와는 비교할 수 없게 빨라짐
* 단점
* * 정렬된 리스트에서만 사용할 수 있음

## 시간 복잡도
* log2n
* O(log n)

## 이진 탐색의 구현
1) 반복문
``` C++
bool BinarySearch(int *arr, int len, int key){
    int start = 0;
    int end = len-1;
    int mid;
 
    while(end - start >= 0) {
        mid = (start + end) / 2; 
 
        if (arr[mid] == key)
            return true;
 
        else if (arr[mid] > key)
            end = mid - 1;
 
        else
            start = mid + 1;
    }
    return false;
}
```
2) 재귀
``` C++
bool BinarySearch(int *arr, int start, int end, int key) {
 
    if (start > end) return false;
 
    int mid = (start + end) / 2;
 
    if (arr[mid] == key)
        return true;
        
    else if (arr[mid] > key)
        return BinarySearch(arr, start, mid - 1, key);
        
    else 
        return BinarySearch(arr, mid + 1, end, key);
    }
}
```
3) STL
* <algorithm> 해더 파일안에 있는 binary_search 함수를 이용하면 됨
``` C++
template <class ForwardIterator, class T>
  bool binary_search (ForwardIterator first, ForwardIterator last, const T& val)
```

# 3️⃣ 큰 수 연산
  자료형으로 담을 수 있는 범위를 벗어나는 경우
1) 배열, 벡터 이용
2) 문자열 string 이용
  ``` C++
// 문자열 덧셈
string add(string& a, string& b) {
	string c(max(a.size(), b.size()), '0');
	int  sum = 0;
	for (int i = 0; i < c.size(); i++) {
		if (i < a.size()) sum += a[a.size() - i - 1] - '0';
		if (i < b.size()) sum += b[b.size() - i - 1] - '0';
		c[c.size() - i - 1] = sum % 10 + '0';
		
		sum /= 10;
	}
	if (sum) c.insert(c.begin(), '1');
	return c;
}
```
``` C++
// 문자열 곱셈
string multiply(string& a, string& b) {
	string c = "0";
	for (int i = 0; i < b.size(); i++) {
		string line(a);
		int carry = 0;
		for (int j = a.size()-1; j >= 0; j--) {
			int sum = carry;
			carry = 0;
			sum += (a[j] - '0') * (b[b.size() - i - 1] - '0');
			if (sum >= 10) {
				carry = sum / 10;
				sum %= 10;
			}
			line[j] = sum + '0';
		}
		if (carry > 0) line.insert(line.begin(), carry + '0');
		line += string(i, '0');
		c = add(c, line);
	}
	return c;
}
```         
