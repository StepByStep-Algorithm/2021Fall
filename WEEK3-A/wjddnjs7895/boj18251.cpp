#include <iostream> 
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

long long MAX = 0;
int N, visited[262144], idx = 1, temp, SUM = 0, num = 0, num_max;
int graph[262144][4];
int arr[262144];

struct point {
	int x, y;
	int w;
};

vector<point> V;

int level(int n) {
	int cnt = 0;
	while (n) {
		n >>= 1;
		cnt += 1;
	}
	return cnt;
}

void dfs(int n, int y) {
	if (n * 2 <= N) {
		dfs(2 * n, y - 1);
	}
	V.push_back({ num, abs(y), arr[n] });
	num++;
	if (n * 2 + 1 <= N) {
		dfs(2 * n + 1, y - 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	int cnt = 0, flag = 0;
	cin.tie(0);
	cin >> N;
	cin >> arr[1];
	num_max = arr[1];
	for (int i = 2; i <= N; i++) {
		cin >> arr[i];
		num_max = max(arr[i], num_max);
		if (arr[i] >= 0)
			flag = 1;
		if (i % 2 == 1) {
			graph[i][1] = idx;
			graph[idx][3] = i;
			idx += 1;
		}
		else {
			graph[i][0] = idx;
			graph[idx][2] = i;
		}
	}

	dfs(1, 0);
	int height = level(N);
	for (int y1 = 0; y1 <= height; y1++) {
		for (int y2 = y1; y2 <= height; y2++) {
			long long SUM = 0;
			for (int x = 0; x < N; x++) {
				if (V[x].y >= y1 && V[x].y <= y2) {
					SUM = max(SUM + V[x].w, 0LL);
					MAX = max(MAX, SUM);
				}
			}
		}
	}
	if (flag)
		printf("%lld\n", MAX);
	else
		printf("%d\n", num_max);
}