import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        Stack<Integer> stack = new Stack<>();
        StringTokenizer st = null;
        int answer = 0;
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            while (!stack.isEmpty() && b < stack.peek()) {
                answer++;
                stack.pop();
            }
            if (stack.isEmpty() || b != stack.peek()) {
                stack.push(b);
            }
        }
        while (!stack.isEmpty()) {
            if (stack.peek() > 0) {
                answer++;
            }
            stack.pop();
        }
        System.out.println(answer);
    }
}