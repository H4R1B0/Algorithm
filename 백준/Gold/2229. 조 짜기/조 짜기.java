import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] students = new int[N + 1];
        int[] dp = new int[N + 1];
        for (int i = 0; i < N; i++) {
            students[i + 1] = Integer.parseInt(st.nextToken());
        }
        for (int i = 2; i < students.length; i++) {
            int max = Integer.MIN_VALUE;
            int min = Integer.MAX_VALUE;

            for (int j = i; j >= 1; j--) {
                max = Math.max(max, students[j]);
                min = Math.min(min, students[j]);
                dp[i] = Math.max(dp[i], max - min + dp[j - 1]);
            }
        }
        System.out.println(dp[N]);
    }
}