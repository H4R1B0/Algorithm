import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] nums = {0, 0, 1, 7, 4, 2, 0, 8, 10};
        long[] dp = new long[101];
        for (int i = 1; i < 9; i++) {
            dp[i] = nums[i];
        }
        dp[6] = 6;
        for (int i = 9; i <= 100; i++) {
            dp[i] = dp[i - 2] * 10 + nums[2];
            for (int j = 3; j < 8; j++) {
                dp[i] = Math.min(dp[i], dp[i - j] * 10 + nums[j]);
            }
        }
        StringBuilder answer = new StringBuilder();
        int T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            int n = Integer.parseInt(br.readLine());
            answer.append(dp[n]).append(' ');
            if (n % 2 == 0) {
                for (int i = 0; i < n / 2; i++) {
                    answer.append(1);
                }
            } else {
                answer.append(7);
                for (int i = 0; i < n / 2 - 1; i++) {
                    answer.append(1);
                }
            }
            answer.append('\n');
        }
        System.out.println(answer);
    }
}