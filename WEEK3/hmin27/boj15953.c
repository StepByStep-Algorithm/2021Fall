#include <stdio.h>
#include <stdlib.h>
int rankA(int *pz1, int a) {
	int i, rankA = 1;
	int resA;

	if (a > 21 || a == 0) resA = 0;
	else {
		for (i = 1; i < 7; i++) {
			if (a <= rankA) {
				resA = pz1[i - 1];
				break;
			}
			rankA += i + 1;
		}
	}

	return resA;
}
	
int rankB( int *pz2, int b) {
	int i, rankB = 1;
	int resB;
	int temp = 1;

	if (b > 31 || b == 0) resB = 0;
	else {
		for (i = 1; i < 6; i++) {
			if (b <= rankB) {
				resB = pz2[i - 1];
				break;
			}

			temp *= 2;
			rankB += temp;
		}
	}

	return resB;
}

int main()
{
	int *queue;
	int prize1[6] = { 500, 300, 200, 50, 30, 10},
		prize2[5] = { 512, 256, 128, 64, 32};
	int front, rear;
	int size, i, resA, resB;

	scanf("%d", &size);

	queue = (int *)malloc(sizeof(int) * size * 2);
	front = 0;
	rear = -1;

	for (i = 0; i < size * 2; i++) {
		scanf("%d", &queue[i]);
		rear++;
	}

	while(front < rear) {
		resA = rankA(prize1, queue[front++]);
		resB = rankB(prize2, queue[front++]);
		printf("%d\n", (resA+resB)*10000);
	}

	return 0;
}