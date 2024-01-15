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
        int M = Integer.parseInt(st.nextToken());
        Set<Integer> set = new HashSet<>();
        for (int i = 0; i < M; i++) {
            int a = Integer.parseInt(br.readLine());
            set.add(a);
        }
        int[][] dp = new int[10001][500];
        Arrays.stream(dp).forEach(
            i -> Arrays.fill(i, 10001)
        );
        dp[1][0] = 0;
        for (int i = 2; i <= N; i++) {
            if (set.contains(i)) {
                continue;
            }
            for (int j = 1; j <= (int) Math.sqrt(2 * i); j++) {
                dp[i][j] = Math.min(dp[i - j][j - 1], dp[i - j][j]);
                dp[i][j] = Math.min(dp[i][j], dp[i - j][j + 1]);
                dp[i][j]++;
            }
        }
        int answer = Arrays.stream(dp[N]).min().getAsInt();
        System.out.println(answer == 10001 ? -1 : answer);
    }
}