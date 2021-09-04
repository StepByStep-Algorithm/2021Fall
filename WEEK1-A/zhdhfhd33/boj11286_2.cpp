#include <iostream>
#include <cstdlib>
#define MAX 100000

using namespace std;

class Unit
{
public:
    int real;
    int absNum;
    Unit():real(0), absNum(0) {}

};
class Heap
{
public:

    Unit arr[MAX];//default constructor
    int count;
    Heap(): count(0) {}

    void mySwap(Unit * a, Unit * b)  //기본으로 제공되는 std::swap() 알아보자
    {
        Unit temp =*a;
//        printf("temp : %d, %d", temp.real, temp.absNum);
        a->real = b->real;
        a->absNum = b->absNum;
        b->real = temp.real;
        b->absNum = temp.absNum;
    }
    void push(int a)
    {
        arr[count].real=a;
        arr[count].absNum = abs(a); //count 인덱스를 절대로 넘어가지 않는다.

        int parent = (count-1)/2;
        int tempLast = count;
        while (1)
        {
            if (arr[parent].absNum > arr[tempLast].absNum) //parent >=0 이 조건은 필요가 없는 것이 어짜피 parent는 음수로 내려가지 않는다.
            {
                mySwap(&arr[parent], &arr[tempLast]);
            }
            else if (arr[parent].absNum == arr[tempLast].absNum && arr[parent].real > arr[tempLast].real)
            {
                mySwap(&arr[parent], &arr[tempLast]);
            }
            else
            {
                break;
            }


            tempLast=parent;
            parent=(parent-1)/2;
        }
        ++count;
    }
    int pop()  //뺄 때 절댓값이 같은 경우를 컨트롤 하지말고 넣을 때 real까지 고려해서 넣으면 편하지.
    {
        if (count == 0)  //push()에서는 삽입할 때 count를 인덱스처럼 사용했다고 해서 pop()에서도 인덱스처럼 사용해야 하는 것은 아니다. push()에서는 인덱스로 사용한 뒤에 ++을 해주기 때문에 가능함.
        {
            return 0;
        }

        int res = arr[0].real;
        mySwap(&arr[0], &arr[count-1]); //여기서만 count-1을 사용함.
        --count;//--count를 여기서 해줘야 한다.

        //재정렬해줘야한다. down heap과정
        int now=0;
        int left=1;
        int right=2;
        int target=now;
        while (1)
        {
            if (left <= count-1 && cmp(arr[target], arr[left])==1) target=left;
            if (right <= count-1 && cmp(arr[target], arr[right])==1) target=right;
            if (now == target){
                break;
            }
            else{
                mySwap(&arr[now], &arr[target]);
                now=target;
                left=now*2+1;
                right = now*2+2;

            }
        }
        return res;

    }
    void printHeap()
    {
        for (int i=0; i<count; ++i)
        {
            printf("arr[%d] : %d, %d\n", i, arr[i].real, arr[i].absNum);
        }
    }
    //a>b : 1, opposite : -1,  same : 0
    int cmp(const Unit& a, const Unit& b){ //이렇게 대소를 비교하는 함수는 미리 짜두지 않으면 매우 힘들다. 꼭 함수로 만들어 놓자.
        if (a.absNum > b.absNum){
            return 1;
        }
        else if (a.absNum < b.absNum){
            return -1;
        }
        else if (a.real > b.real){ //a.absNum == b.absNum 인 상황
            return 1;
        }
        else if (a.real == b.real){
            return 0;
        }
        else{
            return -1;
        }
    }

};
Heap heap;

int main()
{
    int N;
    scanf("%d", &N);
    while (N--)
    {
        int a;
        scanf("%d", &a);
        if (a!=0)
        {

            heap.push(a);
//            heap.printHeap();
//            printf("\n");
        }
        else
        {
            printf("%d\n", heap.pop());
//            heap.printHeap();
//            printf("\n");
        }
    }
}
