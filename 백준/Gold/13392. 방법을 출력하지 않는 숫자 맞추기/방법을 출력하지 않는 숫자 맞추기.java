import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int N;
    static char[] X, Y;
    static int[][] dp;

    public static void main(String[] args) throws IOException {
        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        X = br.readLine().toCharArray();
        Y = br.readLine().toCharArray();

        dp = new int[N][10];
        for (int i = 0; i < N; i++) {
            Arrays.fill(dp[i], -1);
        }
        System.out.println(dfs(0, 0));
    }

    static int dfs(int cnt, int turn) {
        if (cnt == N) {
            return 0;
        }

        if (dp[cnt][turn] != -1) {
            return dp[cnt][turn];
        }

        int turnLeft = (Y[cnt] - X[cnt] - turn + 20) % 10;
        int turnRight = 10 - turnLeft;
        int answer = Math.min(dfs(cnt + 1, (turn + turnLeft) % 10) + turnLeft, dfs(cnt + 1, turn) + turnRight);
        return dp[cnt][turn] = answer;
    }
}