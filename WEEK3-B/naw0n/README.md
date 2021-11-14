## string find, replace 함수
### 1. find 함수 <br>
문자열에서 원하는 문자열의 위치를 찾는 함수 <br>

1. `pos(검색을 시작할 위치)`에서 부터 탐색 시작
2. 문자열에서 `str(찾고자 하는 문자열)` 위치 리턴
3. `s(찾고자 하는 문자열을 가리키는 포인터)`가 가리키는 문자부터 `count(찾고자 하는 문자열의 길이)`개만큼 취한 부분 문자열을 초기 문자열에서 찾는다.
4. `s`가 가리키는 문자열은 초기 문자열에서 검색한다. 이때 `s`는 null 종료 문자열로 간주
5. 초기 문자열에서 문자 `ch(찾고자 하는 문자)` 위치 탐색
6. `t(찾고자 하는 string_view로 변환 가능한 객체`를 string_view 객체인 `sv`로 변환하고 초기 문자열에서 찾는다.
 
```c++
size_type find(const basic_string& str, size_type pos = 0) const;    
size_type find(const CharT* s, size_type pos, size_type count) const; 
size_type find(const CharT* s, size_type pos = 0) const;               
size_type find(CharT ch, size_type pos = 0) const;                     
template <class T>
size_type find(const T& t, size_type pos = 0) const; 
```
### 2. replace 함수
문자열에서 일부를 다른 문자열로 치환하는 함수 <br>
```c++
#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string word = "sweet new, sweet new";
	cout << word << '\n';
	word.replace(6, 3, "change");	// word[6]부터 3개의 문자를 "change"로 대체
	cout << word << '\n';
	return 0;
}
```
