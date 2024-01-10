import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int A, B, C;
    static char[] X, Y;
    static int[][] dp;

    public static void main(String[] args) throws IOException {
        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        A = Integer.parseInt(st.nextToken());
        B = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        X = br.readLine().toCharArray();
        Y = br.readLine().toCharArray();

        dp = new int[X.length + 1][Y.length + 1];
        for (int i = 0; i <= X.length; i++) {
            Arrays.fill(dp[i], Integer.MAX_VALUE);
        }
        System.out.println(dfs(0, 0));
    }

    static int dfs(int x, int y) {
        if (dp[x][y] != Integer.MAX_VALUE) {
            return dp[x][y];
        }

        if (x == X.length && y == Y.length) {
            return 0;
        }

        int answer = Integer.MIN_VALUE;
        if (x < X.length && y < Y.length) {
            if (X[x] == Y[y]) {
                answer = Math.max(answer, dfs(x + 1, y + 1) + A);
            } else {
                answer = Math.max(answer, dfs(x + 1, y + 1) + C);
            }
        }

        if (x < X.length) {
            answer = Math.max(answer, dfs(x + 1, y) + B);
        }
        if (y < Y.length) {
            answer = Math.max(answer, dfs(x, y + 1) + B);
        }
        return dp[x][y] = answer;
    }
}