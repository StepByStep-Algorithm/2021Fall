#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;

int N, sx, sy, MIN = 1000001;
int arr[51][51];
int visited[51][51] = { 0, };
vector<int> V;
vector<pair<int, int>> VK;

void dfs(int x, int y, int l, int r) {
	int dx[8] = { 1,-1,0,0,1,1,-1,-1 };
	int dy[8] = { 0,0,1,-1,1,-1,1,-1 };
	if (arr[x][y] < l || arr[x][y] > r)
		return;
	visited[x][y] = 1;
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[nx][ny] && arr[nx][ny] >= l && arr[nx][ny] <= r) {
			visited[nx][ny] = 1;
			dfs(nx, ny, l, r);
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char temp;
			cin >> temp;
			if (temp == 'P') {
				sx = i;
				sy = j;
			}
			else if (temp == 'K')
				VK.push_back({ i,j });
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int temp;
			cin >> arr[i][j];
			V.push_back(arr[i][j]);
		}
	}
	sort(V.begin(), V.end());
	V.erase(unique(V.begin(), V.end()), V.end());
	int l = 0, r = 0;
	while (1) {
		if (r >= V.size()) break;
		while (1) {
			int flag = 0;
			int left = V[l];
			int right = V[r];
			dfs(sx, sy, left, right);

			for (int i = 0; i < VK.size(); i++) {
				if (!visited[VK[i].first][VK[i].second])
					flag = 1;
			}

			for (int i = 0; i < N; i++)
				for (int j = 0; j < N; j++)
					visited[i][j] = 0;

			if (flag)
				break;
			MIN = min(MIN, right - left);
			l += 1;
		}
		r += 1;
	}
	printf("%d\n", MIN);
}