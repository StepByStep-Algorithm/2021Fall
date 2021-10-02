#include <stdio.h>

int compare(int a, int b)
{
	if (a % b == 0) return 1;
	else
	{
		if (b % a == 0) return 2;
		else return 3;
	}
}
int main()
{
	int num[2];
	int i = 0, res;

	while (1) {
		scanf("%d", &num[i%2]);
		if (i % 2 == 1) {
			if (num[0] == 0 && num[1] == 0) break;
			else
			{
				res = compare(num[0], num[1]);
			}

			switch (res) {
			case 1: printf("multiple\n"); break;
			case 2: printf("factor\n"); break;
			case 3: printf("neither\n"); break;
			}
		}

		i++;
	}
	return 0;
}