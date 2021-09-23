# <목록>
1. 깊이우선탐색(BFS)
<br>
<br>

##  1) 깊이우선탐색(BFS)
+ 특징
	+ 현재 정점에 연결된 가까운 점들부터 탐색

```C++
void bfs(int start, vector<int> graph[], bool check[]){
	queue<int> q;
	q.push(start);
	check[start] = true;

	while(!q.empty()){
		int tmp = q.front();
		q.pop();
		printf("%d ",tmp);
		for(int i=0; i<graph[tmp].size(); i++){
			if(check[graph[tmp][i]] == false){
				q.push(graph[tmp][i]);
				check[graph[tmp][i]] = true;
			}
		}
	}
}
```