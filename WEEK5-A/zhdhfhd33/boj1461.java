import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {

//	public static int findMax(List<Integer> location, final int M) {
//		int a=Math.abs(location.get(0));
//		int b=Math.abs(location.get(location.size()-1));
//		if (a>b) {
//			return -1;//왼쪽이 더 멀다. 왼쪽을 마지막에
//		}
//		else if (a<b) {
//			return 1; //오른쪽이 더 멀다. 오른쪽을 마지막에
//		}
//		else {//절댓값이 같을 때
//			for (int i=0; i<M-1; ++i) {
//				if (i+1 < location.size() && location.get(i) * location.get(i+1) < 0) {//부호가 다를 때
//					return 1;
//				}
//			}
//			return -1; //M개를 선택했을 때 양쪽 다 부호가 다른 경우는 없다. 자동으로 -1 반환하면 된다.
//		}
//	}

	public static void main(String[] args) {
		final int N, M;
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		M = sc.nextInt();
		List<Integer> location = new ArrayList<>();
		for (int i = 0; i < N; ++i) {
			location.add(sc.nextInt());
		}
		sc.close();
		Collections.sort(location); // 오름차순
		int res=0;
//		System.out.println(location);//debug
//		final int SZ=location.size();
//		//이렇게 코드가 중복되면 뭔가 불편하다. 그냥 변수컨트롤 하고 실행하는 부분은 하나만, 코드가 중복되지 않게 짜자.
//		int judge =findMax(location, M);
//		if (judge==-1) {
//			res+=Math.abs(location.get(0));
//			for (int i=0; location.size()>=1 && i<M; ++i) {
//				location.remove(0);
//			}
//		}
//		else if (judge==1){
//			res+=Math.abs(location.get(SZ-1));
//			for (int i=0; location.size()>=1 && i<M; ++i) {
//				location.remove(SZ-1-i);
//			}
//		}
//		else {
//			System.out.println("error!");
//		}
//		System.out.println(location);//debug
//		
//		if (location.size()<1) { // 한번에 모든 책을 들고 갈 수 있는 경우 여기서 걸러짐
//			System.out.println(res);
//			return;
//		}
		int cur=0;
		int curNum=0;
		//음수일 때
		while (location.size()>cur && (curNum=location.get(cur))<0) {
			res+=Math.abs(curNum)*2;
			cur+=M;
		}
		cur=location.size()-1;
		//양수일 때
		while (cur >= 0 && (curNum=location.get(cur))>0) {
			res+=Math.abs(curNum)*2;
			cur-=M;
		}
		res-=Math.max(Math.abs(location.get(0)) ,Math.abs(location.get(location.size()-1) ));
		System.out.print(res);
	}
}
