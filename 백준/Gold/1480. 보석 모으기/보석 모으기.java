import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static int N, M, C;
    static int[] arr;
    static int[][][] dp = new int[11][21][1 << 13]; //가방 번호, 무게, 보석 목록

    public static void main(String[] args) throws IOException {
        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());

        arr = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        Arrays.stream(dp).forEach(
            i -> Arrays.stream(i).forEach(
                j -> Arrays.fill(j, -1)
            )
        );
        int answer = dfs(0, 0, 0);
        System.out.println(answer);
    }

    static int dfs(int idx, int weight, int visit) {
        if (idx == M) {
            return -1;
        }

        if (visit == (1 << N) - 1) {
            return 0;
        }

        if (dp[idx][weight][visit] != -1) {
            return dp[idx][weight][visit];
        }

        int result = 0;
        for (int i = 0; i < N; i++) {
            if ((visit & (1 << i)) > 0) {
                continue;
            }

            if (arr[i] > C) {
                continue;
            }

            if (weight + arr[i] > C) {
                result = Math.max(result, dfs(idx + 1, arr[i], visit | (1 << i)) + 1);
            } else {
                result = Math.max(result, dfs(idx, weight + arr[i], visit | (1 << i)) + 1);
            }
        }
        return dp[idx][weight][visit] = result;
    }
}