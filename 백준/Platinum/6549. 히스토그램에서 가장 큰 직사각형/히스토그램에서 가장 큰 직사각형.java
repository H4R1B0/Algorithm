import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int N;
    static long[] arr = new long[100010];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while (true) {
            Arrays.fill(arr,0);
            StringTokenizer st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            if (N == 0)
                break;
            for (int i = 1; i <= N; i++)
                arr[i] = Integer.parseInt(st.nextToken());
            Stack<Integer> stack = new Stack<>();
            stack.add(0);
            long answer = 0;
            for (int i = 1; i <= N + 1; i++) {
                while (!stack.isEmpty() && arr[stack.peek()] > arr[i]) {
                    int idx = stack.pop();
                    answer = Math.max(answer, arr[idx] * (long)(i - stack.peek() - 1));
                }
                stack.add(i);
            }
            System.out.println(answer);
        }
    }
}