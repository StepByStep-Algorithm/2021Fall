import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
//이렇게 n*m으로 가야하는 문제는 DFS는 좋지않다. 

class Unit {
	int num;
	int z;// 벽돌을 깬적 있으면 1, 없으면 0
	int dist;// distance

	Unit() {
		this.num = 0;
		this.z = 0;
		this.dist = 1;
	}
	public String toString() {
		return "num : "+num+"\nz : "+z+"\n"+"dist : "+dist;
	}
}

class Pair {
	int x;
	int y;

	Pair(int x, int y) {
		this.x = x;
		this.y = y;
	}
	public String toString() {
		return "x : "+x+"\ny : "+y;
	}

}



public class Main {
	//상하좌우 z를 새로고침함. x, y는 현재좌표
		public static void refreshZ(Unit arr[][], int x, int y) {
			int N=arr.length;
			int M=arr[0].length;
			// down
			if (x + 1 <= N - 1) {
				arr[x+1][y].z=arr[x][y].z;
			}

			// up
			if (x - 1 >= 0) {
				arr[x-1][y].z=arr[x-1][y].z;
			}
			// right
			if (y + 1 <= M - 1) {
				arr[x][y+1].z=arr[x][y].z;
			}
			// left
			if (y - 1 >= 0) {
				arr[x][y-1].z=arr[x][y].z;
			}
		}
		
		
	public static void main(String[] args) {
		int N, M;
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		M = sc.nextInt();
		Unit arr[][] = new Unit[N][M];
		for (int i = 0; i < N; ++i) {

			for (int j = 0; j < M; ++j) {

				arr[i][j] = new Unit(); // 자바에서는 객체 배열은 공간만 할당한 것임. like 포인터 배열
			}
		}
		
		
		// 입력부. java에는 %1d같은게 없나봐
		for (int i = 0; i < N; ++i) {
			String temp = sc.next();
			for (int j = 0; j < M; ++j) {

				arr[i][j].num = temp.charAt(j)-'0';//integer.valueOf()는 char에 대해 동작하지 않는다.
			}
		}

		// bfs
		int isVisited[][]=new int[N][M];
		Queue<Pair> q = new LinkedList<>();// queue는 ArrayList안된다. LinkedList만 됨.
		q.add(new Pair(0, 0));
		isVisited[0][0]=1;
		while (!q.isEmpty()) {
			Pair a = q.poll();
			refreshZ(arr, a.x, a.y); 
			//bfs가 끝나는 부분
			if (a.x == N - 1 && a.y == M - 1) {
				System.out.println(arr[a.x][a.y].dist);
				break;
			}
			// q.add()시작
			// down
			if (a.x + 1 <= N - 1 && isVisited[a.x+1][a.y]==0) {
				if (arr[a.x + 1][a.y].num == 0) {

					q.add(new Pair(a.x + 1, a.y));
					arr[a.x + 1][a.y].dist=arr[a.x][a.y].dist+1;
//					arr[a.x + 1][a.y].z=arr[a.x][a.y].z;
					isVisited[a.x+1][a.y]=1;
				} else if (arr[a.x + 1][a.y].z == 0) {
					q.add(new Pair(a.x + 1, a.y));
					arr[a.x + 1][a.y].z = 1;
					arr[a.x + 1][a.y].dist=arr[a.x][a.y].dist+1;
//					arr[a.x + 1][a.y].z=arr[a.x][a.y].z;
					isVisited[a.x+1][a.y]=1;
				}

			}

			// up
			if (a.x - 1 >= 0 && isVisited[a.x-1][a.y]==0) {
				if (arr[a.x - 1][a.y].num == 0) {

					q.add(new Pair(a.x - 1, a.y));
					arr[a.x - 1][a.y].dist=arr[a.x][a.y].dist+1;
//					arr[a.x - 1][a.y].z=arr[a.x][a.y].z;
					isVisited[a.x-1][a.y]=1;
				} else if (arr[a.x - 1][a.y].z == 0) {
					q.add(new Pair(a.x - 1, a.y));
					arr[a.x - 1][a.y].z = 1;
					arr[a.x - 1][a.y].dist=arr[a.x][a.y].dist+1;
//					arr[a.x - 1][a.y].z=arr[a.x][a.y].z;
					isVisited[a.x-1][a.y]=1;
				}

			}
			// right
			if (a.y + 1 <= M - 1 && isVisited[a.x][a.y+1]==0) {
				if (arr[a.x][a.y + 1].num == 0) {

					q.add(new Pair(a.x, a.y + 1));
					arr[a.x][a.y + 1].dist=arr[a.x][a.y].dist+1;
//					arr[a.x][a.y + 1].z=arr[a.x][a.y].z;
					isVisited[a.x][a.y+1]=1;
				} else if (arr[a.x][a.y + 1].z == 0) {
					q.add(new Pair(a.x, a.y + 1));
					arr[a.x][a.y + 1].z = 1;
					arr[a.x][a.y + 1].dist=arr[a.x][a.y].dist+1;
//					arr[a.x][a.y + 1].z=arr[a.x][a.y].z;
					isVisited[a.x][a.y+1]=1;
				}

			}
			// left
			if (a.y - 1 >= 0 && isVisited[a.x][a.y-1]==0) {
				if (arr[a.x][a.y - 1].num == 0) {

					q.add(new Pair(a.x, a.y - 1));
					arr[a.x][a.y - 1].dist=arr[a.x][a.y].dist+1;
//					arr[a.x][a.y - 1].z=arr[a.x][a.y].z;
					isVisited[a.x][a.y-1]=1;
				} else if (arr[a.x][a.y - 1].z == 0) {
					q.add(new Pair(a.x, a.y - 1));
					arr[a.x][a.y - 1].z = 1;
					arr[a.x][a.y - 1].dist=arr[a.x][a.y].dist+1;
//					arr[a.x][a.y - 1].z=arr[a.x][a.y].z;
					isVisited[a.x][a.y-1]=1;
				}

			}

		} // while end

		//dist출력 
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				System.out.printf("%d ", arr[i][j].dist);
			}
			System.out.println();
		}
		
		//q가 empty되었다는 것은 문제를 풀지 못했다는 것을 의미. -1을 출력.
		System.out.println("-1");

	}// main end
}

//13 13
//0100011011000
//0001001010000
//0000100001000
//1100010101011
//1111101111000
//1011010001001
//0100001001001
//0100111010001
//0101010000100
//0001110100000
//0000001000100
//1010001000111
//1001000100000
//
//정답 : 27
