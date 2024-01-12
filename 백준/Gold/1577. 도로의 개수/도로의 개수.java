import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int N, M;

    public static void main(String[] args) throws IOException {
        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(br.readLine());
        //0 가로, 1 세로
        boolean[][][] road = new boolean[M + 1][N + 1][2];
        for (int i = 0; i < K; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            int d = Integer.parseInt(st.nextToken());
            if (a > c) {
                int tmp = c;
                c = a;
                a = tmp;
            }
            if (b > d) {
                int tmp = d;
                d = b;
                b = tmp;
            }
            if (a < c) {
                road[b][a][0] = true;
            } else if (b < d) {
                road[b][a][1] = true;
            }
        }

        long[][] dp = new long[M + 1][N + 1];
        //세로, 가로 초기화
        for (int i = 1; i <= M; i++) {
            if (road[i - 1][0][1])
                break;
            dp[i][0] = 1;
        }
        for (int i = 1; i <= N; i++) {
            if (road[0][i - 1][0]) {
                break;
            }
            dp[0][i] = 1;
        }
        for (int i = 1; i <= M; i++) {
            for (int j = 1; j <= N; j++) {
                if (!road[i][j - 1][0]) {
                    dp[i][j] += dp[i][j - 1];
                }
                if (!road[i - 1][j][1]) {
                    dp[i][j] += dp[i - 1][j];
                }
            }
        }
        System.out.println(dp[M][N]);
    }
}