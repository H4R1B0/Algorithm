import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[] vip = new int[50];
        int[] dp = new int[50];
        int M = Integer.parseInt(br.readLine());
        for (int i = 0; i < M; i++) {
            vip[i] = Integer.parseInt(br.readLine());
        }

        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= N; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        int answer = 1;
        int start = 0;
        for (int i = 0; i < M; i++) {
            int end = vip[i];
            answer *= dp[end - start - 1];
            start = end;
        }
        answer *= dp[N - start];
        System.out.println(answer);
    }
}