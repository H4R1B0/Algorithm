import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int N;
    static int[] X, Y;
    static int[][][][] dp;

    public static void main(String[] args) throws IOException {
        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        char[] tmp = br.readLine().toCharArray();
        X = new int[N + 5];
        for (int i = 0; i < N; i++) {
            X[i] = tmp[i] - '0';
        }
        tmp = br.readLine().toCharArray();
        Y = new int[N + 5];
        for (int i = 0; i < N; i++) {
            Y[i] = tmp[i] - '0';
        }

        dp = new int[N + 5][10][10][10];
        Arrays.stream(dp).forEach(
            i -> Arrays.stream(i).forEach(
                j -> Arrays.stream(j).forEach(
                    k -> Arrays.fill(k, -1)
                )
            )
        );
        System.out.println(dfs(0, X[0], X[1], X[2]));
    }

    static int dfs(int cnt, int a, int b, int c) {
        if (cnt == N) {
            return 0;
        }
        if (dp[cnt][a][b][c] != -1) {
            return dp[cnt][a][b][c];
        }
        int answer = Integer.MAX_VALUE;
        //-1 시계, 1 반시계
        for (int i = -1; i <= 1; i += 2) {
            int move = rotate(rotate(Y[cnt] - a) * i);
            for (int j = 0; j <= move; j++) {
                for (int k = 0; k <= j; k++) {
                    int nextB = rotate(b + j * i);
                    int nextC = rotate(c + k * i);
                    answer = Math.min(answer, dfs(cnt + 1, nextB, nextC, X[cnt + 3]) + (move - j + 2) / 3 + (j - k + 2) / 3 + (k + 2) / 3);
                }
            }
        }
        return dp[cnt][a][b][c] = answer;
    }

    static int rotate(int x) {
        return (x + 10) % 10;
    }
}