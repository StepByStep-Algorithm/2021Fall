import java.util.Scanner;

class Pair {
	public int a;
	public int b;

	public Pair(int a, int b) {
		this.a = a; // 가로, x좌표
		this.b = b;// 세로, y좌표
	}

	@Override
	public String toString() {
		return "[a=" + a + ", b=" + b + "]";
	}

}

public class Main {


//a,b 는 왼쪽 위 좌표. c,d는 각각 가로, 세로길이
	public static boolean isBox(int plate[][], int a, int b, int c, int d) {
		for (int i = a; i <= a + c; ++i) {
			for (int j = b; j <= b + d; ++j) {
				if (plate[i][j] == 0) {
					return false;
				}
			}
		}
		return true;

	}

	public static void main(String[] args) {
		int N;
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		Pair[] pairs = new Pair[N];// java에서 배열은 공간일 뿐. 객체는 다시 생성해줘야한다.

		for (int i = 0; i < N; i++) {
			int a, b;
			b = (sc.nextInt() - 1);
			a = 99 - (sc.nextInt() + 8);
			pairs[i] = new Pair(a, b);// pairs에는 왼쪽 위의 점좌표를 저장.
		}
		sc.close();
		int plate[][] = new int[100][100];

		// 그리기. 1이 있으면 검은색종이
		for (Pair t : pairs) {
			for (int i = 0; i < 10; ++i) {
				for (int j = 0; j < 10; ++j) {
					plate[(t.a + i)][(t.b + j)] = 1;
				}
			}
		}

		// 규칙을 찾아서 해결할랬는데 쉽지않다. 다 검사하는게 맞는 듯.
		// 유효한 규칙. 최댓값은 point에서 나온다. no
		// 내부점은 안해도 된다.x -> 100*100 모든 점에 대해서 다 해야함
		// dfs사용하려 했으나 x
		final int LEN = 100;
		int area = 100;
		for (int a = 0; a < LEN; ++a) {// 모든 left, up 꼭짓점에 대해 진행
			for (int b = 0; b < LEN; ++b) {
				for (int j = 1; a + j < LEN; ++j) {
					for (int k = 1; b + k < LEN; ++k) {
						if (isBox(plate, a, b, j, k)) {
							area = Math.max(area, (j + 1) * (k + 1));
//							System.out.println(area);
						} else {
							break;
						}
					}
				}
			}

		}
		System.out.println(100 < area ? area : 100);

	}

}
