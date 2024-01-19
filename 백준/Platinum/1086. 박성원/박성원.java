import java.io.*;

public class Main {
    static int N, K;
    static String[] nums = new String[16];
    static long[] modNums = new long[16];
    static long[][] dp = new long[1 << 15][101];
    static long[] ten = new long[51];

    public static void main(String[] args) throws IOException {
        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        long total = 1;
        for (int i = 0; i < N; i++) {
            nums[i] = br.readLine();
            total *= (i + 1);
        }

        K = Integer.parseInt(br.readLine());
        for (int i = 0; i < N; i++) {
            modNums[i] = getMod(nums[i]);
        }

        ten[0] = 1 % K;
        for (int i = 1; i < 51; i++) {
            ten[i] = (ten[i - 1] * 10) % K;
        }

        dp[0][0] = 1;
        for (int visit = 0; visit < (1 << N); visit++) {
            for (int i = 0; i < N; i++) {
                if ((visit & (1 << i)) == 0) {
                    int nextVisit = (visit | (1 << i));
                    for (int j = 0; j < K; j++) {
                        long nextMod = ((j * ten[nums[i].length()]) % K + modNums[i]) % K;
                        dp[nextVisit][(int) nextMod] += dp[visit][j];
                    }
                }
            }
        }
        if (dp[(1 << N) - 1][0] == 0 || dp[(1 << N) - 1][0] == total) {
            System.out.println(dp[(1 << N) - 1][0] / total + "/1");
        } else {
            long gcd = getGcd(dp[(1 << N) - 1][0], total);
            System.out.println(dp[(1 << N) - 1][0] / gcd + "/" + total / gcd);
        }
    }

    static long getGcd(long a, long b) {
        if (a % b == 0) {
            return b;
        }
        return getGcd(b, a % b);
    }

    static int getMod(String str) {
        int result = 0;
        for (int i = 0; i < str.length(); i++) {
            result *= 10;
            result += str.charAt(i) - '0';
            result %= K;
        }
        return result;
    }
}