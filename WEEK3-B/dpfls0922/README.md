> # WEEK3-자료구조
#### 1. 스택
#### 2. 큐
#### 3. 리스트
</br>

# 1️⃣ 스택
* LIFO(Last-in First-out) 후입선출 규칙을 따르는 자료구조
* 새로운 원소는 스택의 맨 위(top)에 추가되고 원소를 뺄 때는 맨 위(top)에 원소가 나오는 것
* 즉, 입구와 출구가 하나인 경우
* #include <stack>을 하여 c++ stl 라이브러리를 사용함
  
## 연산
* push(x)
  </br>
  x라는 항목을 스택 맨 위에 삽입 
* pop() 
  </br>
  스택 맨 위에 있는 항목을 삭제 
* empty() 
  </br>
  스택이 비어있는지를 확인 후 true,false 값을 반환 
* size()
  </br> 
  스택에 들어있는 원소의 개수를 반환 
* top() 
  </br>
  스택 맨 위에 있는 항목을 리턴

# 2️⃣ 큐
*  FIFO(First-in First-out) 선입선출 규칙을 따르는 자료구조
* 원소를 꺼낼 때는 맨 위에서 꺼내고 원소를 넣을 때는 맨 밑부터 넣는 것
* 즉. 입구와 출구가 각각 있는 것
* #include <queue>을 하여 c++ stl라이브러리를 사용함
  
## 연산
* push(x) 
   </br>
   x라는 항목을 큐의 맨 끝에 삽입
* pop()
  </br>
  큐의 맨 앞에 있는 항목을 삭제 
* front()
  </br>
  큐의 맨 앞에 있는 항목을 리턴 
* back()
  </br>
  큐의 맨 뒤에 있는 항목을 리턴 
* empty(),size()
  </br>
  큐가 비어있는지 검사, 큐에 들어있는 원소의 개수 반환

# 3️⃣ 리스트
* 시퀀스 컨테이너 (sequence container)의 일종으로 순서를 유지하는 자료구조
* #include <list> 하여 c++ stl라이브러리를 사용함

## 관련 함수
#### 반복자
* begin()
  </br>
  beginning iterator 반환
* end()
  </br>
  end iterator 반환
#### 삽입
* push_front(element)
  </br>
  리스트 맨 앞에 원소 추가
* push_back(element)
  </br>
  리스트 맨 뒤에 원소 추가
* insert(iterator, element)
  </br>
  iterator가 가리키는 부분의 앞에 원소 추가
#### 삭제
* pop_front()
  </br>
  리스트 맨 앞의 원소 삭제
* pop_back()
  </br>
  리스트 맨 뒤의 원소 삭제
* erase(iterator)
  </br>
  iterator가 가리키는 부분의 원소 삭제
#### 조회
* ( * )iterator
  </br>
  iterator가 가리키는 원소에 접근
* front()
  </br>
  첫번째 원소 반환
* back()
  </br>
  마지막 원소 반환

#### 기타
* empty()
  </br>
  리스트가 비어있는지 여부
* size()
  </br>
  리스트 사이즈 반환
