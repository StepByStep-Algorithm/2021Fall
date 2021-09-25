#include <iostream>
using namespace std;

int main() {
    string str;
    int count = 0;
    cin>>str;
    for (int i = 0; i<str.length(); i++) {
        if (str[i] == 'c') {
            if (str[i + 1] == '=') i++;
            else if (str[i + 1] == '-') i++;
        }
        if (str[i] == 'd') {
            if (str[i + 1] == 'z'&&str[i + 2] == '=') i += 2;
            else if (str[i + 1] == '-') i++;
        }
        if (str[i + 1] == 'j') {
            if (str[i] == 'l') i++;
            else if (str[i] == 'n') i++;
        }
        if (str[i + 1] == '=') {
            if (str[i] == 's') i++;
            else if (str[i] == 'z') i++;
        }
        count++;
    }
    cout<<count;
    return 0;
}
