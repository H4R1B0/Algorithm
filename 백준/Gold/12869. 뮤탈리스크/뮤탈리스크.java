import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    private static final int[][] attacks = {
            {1, 3, 9}, {1, 9, 3}, {3, 1, 9}, {3, 9, 1}, {9, 1, 3}, {9, 3, 1}
    };

    public static void main(String[] args) throws IOException {
        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[] scv = new int[3];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            scv[i] = Integer.parseInt(st.nextToken());
        }
        int[][][] dp = new int[scv[0] + 1][scv[1] + 1][scv[2] + 1];

        Queue<int[]> q = new LinkedList<int[]>();
        q.add(new int[]{scv[0], scv[1], scv[2]});
        while (!q.isEmpty()) {
            int[] cur = q.poll();

            if (scv[0] == 0 && scv[1] == 0 && scv[2] == 0) {
                break;
            }

            for (int[] attack : attacks) {
                int a = Math.max(cur[0] - attack[0], 0);
                int b = Math.max(cur[1] - attack[1], 0);
                int c = Math.max(cur[2] - attack[2], 0);

                if (dp[a][b][c] == 0) {
                    dp[a][b][c] = dp[cur[0]][cur[1]][cur[2]] + 1;
                    q.offer(new int[]{a, b, c});
                }
            }
        }

        System.out.println(dp[0][0][0]);
    }
}