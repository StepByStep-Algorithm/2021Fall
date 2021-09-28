import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;


class Triple {
	int a;
	int b;
	int c;

	Triple(int a, int b, int c) {
		this.a = a;
		this.b = b;
		this.c = c;
	}
}

public class Main {

	public static void main(String[] args) {
		int N, M;
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		M = sc.nextInt();

		// 입력
		int arr[][] = new int[N][M];
		for (int i = 0; i < N; ++i) {
			String str = sc.next();
			for (int j = 0; j < str.length(); ++j) {
				arr[i][j] = str.charAt(j)-'0';
			}
		}

		//방향
		int dir[][] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };
		
		// 방문을 관리하는 3차원 배열인 동시에 거리를 나타냄. 0, 1만 들어가는 것이 아니라 지금까지 온 거리가 저장된다.
		// 마지막인덱스는 벽을 뚫은 횟수
		int isVisited[][][] = new int[N][M][2];
		
		Queue<Triple> q = new LinkedList<>();
		q.add(new Triple(0, 0, 0));
		isVisited[0][0][0] = 1;
		while (!q.isEmpty()) {
			Triple cur = q.poll();
			//종료조건
			if (cur.a==N-1 && cur.b == M-1) {
				System.out.println(isVisited[cur.a][cur.b][cur.c]);
				return;
			}
			
			for (int i=0; i<dir.length; ++i) {
				Triple temp=new Triple(cur.a, cur.b, cur.c);
				temp.a+=dir[i][0];
				temp.b+=dir[i][1];
				if (0 <= temp.a && temp.a<=N-1 && 0<=temp.b && temp.b<=M-1 && isVisited[temp.a][temp.b][temp.c]==0) {
					if (arr[temp.a][temp.b]==0) {
						q.add(new Triple(temp.a, temp.b, temp.c));
						isVisited[temp.a][temp.b][temp.c]=isVisited[cur.a][cur.b][cur.c]+1;
					}
					else if (temp.c==0){ //arr[][]=1이고 temp.c=0일 때
						q.add(new Triple(temp.a, temp.b, 1));
						isVisited[temp.a][temp.b][1]=isVisited[cur.a][cur.b][cur.c]+1;
					}
				}
			}//for end
		}//while end
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
