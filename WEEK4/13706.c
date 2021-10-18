#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sqrt(int start, int end, int n) {
	int mid;
	mid = (start + end) / 2;

	if ( mid > n / mid) sqrt(start, mid - 1, n);
	else if (mid < n / mid) sqrt(mid + 1, end, n);
	else return mid;
}

int main() {
	int n;
	int res;

	scanf("%d", &n);

	res = sqrt(1, n, n);
	printf("%d", res);

}

