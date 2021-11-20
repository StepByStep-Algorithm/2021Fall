#include <iostream>
using namespace std;

unsigned int cal(unsigned int a, unsigned b);


int main() {
    unsigned int n, a=0, b=0;
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    cin.ignore();
    for(int i=0;i<n;i++){
        cin>>a>>b;
        cin.ignore();
        cout<<cal(a,b)<<endl;
    }

}

unsigned int cal(unsigned int a, unsigned b){
    if(a>21||a==0) a=0; //본선 진출 X와 순위권 X를 고려
    else{
        if(a==1) a=5000000;
        else if(3>=a) a=3000000;
        else if(6>=a) a=2000000;
        else if(10>=a) a= 500000;
        else if(15>=a) a=300000;
        else a=100000;
    }

    if(b>31||b==0) b=0; // 본선 진출 X와 순위권 X를 고려
    else{
        if(b==1) b=5120000;
        else if(3>=b) b=2560000;
        else if(7>=b) b=1280000;
        else if(15>=b) b= 640000;
        else  b=320000;
    }

    return a+b;
}
