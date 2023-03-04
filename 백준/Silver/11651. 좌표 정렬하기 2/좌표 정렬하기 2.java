import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		ArrayList<Pos> positions = new ArrayList<>();
		for(int i=0;i<N;i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			positions.add(new Pos(a,b));
		}
		Collections.sort(positions);
		
		for(Pos pos : positions) {
			System.out.println(pos.x+" "+pos.y);
		}
	}
	static class Pos implements Comparable<Pos>{
		int x, y;
		Pos(int x, int y){
			this.x = x;
			this.y = y;
		}
		@Override
	    public int compareTo(Pos pos) {
			if(pos.y == y)
				return pos.x<x?1:-1;
			return pos.y<y?1:-1;
	    }
	}
}