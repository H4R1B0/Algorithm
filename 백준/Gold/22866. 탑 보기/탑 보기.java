import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[] arr = new int[N + 1];
        int[] cnt = new int[N + 1];
        int[] near = new int[N + 1];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
            near[i] = -100000;
        }

        Stack<Integer> stk = new Stack<>();
        for (int i = 1; i <= N; i++) {
            while (!stk.isEmpty() && arr[stk.peek()] <= arr[i]) {
                stk.pop();
            }
            cnt[i] = stk.size();
            if (cnt[i] > 0) {
                near[i] = stk.peek();
            }
            stk.push(i);
        }
        stk.clear();
        for (int i = N; i >= 1; i--) {
            while (!stk.isEmpty() && arr[stk.peek()] <= arr[i]) {
                stk.pop();
            }
            cnt[i] += stk.size();
            if (!stk.isEmpty() && stk.peek() - i < i - near[i]) {
                near[i] = stk.peek();
            }
            stk.push(i);
        }
        StringBuilder answer = new StringBuilder();
        for (int i = 1; i <= N; i++) {
            answer.append(cnt[i]);
            if (cnt[i] > 0) {
                answer.append(' ').append(near[i]);
            }
            answer.append('\n');
        }
        System.out.println(answer);
    }
}