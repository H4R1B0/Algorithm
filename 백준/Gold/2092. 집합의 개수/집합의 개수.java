import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static final int MOD = 1000000;
    static int[] cnt;
    static int[][] dp;

    public static void main(String[] args) throws IOException {
        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int T = Integer.parseInt(st.nextToken());
        int A = Integer.parseInt(st.nextToken());
        int S = Integer.parseInt(st.nextToken());
        int B = Integer.parseInt(st.nextToken());

        cnt = new int[T + 1];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < A; i++) {
            int num = Integer.parseInt(st.nextToken());
            cnt[num]++;
        }

        dp = new int[T + 1][A + 1];
        dp[0][0] = 1;

        for (int i = 1; i <= T; i++) {
            //i 숫자 하나로만 구성
            for (int j = 0; j <= cnt[i]; j++) {
                dp[i][j]++;
            }

            for (int j = 0; j <= A; j++) {
                dp[i][j] += dp[i - 1][j];
                for (int k = 1; k <= cnt[i]; k++) {
                    if (j - k > 0) {
                        dp[i][j] += dp[i - 1][j - k];
                        dp[i][j] %= MOD;
                    }
                }
            }
        }
        int answer = 0;
        for(int i=S;i<=B;i++){
            answer += dp[T][i];
            answer %= MOD;
        }
        System.out.println(answer);
    }
}