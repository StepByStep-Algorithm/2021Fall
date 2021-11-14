import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Scanner;
import java.util.Queue;

class Pair {
	int x;
	int y;

	Pair(int x, int y) {
		this.x = x;
		this.y = y;
	}
}

public class Main {

	// arr에서 값이 find인 좌표를 ArrayList에 담아서 반환
	public static ArrayList<Pair> getArli(int arr[][], int find) {
		ArrayList<Pair> res = new ArrayList<>();
		for (int i = 0; i < arr.length; ++i) {
			for (int j = 0; j < arr[0].length; ++j) {
				if (arr[i][j] == find)
					res.add(new Pair(i, j));
			}
		}
		return res;
	}

	// 개수만 반환.
	public static int getCnt(int arr[][], int find) {
		int cnt = 0;
		for (int i = 0; i < arr.length; ++i) {
			for (int j = 0; j < arr[0].length; ++j) {
				if (arr[i][j] == find)
					++cnt;
			}
		}
		return cnt;
	}

	// 바이러스를 따라 0을 2로 바꿈.
	public static void bfs(int arr[][], Pair t) {
		Queue<Pair> q = new LinkedList<>();
		q.add(t);
		while (!q.isEmpty()) {
			Pair cur = q.poll();
			arr[cur.x][cur.y] = 2;

			// right. 0이면 q에 넣는다.
			if (cur.y + 1 <= arr[0].length - 1 && arr[cur.x][cur.y + 1] == 0) {
				q.add(new Pair(cur.x, cur.y + 1));
			}
			// left
			if (cur.y - 1 >= 0 && arr[cur.x][cur.y - 1] == 0) {
				q.add(new Pair(cur.x, cur.y - 1));
			}
			// up
			if (cur.x - 1 >= 0 && arr[cur.x - 1][cur.y] == 0) {
				q.add(new Pair(cur.x - 1, cur.y));
			}
			// down
			if (cur.x + 1 <= arr.length - 1 && arr[cur.x + 1][cur.y] == 0) {
				q.add(new Pair(cur.x + 1, cur.y));
			}
		}

	}
	public static void printArr(int arr[][]) {
		for (int i = 0; i < arr.length; ++i) {
			for (int j = 0; j < arr[0].length; ++j) {
				System.out.print(arr[i][j]+" ");
			}
			System.out.println();
		}
	}
	
	public static int[][] arrCopy(int arr[][]){
		int res[][]=new int[arr.length][arr[0].length];
		for (int i=0; i<arr.length;++i) {
			System.arraycopy(arr[i], 0, res[i], 0, arr[0].length);
		}
		return res;
	}
	
	public static int solve(int arr[][]) {
		ArrayList<Pair> virus = getArli(arr, 2);
		ArrayList<Pair> empty = getArli(arr, 0);
		final int EM_SIZE = empty.size();
		int max = 0;
		// 3개의 조합
		for (int i = 0; i < EM_SIZE; ++i) {
			for (int j = i + 1; j < EM_SIZE; ++j) {
				for (int k = j + 1; k < EM_SIZE; ++k) {
					//arr의 copy로 작업해야 한다.
					int copy[][]=arrCopy(arr);
					
					
					// 벽 세우기
					Pair a = empty.get(i);
					Pair b = empty.get(j);
					Pair c = empty.get(k);
					copy[a.x][a.y] = 1;
					copy[b.x][b.y] = 1;
					copy[c.x][c.y] = 1;

					// 바이러스가 있는 곳에서 bfs시작
					for (int l = 0; l < virus.size(); ++l) {
						bfs(copy, virus.get(l));
					}
					
					int cnt = getCnt(copy, 0);
					max = max < cnt ? cnt : max;
					
					//debugging
//					System.out.println("max : "+max);
//					printArr(copy);
//					System.out.println();
					
					//아니라면 벽 다시 지우기A
					copy[a.x][a.y] = 0;
					copy[b.x][b.y] = 0;
					copy[c.x][c.y] = 0;
				}
			}
		}
		return max;
	}

	public static void main(String[] args) {
		int N, M;
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		M = sc.nextInt();
		int arr[][] = new int[N][M];
		for (int i = 0; i < arr.length; ++i) {
			for (int j = 0; j < arr[0].length; ++j) {
				arr[i][j] = sc.nextInt();
			}
		}
		sc.close();
		System.out.println(solve(arr));

	}

}
