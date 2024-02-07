import java.io.*;
import java.util.*;

public class Main {
    static int[][] dp = new int[101][100001];
    static int[][] arr;
    static int N;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = 3;
        StringTokenizer st = null;
        while (T-- > 0) {
            Arrays.stream(dp).forEach(
                i -> Arrays.fill(i, -1)
            );
            N = Integer.parseInt(br.readLine());
            arr = new int[N][2];
            int total = 0;
            for (int i = 0; i < N; i++) {
                st = new StringTokenizer(br.readLine());
                arr[i][0] = Integer.parseInt(st.nextToken());
                arr[i][1] = Integer.parseInt(st.nextToken());
                total += arr[i][0] * arr[i][1];
            }
            if (total % 2 != 0) {
                System.out.println(0);
            } else {
                System.out.println(dfs(0, total / 2));
            }
        }
    }

    static int dfs(int idx, int price) {
        if (price < 0) {
            return 0;
        }
        if (idx == N) {
            return price == 0 ? 1 : 0;
        }
        if (dp[idx][price] != -1) {
            return dp[idx][price];
        }
        int result = 0;
        for (int i = 0; i <= arr[idx][1]; i++) {
            result = Math.max(result, dfs(idx + 1, price - arr[idx][0] * i));
        }
        return dp[idx][price] = result;
    }
}