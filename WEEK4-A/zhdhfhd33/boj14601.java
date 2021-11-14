import java.util.Scanner;

public class Main {
	public static int cnt = 1;
	// 2*2배열을 기준으로 비는 곳의 좌표를 사용해서 방향을 나타낸다. dir=1~4
	// a, b는
	public static void printArr(int arr[][]) {
		for (int i = 0; i < arr.length; ++i) {
			for (int j = 0; j < arr[0].length; ++j) {
				System.out.print(arr[i][j] + " ");
			}
			System.out.println();
		}
	}

	public static void draw(int arr[][], int a, int b, int dir) {
		if (dir == 1) {
			arr[a][b + 1] = cnt;
			arr[a + 1][b] = cnt;
			arr[a + 1][b + 1] = cnt;
		} else if (dir == 2) {
			arr[a][b] = cnt;
			arr[a][b + 1] = cnt;
			arr[a + 1][b + 1] = cnt;
		} else if (dir == 3) {
			arr[a][b] = cnt;
			arr[a][b + 1] = cnt;
			arr[a + 1][b] = cnt;
		} else if (dir == 4) {
			arr[a][b] = cnt;
			arr[a + 1][b] = cnt;
			arr[a + 1][b + 1] = cnt;
		} else {
			System.out.println("draw() error!!");
		}
		++cnt;
	}

	// dir는 몇사분면에 배수구가 있는지 표현. 1~4 사분면으로 표시
	// a,b는 ㄴ을 포함하는 사각형의 left, up좌표
	// sz는 ㄴ자의 가장 긴 변의 길이의 반을 의미..
	public static void divide(int arr[][], int a, int b, int dir, int sz) {
		if (sz <= 1) {
			draw(arr, a, b, dir);
			return;
		}
		if (dir == 1) {
			divide(arr, a, b + sz, 2, sz / 2);
			divide(arr, a + sz / 2, b + sz / 2, 1, sz / 2);
			divide(arr, a + sz, b + sz, 1, sz / 2);
			divide(arr, a + sz, b, 4, sz / 2);
		} else if (dir == 2) {
			divide(arr, a, b, 3, sz / 2);
			divide(arr, a + sz / 2, b + sz / 2, 2, sz / 2);
			divide(arr, a, b + sz, 2, sz / 2);
			divide(arr, a + sz, b + sz, 1, sz / 2);
		} else if (dir == 3) {
			divide(arr, a, b, 3, sz / 2);
			divide(arr, a + sz / 2, b + sz / 2, 3, sz / 2);
			divide(arr, a, b + sz, 2, sz / 2);
			divide(arr, a + sz, b, 4, sz / 2);
		} else if (dir == 4) {
			divide(arr, a, b, 3, sz / 2);
			divide(arr, a + sz / 2, b + sz / 2, 4, sz / 2);
			divide(arr, a + sz, b + sz, 1, sz / 2);
			divide(arr, a + sz, b, 4, sz / 2);
		} else {
			System.out.println("divied error!!");
		}
	}

	// a,b, sz는 탐색하고자 하는 상자의 왼쪽 위 좌표, 한변의 길이이다.
	// targetA, targetB는 -1이 있는 위치임.
	public static int getDir(int arr[][], int a, int b, final int sz, int targetA, int targetB) {
		int dir;
		if (targetA <= (a + sz / 2 - 1)) {
			if (targetB <= (b + sz / 2 - 1)) {
				dir = 1;// 1사분면
			} else {
				dir = 4;
			}
		} else {
			if (targetB <= (b + sz / 2 - 1) ) {
				dir = 2;
			} else {
				dir = 3;
			}
		}
		return dir;
	}

	public static void main(String[] args) {
		// 4*4에서는 배수구가 어디 위치하던간에 배치할 수 있다.
		// 8*8, 16*16은 4*4의 합으로 나타낼 수 있다. 결국 2의 제곱수이기만 한다면 배수구가 어디 위치하든지 비울 수 있음
		// 빈칸을 비우는 것은 쉽다. 다만 나머지를 어떻게 채울지가 중요함. 기본 단위 타일이 3칸으로 이뤄져 있다.
		// 채워야하는 타일의 총 수가 3의 배수이면 어떻게든 할당이 가능한 것을 발견. 일직선이든 ㄴ모양이든 상관없이 3의 배수이기만 하면 된다.

		Scanner sc = new Scanner(System.in);
		int N = (int) Math.pow(2, sc.nextInt());
		int arr[][] = new int[N][N];

		int a, b;
		b = sc.nextInt() - 1; // col
		a = N - (sc.nextInt()); // row

		// 처음 사각형에서 몇사분면에 있는지 확인하자.
		int dir = 0;
		dir = getDir(arr, 0, 0, N, a, b);

		int cnt = 1;
		arr[a][b] = -1;
//		printArr(arr);
		int sz = N / 2;
		divide(arr, 0, 0, dir, sz);
		sz /= 2;
		int startA=0, startB=0;
		
		while (sz >= 1) {
			if (dir == 1) {
//				startA=+0;
//				startB=+0;
				dir = getDir(arr, startA+0, startB+0, 2 * sz, a, b);
				divide(arr, startA+0, startB+0, dir, sz);
			} else if (dir == 2) {
				startA+=2*sz;
//				startB=+0;
				dir = getDir(arr, startA, startB, 2 * sz, a, b);
				divide(arr, startA, startB, dir, sz);
			} else if (dir == 3) {
				startA+=2*sz;
				startB+=2*sz;
				dir = getDir(arr, startA, startB, 2 * sz, a, b);
				divide(arr, startA, startB, dir, sz);
			} else if (dir == 4) {
//				startA=+0;
				startB+=2*sz;
				dir = getDir(arr, startA, startB, 2 * sz, a, b);
				divide(arr, startA, startB, dir, sz);
			}
//			System.out.println(dir);
			sz /= 2;
		}
		printArr(arr);

	}

}
