import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static int N, answer;
    static boolean[] broken = new boolean[10];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        answer = Math.min(Integer.MAX_VALUE, Math.abs(N - 100));
        int M = Integer.parseInt(br.readLine());
        if (M > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 0; i < M; i++) {
                broken[Integer.parseInt(st.nextToken())] = true;
            }
        }
        if (M < 10)
            dfs("");
        System.out.println(answer);
    }

    static void dfs(String num) {
        for (int i = 0; i < 10; i++) {
            if (!broken[i]) {
                String next = num + i;
                int len = next.length();
                answer = Math.min(answer, Math.abs(N - Integer.parseInt(next)) + len);

                if (len < 6) {
                    dfs(next);
                }
            }
        }
    }
}