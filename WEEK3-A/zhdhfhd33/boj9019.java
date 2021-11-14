import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

//path는 경로이면서 동시에 명령을 뜻함. path의 가장 마지막 문자는 수행해야하는 명령을 가리킨다.
class Unit {
	int str;
	String path;

	Unit(int str, String path) {
		this.str = str;
		this.path = path;
	}

	// 정상동작하지 않으면 -1반환
	public int doCommand() {
		switch (path.charAt(path.length() - 1)) {
		case 'D':
			return Main.D(str);
		case 'S':
			return Main.S(str);
		case 'L':
			return Main.L(str);
		case 'R':
			return Main.R(str);
		default:
			return -1;
		}

	}

	public String toString() {
		return "path : " + path + " str : " + str;
	}
}//Unit end

public class Main {
	public static int D(int str) {
//		String copy = String.valueOf(str);
		int num = str;
		num = 2 * num % 10000;
		return num;
	}

	public static int S(int str) {
		int num = str;
		num = num - 1 <= -1 ? 9999 : num - 1;
		return num;
	}

	

	public static int L(int str) {
//		char ch[] = new char[4];
//		// 0으로 초기화. char배열은 생성하면 ''으로 초기화 되어있음.
//		for (int i = 0; i < ch.length; ++i) {
//			ch[i] = '0';
//		}
//		// str->ch 복사
//		for (int i = str.length() - 1, idx = ch.length - 1; i >= 0; --i, --idx) {
//			ch[idx] = str.charAt(i);
//		}
//
//		char tmp = ch[0];
//		for (int i = 0; i + 1 < ch.length; ++i) {
//			ch[i] = ch[i + 1];
//		}
//		ch[ch.length - 1] = tmp;
//		return String.valueOf(ch);
		int num=Integer.valueOf(str);
		num=(num % 1000) * 10 + num / 1000;
		return num;
	}

	public static int R(int str) {
//		char ch[] = new char[4];
//		// 0으로 초기화. char배열은 생성하면 ''으로 초기화 되어있음.
//		for (int i = 0; i < ch.length; ++i) {
//			ch[i] = '0';
//		}
//		// str->ch 복사
//		for (int i = str.length() - 1, idx = ch.length - 1; i >= 0; --i, --idx) {
//			ch[idx] = str.charAt(i);
//		}
//
//		char tmp = ch[ch.length - 1];
//		for (int i = ch.length - 1; i - 1 >= 0; --i) {
//			ch[i] = ch[i - 1];
//		}
//		ch[0] = tmp;
//		return String.valueOf(ch);
		int num=str;
		num=(num % 10) * 1000 + (num / 10);
		return num;
	
	}

	// bfs를 이용. 이런 형태를 위해서는 Q를 사용할 수 밖에 없나봄. 반복문으로 될줄 알았는데
	// D=0, S=1, L=2, R=3
	// 실패시 null반환
	public static Unit solve(int start, int end) {
		Queue<Unit> q = new LinkedList<>();
		int[] isVisited = new int[10000];// 9999까지
		String command[] = { "D", "S", "L", "R" };

		// 초기조건 : 큐에 넣고 방문처리
		isVisited[Integer.valueOf(start)] = 1;
		for (int i = 0; i < 4; ++i) {
			q.add(new Unit(start, command[i]));
		}

		while (!q.isEmpty()) {
			Unit a = q.poll();
			a.str = a.doCommand(); //고생함. 실행하고 검사해야된다. 1 1 1같은 입력조건에 대비해서 먼저 검사하고 실행하는 방법을 선택했었는데 그렇게 되면 q는 다 비워졌지만 답을 못찾을 때가 있음.
			//null ptr exception남. 아마도 path의 마지막 명령을 실행해주지 않아서 정답을 못찾은 듯.
			if (Integer.valueOf(a.str)==end) {
				return a; // 처음부터 같을 수도 있잖아. doCommand()하기전에 검사하자.
			}
			
			//다음 녀석이 넣을 수 있는지 검사하고 넣어야 한다.
			//D
			int method= D(a.str);
			if (isVisited[method] == 0) {
				q.add(new Unit(a.str, a.path+"D"));
				isVisited[method] = 1;
			}
			//S
			method=S(a.str);
			if (isVisited[method] == 0) {
				q.add(new Unit(a.str, a.path + "S"));
				isVisited[method] = 1;
			}
			//L
			method=L(a.str);
			if (isVisited[method] == 0) {
				q.add(new Unit(a.str, a.path + "L"));
				isVisited[method] = 1;
			}
			//R
			method=R(a.str);
			if (isVisited[method] == 0) {
				q.add(new Unit(a.str, a.path + "R"));
				isVisited[method] = 1;
			}
		}
		return null;
	}

	public static void main(String[] args) {
		int T;
		Scanner sc = new Scanner(System.in);
		T = sc.nextInt();
		while (T-- != 0) {
			int a, b;
			a = sc.nextInt();
			b = sc.nextInt();

			Unit res = solve(a, b);
			System.out.println(res.path);

		}
		sc.close();
	}

}
