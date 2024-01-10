import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int N, M, C;
    static int[][] map;
    static int[][][][] dp;
    static final int MOD = 1000007;

    public static void main(String[] args) throws IOException {
        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        map = new int[N + 1][M + 1];
        dp = new int[N + 1][M + 1][C + 1][C + 1];
        for (int i = 1; i <= C; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            map[a][b] = i;
        }

        if (map[1][1] != 0) {
            dp[1][1][1][map[1][1]] = 1;
        } else {
            dp[1][1][0][0] = 1;
        }

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                if (i == 1 && j == 1) {
                    continue;
                }

                int idx = map[i][j];
                if (idx != 0) {
                    //오락실 번호 방문
                    for (int l = 0; l < idx; l++) {
                        //총 방문 횟수
                        for (int k = 0; k <= l; k++) {
                            dp[i][j][k + 1][idx] += dp[i - 1][j][k][l] + dp[i][j - 1][k][l];
                            dp[i][j][k + 1][idx] %= MOD;
                        }
                    }
                } else {
                    for (int l = 0; l <= C; l++) {
                        for (int k = 0; k <= l; k++) {
                            dp[i][j][k][l] += dp[i - 1][j][k][l] + dp[i][j - 1][k][l];
                            dp[i][j][k][l] %= MOD;
                        }
                    }
                }
            }
        }

        for (int i = 0; i <= C; i++) {
            int sum = 0;
            for (int j = 0; j <= C; j++) {
                sum += dp[N][M][i][j];
            }
            System.out.print(sum % MOD + " ");
        }
    }
}