import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine();
		int M = Integer.parseInt(br.readLine());
		Stack<String> left = new Stack<String>();
		Stack<String> right = new Stack<String>();
		String[] tmp = str.split("");
		for(String t:tmp) {
			left.push(t);
		}

		for (int i = 0; i < M; i++) {
			String[] cmd = br.readLine().split(" ");
			if (cmd[0].equals("L")) {
				if (!left.isEmpty())
					right.push(left.pop());
			} else if (cmd[0].equals("D")) {
				if (!right.isEmpty())
					left.push(right.pop());
			} else if (cmd[0].equals("B")) {
				if (!left.isEmpty())
					left.pop();
			} else if (cmd[0].equals("P")) {
				left.push(cmd[1]);
			}
		}
		
		while(!left.isEmpty())
			right.push(left.pop());
		StringBuilder sb = new StringBuilder();
		while(!right.isEmpty()) {
			sb.append(right.pop());
		}
		System.out.println(sb);
	}
}
