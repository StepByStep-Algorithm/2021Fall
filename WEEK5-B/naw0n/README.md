## 최소 신장 트리(Minimum Spanning Tree)
- Spanning Tree(그래프 내의 모든 정점을 포함하는 트리)에서 n개의 정점을 가지는 그래프의 최소 간선의 수는 n-1개
- n-1개의 간선으로 연결되어 있으면 필연적으로 트리 형태가 된다.
- DFS, BFS를 이용하여 그래프에서 신장 트리를 찾을 수 있음. 
- 하나의 그래프에는 많은 spanning tree가 존재할 수 있다.
- spanning tree는 모든 정점이 연결되어 있어야 하고, 사이클을 포함해서는 안된다.

## DfS(Depth-First-Search) 깊이 우선 탐색
- 최대한 깊이 내려간 후, 더 이상 깊이 갈 곳이 없을 경우 옆으로 이동
- 루트 노드(혹은 임의의 노드)에서 시작해서 다음 branch로 넘어가기 전에 해당 branch를 완벽하게 탐색하는 방식
- 경로의 특징을 저장해야할 경우

1. 모든 노드를 방문하고자 하는 경우에 방법을 사용
2. 깊이 우선 탐색(DFS)이 너비 우선 탐색(BFS)보다 더 간단함
3. 검색 속도는 너비 우선 탐색(BFS)에 비해 느림.

```c++
void dfs(int n, int v) {
	dfs_check[v] = 1;
	cout << v << " ";

	for (int i = 1; i <= n; i++)
		if (line[v][i] && !dfs_check[i])
			dfs(n, i);
}
```

## BFS(Breadth-First-Search) 너비 우선 탐색
- 최대한 넓게 이동한 다음, 더 이상 갈 수 없을 때 아래로 이동
- 루트 노드(혹은 임의의 노드)에서 시작해 인접한 노드를 먼저 탐색하는 방식
- 시작 정점으로부터 가까운 정점을 먼저 방문하고 멀리 떨어져 있는 정점을 나중에 방문
- 최단 경로를 찾을 경우 사용

ex) 친구관계
- DFS : 모든 친구 관계를 살펴야할 수도 있음
- BFS : A와 가까운 관계부터 탐색

## DFS와 BFS 비교
|DFS(깊이우선탐색)|BFS(너비우선탐색)|
|------|---|
|현재 정점에서 갈 수 있는 점들까지 들어가면서 탐색|현재 정점에서 연결된 가까운 점들부터 탐색|
|스택, 재귀함수로 구현|큐로 구현|


```c++
void bfs(int n, int v) {
	queue<int> q;

	bfs_check[v] = 1;
	q.push(v);
	while (!q.empty()) {
		int now = q.front();
		cout << now << " ";
		q.pop();
		for (int i = 1; i <= n; i++)
			if (line[now][i] && !bfs_check[i]) {
				q.push(i);
				bfs_check[i] = 1;
			}
	}
}
```
