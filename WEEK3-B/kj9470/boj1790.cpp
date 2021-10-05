// BOJ 1790번 : 수 이어 쓰기 2
#include <iostream>
using namespace std;
long long length(int n);
int result(int n, int k);

int main() {
    int n, k;
    cin >> n >> k;

    if(length(n) < k){
        cout << -1 << '\n';
        return 0;
    }

    int res = result(n, k);
    string s = to_string(res);
    long long l = length(res);
    cout << s[s.size() - (l - k) - 1] << '\n';
}

long long length(int n){
    long long count = 0;
    for(int i = 1, j = 1; i <= n; i *= 10, j++){
        int end = i * 10 - 1;
        if(end >= n){
            count += (long)((n - i + 1) * j);
        }
        else{
            count += (long)((end - i + 1) * j);
        }
    }
    return count;
}

int result(int n, int k){
    int left = 1;
    int right = n;
    int result = 0;
    while(left <= right){
        int mid = (left + right) / 2;
        long long len = length(mid);
        if(k > len){
            left = mid + 1;
        }
        else{
            result = mid;
            right = mid - 1;
        }
    }
    return result;
}


