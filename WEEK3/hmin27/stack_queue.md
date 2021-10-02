Stack and Queue
=====
# Stack
* Data insertion(Push)과 deletion(Pop)은 top에서만 일어남
* Last In First Out

## Implementation
    1. Array-Based
        - 왼쪽에서 오른쪽으로 요소를 추가
        - top 요소의 index를 계속해서 저장하고 있어야 함
        - Limitation
            - stack의 최대 크기(배열의 크기)가 이전에 선언되어야하며 변경할 수 없음
            - 가득 찬 stack에 새로운 요소를 push하려고 하면 예외가 발생함
    2. Linked List
        - Singly linked list 이용
        - top 요소는 리스트의 첫 번째 노드에 저장됨

# Queues
* Data Insertion(enqueue or push)는 rear에서 일어나며, Data deletion(dequeue or pop)은 front에서 일어남
* First In First Out

## Implementation
    1. Array-Based
        - rear의 index를 계속해서 저장하고 있어야 함
        - Pop: queue[0] 삭제 후 모든 요소들을 왼쪽으로 한 칸씩 이동
        - Push: rear index에 저장
    1-2. Improved Queue
        - front와 rear의 index 모두 저장하고 있음
        - Pop: front의 index 증가
        - Push: rear의 index 증가
        - rear이 리스트의 끝에 도달하면 모든 요소들을 왼쪽으로 이동
    2. Circular Queue
        - front와 rear의 index 모두 저장하고 있음
        - front는 첫 요소에서 반시계 방향으로 한 칸 이동한 칸을 가리킴
        - rear는 마지막 요소를 가리킴
        