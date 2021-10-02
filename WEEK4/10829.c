#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void divideByTwo(long long share) {
	long long remainder;
	
	remainder = share % 2;
	share /= 2;


	if (share == 1) printf("%lld%lld", share, remainder);
	else {
		divideByTwo(share);
		printf("%lld", remainder);
	}

}
int main() {

	long long a;

	scanf("%lld", &a);
	divideByTwo(a);

	return 0;
}