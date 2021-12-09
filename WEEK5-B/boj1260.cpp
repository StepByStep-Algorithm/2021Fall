#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;

vector<int> graph[10001];
int dfs_visited[1001] = { 0, };

void dfs(int v) {
	dfs_visited[v] = 1;
	cout << v << ' ';
	for (int i = 0; i < graph[v].size(); i++) {
		int next = graph[v][i];
		if (!dfs_visited[next])
			dfs(next);
	}
}

int bfs_visited[1001] = { 0, };
void bfs(int v) { 
	queue <int> q;
	bfs_visited[v] = 1;
	q.push(v);
	while (!q.empty()) {
		v = q.front();
		q.pop();
		cout << v << ' ';
		for (int i = 0; i < graph[v].size(); i++) {
			int next = graph[v][i];
			if (!bfs_visited[next]) {
				q.push(next);
				bfs_visited[next] = 1;
			}
		}
	}
}

int main() {
	int n, m, v;
	int a, b;

	cin >> n >> m >> v;
	while(m--){
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
		sort(graph[i].begin(), graph[i].end());

	dfs(v);
	cout << '\n';
	bfs(v);
	return 0;
}
