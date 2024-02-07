import java.io.*;
import java.util.*;

public class Main {
    static long[] dp = new long[55];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        long A = Long.parseLong(st.nextToken());
        long B = Long.parseLong(st.nextToken());
        dp[0] = 1;
        for (int i = 1; i < 55; i++) {
            dp[i] = (dp[i - 1] << 1) + (1L << i);
        }
        System.out.println(getOne(B) - getOne(A - 1));
    }

    static long getOne(long x) {
        long cnt = x & 1;
        for (int i = 54; i > 0; i--) {
            if ((x & (1L << i)) > 0) {
                cnt += dp[i - 1] + (x - (1L << i) + 1);
                x -= (1L << i);
            }
        }
        return cnt;
    }
}