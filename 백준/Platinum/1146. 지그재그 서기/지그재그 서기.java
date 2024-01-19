import java.io.*;
import java.util.*;

public class Main {
    static final int MOD = 1_000_000;
    static int N;
    static int[][] dp = new int[101][101];

    public static void main(String[] args) throws IOException {
        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        if (N == 1) {
            System.out.println(1);
            return;
        }

        Arrays.stream(dp).forEach(
            i -> Arrays.fill(i, -1)
        );
        int answer = 0;
        for (int i = 0; i < N; i++) {
            answer += dfs(i, N - i - 1) % MOD;
        }
        answer *= 2;
        System.out.println(answer % MOD);
    }

    static int dfs(int left, int right) {
        if (left + right == 0) {
            return 1;
        }

        if (dp[left][right] != -1) {
            return dp[left][right];
        }

        if (right == 0) {
            return 0;
        }
        int answer = 0;
        for (int i = 0; i < right; i++) {
            answer += dfs(right - i - 1, left + i) % MOD;
        }
        return dp[left][right] = answer % MOD;
    }
}