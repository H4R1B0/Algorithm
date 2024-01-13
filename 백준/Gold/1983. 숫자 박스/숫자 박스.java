import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int N;
    static int[][] arr;
    static int[] len;
    static int[][][] dp;

    public static void main(String[] args) throws IOException {
        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        arr = new int[2][N];
        len = new int[2];
        dp = new int[N][N][N];
        StringTokenizer st = null;
        for (int i = 0; i < 2; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                int num = Integer.parseInt(st.nextToken());
                if (num != 0) {
                    arr[i][len[i]++] = num;
                }
            }
        }

        Arrays.stream(dp).forEach(
            i -> Arrays.stream(i).forEach(
                j -> Arrays.fill(j, Integer.MIN_VALUE)
            )
        );

        System.out.println(dfs(0,0,0));
    }

    static int dfs(int i, int j, int k) {
        if (i == len[0] || j == len[1]) {
            return 0;
        }

        if (dp[i][j][k] != Integer.MIN_VALUE) {
            return dp[i][j][k];
        }

        int answer = Integer.MIN_VALUE;
        if (len[0] - i + k < N) {
            answer = Math.max(answer, dfs(i, j + 1, k + 1));
        }
        if (len[1] - j + k < N) {
            answer = Math.max(answer, dfs(i + 1, j, k + 1));
        }
        answer = Math.max(answer, dfs(i + 1, j + 1, k + 1) + arr[0][i] * arr[1][j]);
        return dp[i][j][k] = answer;
    }
}