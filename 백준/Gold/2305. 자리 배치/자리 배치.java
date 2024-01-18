import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    static int N, K;
    static int[] fibo = new int[45];
    static int[] fiboSum = new int[45];
    static int[] dp = new int[45];

    public static void main(String[] args) throws IOException {
        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        K = Integer.parseInt(br.readLine());

        fibo[0] = 1;
        fibo[1] = 1;
        fiboSum[0] = 1;
        fiboSum[1] = 2;
        for (int i = 2; i < 41; i++) {
            fibo[i] = fibo[i - 1] + fibo[i - 2];
            fiboSum[i] = fiboSum[i - 1] + fibo[i];
        }
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= N; i++) {
            dp[i] = dp[i - 1] + dp[i - 2] + fiboSum[i - 2] + fiboSum[i - 3];
        }
        int answer = dp[N - K + 1] * fibo[K - 1] + dp[K] * fibo[N - K] - fibo[K - 1] * fibo[N - K];
        System.out.println(answer);
    }
}