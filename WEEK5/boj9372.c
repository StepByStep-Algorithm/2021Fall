#include <stdio.h>
#define MAX_COUNTRY 1000

void clearmatrix(int graph[][MAX_COUNTRY]) {
	for (int i = 0; i < MAX_COUNTRY; i++) {
		for (int j = 0; j < MAX_COUNTRY; j++) {
			graph[i][j] = 0;
		}
	}
}

void makematrix(int graph[][MAX_COUNTRY], int n) {
	int a, b;

	for (int i = 0; i < n; i++) {
		scanf_s("%d %d", &a, &b);
		graph[a + 1][b + 1] = 1;
		graph[b + 1][a + 1] = 1;
	}
}

int findpath(int graph[][MAX_COUNTRY], int startP, int preStartP, int n, int cnt) {
	int i, total = 0;
	if (cnt == n - 1) return cnt;

	for (i = 0; i < n; i++) {
		if (graph[startP - 1][i] == 1) {
			total++;
		}
	}
	for (i = 0; i < n; i++) {
		if (graph[startP - 1][i] == 1) {
			if (total == 1) {
				findpath(graph, i + 1, startP, n, cnt++);
			}
			else {
				if (startP != preStartP) findpath(graph, i + 1, startP, n, cnt++);
			}
		}
	}

}

int main()
{
	int testcase, n, m;
	int graph[MAX_COUNTRY][MAX_COUNTRY];
	int i, cnt = 0;

	scanf_s("%d", testcase);

	for (; testcase > 0; testcase--) {

		scanf_s("%d %d", &n, &m);

		clearmatrix(graph);
		makematrix(graph, n);

		for (i = 0; i < n; i++) {  //첫 시작을 n가지 경우로 두기
			findpath(graph, i, 0, n, cnt);
		}
	}


	return 0;
}