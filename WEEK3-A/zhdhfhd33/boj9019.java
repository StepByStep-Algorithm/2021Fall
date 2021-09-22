import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

//path는 경로이면서 동시에 명령을 뜻함. path의 가장 마지막 문자는 수행해야하는 명령을 가리킨다.
class Unit {
	String str;
	String path;

	Unit(String str, String path) {
		this.str = str;
		this.path = path;
	}

	// 정상동작하지 않으면 null반환
	public String doCommand() {
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
			return null;
		}

	}

	public String toString() {
		return "path : " + path + " str : " + str;
	}
}//Unit end

public class Main {
	public static String D(String str) {
//		String copy = String.valueOf(str);
		int num = Integer.valueOf(str);
		num = 2 * num % 10000;
		return Integer.toString(num);
	}

	public static String S(String str) {
//		String copy = String.valueOf(str);
		int num = Integer.valueOf(str);
		num = num - 1 <= -1 ? 9999 : num - 1;
		return Integer.toString(num);
	}

	

	public static String L(String str) {
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
		return Integer.toString(num);
	}

	public static String R(String str) {
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
		int num=Integer.valueOf(str);
		num=(num % 10) * 1000 + (num / 10);
		return Integer.toString(num);
	
	}

	// bfs를 이용. 이런 형태를 위해서는 Q를 사용할 수 밖에 없나봄. 반복문으로 될줄 알았는데
	// D=0, S=1, L=2, R=3
	// 실패시 null반환
	public static Unit solve(String start, String end) {
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
			
			//debugging
//			System.out.println(a);
//			int cnt=0;
//			for (int i=0; i<isVisited.length; ++i) {
//				if (isVisited[i]==1) {
//					++cnt;
//				}
//			}
//			System.out.println("cnt : "+cnt);
			
			int ans=Integer.valueOf(end);
			a.str = a.doCommand(); //고생함. 실행하고 검사해야된다. 1 1 1같은 입력조건에 대비해서 먼저 검사하고 실행하는 방법을 선택했었는데 그렇게 되면 q는 다 비워졌지만 답을 못찾을 때가 있음.
			//null ptr exception남. 아마도 path의 마지막 명령을 실행해주지 않아서 정답을 못찾은 듯.
			if (Integer.valueOf(a.str)==ans) {
				return a; // 처음부터 같을 수도 있잖아. doCommand()하기전에 검사하자.
			}
			
			//다음 녀석이 넣을 수 있는지 검사하고 넣어야 한다.
			//D
			String str_method=D(a.str);
			int method= Integer.valueOf(str_method);
			if (isVisited[method] == 0) {
				q.add(new Unit(a.str, a.path+"D"));
				isVisited[method] = 1;
			}
			//S
			str_method=S(a.str);
			method=Integer.valueOf(str_method);
			if (isVisited[method] == 0) {
				q.add(new Unit(a.str, a.path + "S"));
				isVisited[method] = 1;
			}
			//L
			str_method=L(a.str);
			method=Integer.valueOf(str_method);
			if (isVisited[method] == 0) {
				q.add(new Unit(a.str, a.path + "L"));
				isVisited[method] = 1;
			}
			//R
			str_method=R(a.str);
			method=Integer.valueOf(str_method);
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
			String a, b;
			a = sc.next();
			b = sc.next();

			Unit res = solve(a, b);
//			System.out.println(res.str);
			System.out.println(res.path);

//			Unit test = new Unit("0", "S");
//			System.out.println(test.doCommand());
		}
		sc.close();
		//1 4892 684
	}

}
