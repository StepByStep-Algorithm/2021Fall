#include <iostream>
#include <string>

using namespace std;
int call;

void cutNadd(string& digits);

int main(){
    string digits;
    cin >> digits;

    call = 0;
    cutNadd(digits);

    cout << call << "\n";
    if(digits[0] % 3 == 0) cout << "YES";
    else cout << "NO";

    return 0;
}

void cutNadd(string& digits){
    if(digits.length() == 1) return;

    int sum = 0;
    for (int i = 0 ; i < digits.length() ; i++) sum += digits[i] - '0';

    string newdigits;

    do{
        newdigits += (sum % 10) + '0'; sum /= 10;
    }while(sum > 0);
    
    call++;
    cutNadd(newdigits);
}