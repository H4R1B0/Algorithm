import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int L = Integer.parseInt(st.nextToken());
        long I = Long.parseLong(st.nextToken());

        //영역별로 몇개 인지 계산
        long[][] dp = new long[N + 1][N + 1];
        dp[0][0] = 1;
        for (int i = 1; i <= N; i++) {
            dp[i][0] = 1;
            for (int j = 1; j <= i; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
            }
        }
        StringBuilder answer = new StringBuilder();
        for (int i = N; i > 0; i--) {
            long sum = 0;
            for (int j = 0; j <= L; j++) {
                sum += dp[i - 1][j];
            }
            if (sum < I) {
                answer.append(1);
                I -= sum;
                L--;
            } else {
                answer.append(0);
            }
        }
        System.out.println(answer);
    }
}