## Minimum-cost Spanning Trees
* 정의: 최소 신장 트린 동시에 edge에 weight의 비용이 추가된 트리
* Greedy method: 각각의 단계에서 가장 최적의 해결책을 찾아야 함
* 예시로는 Kruskal, Prim, Sollin의 알고리즘이 있음
    - constraints: 그래프 내의 edgw를 사용해야 함/ 정확하게 n-1개의 edge들을 사용해야 함/ cycle을 형성하는 edges은 사용하지 않을 수 있음

## Prim's Algorithm
모든 노드를 순회해야 할 때 최소의 비용을 택하는 알고리즘
1. 한 번에 하나의 edge를 선택
    * 이때 선택한 edge는 subtree T에서 이미 선택한 edge들과 연결이 되어있어야 함
    * (u,v) where u in T and v is not in T
2. T에서 egde가 cycle을 만들지 않는 한 계속해서 edge를 선택해서 T에 추가함
3. T의 edge 개수가 n-1개가 되면 시행 종료

이때 시간복잡도는 O(m logn)을 만족함
