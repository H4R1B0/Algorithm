import java.util.Scanner;

public class Main {
	static final int MAX = 1001;
	public static void main(String[] args) {
		int[] arr = new int[1001];
		int[] height = new int[1001];
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		
		int max = -1;
		int maxIdx = -1;
		for(int i=0;i<N;i++) {
			int x = sc.nextInt();
			int y = sc.nextInt();
			if(max < y) {
				max = y;
				maxIdx = x;
			}
			arr[x] = y;
		}
//		System.out.println(maxIdx);
		
		int curHeight = arr[0];
		for(int i=0;i<maxIdx;i++) {
			if(curHeight < arr[i]) {
				curHeight = arr[i];
			}
			height[i] = curHeight;
		}
		curHeight = arr[MAX-1];
		for(int i=MAX-1;i>=maxIdx;i--) {
			if(curHeight < arr[i]) {
				curHeight = arr[i];
			}
			height[i] = curHeight;
		}
		
		int answer=0;
		for(int i=0;i<MAX;i++) {
			answer+=height[i];
//			System.out.print(height[i]+" ");
		}
		System.out.println(answer);
	}
}
