#include <iostream>
#include <algorithm>
using namespace std;

class List{
public:
    int age;
    string name;
};

void sorting(List *list);

int main() {
    int tc;
    cin>>tc;
    List *list=new List[tc];

    for(int i=0; i<tc;i++){
        cin>>list[i].age>>list[i].name;
    }
    sorting(list,list+tc);
    for(int i=0;i<tc;i++){
        cout<<list[i].age<<" "<<list[i].name<<"\n";
    }
    delete [] list;

}

void sorting(List *list){
    int temp1; // 수를 바꿀 때 사용
    string temp2;
    for(int i=0;i<2;i++){ // 앞에 있는 수가 뒤에 있는 수 보다 작다면 계속해서 뒤로 밀림
        for(int j=i+1;j<3;j++){ // i보다 큰 숫자들에 대해 비교 반복
            if(list[i].age>list[j].age){
                temp1=list[i].age;
                temp2=list[i].name;
                list[i].age=list[j].age;
                list[i].name=list[j].name;
                list[j].age=temp1;
                list[j].name=temp2;
            }
        }
    }
}