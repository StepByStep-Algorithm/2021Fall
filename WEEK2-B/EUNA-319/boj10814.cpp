#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct List{
    int age;
    string name;
};

bool compare(const List &i, const List &j){
    return i.age<j.age;
}

int main() {
    int tc;
    cin>>tc;
    vector <List> person;
    List list;

    for(int i=0; i<tc;i++){
        cin>>list.age>>list.name;
        person.push_back(list);
    }
    stable_sort(person.begin(),person.end(),compare);

    for(int i=0;i<tc;i++){
        cout<<person[i].age<<" "<<person[i].name<<"\n";
    }

}


