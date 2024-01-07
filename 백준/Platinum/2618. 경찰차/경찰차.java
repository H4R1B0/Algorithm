import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int N, W;
    static List<int[]> acc;
    static int[][] dp;
    static StringBuilder answer = new StringBuilder();

    public static void main(String[] args) throws IOException {
        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        W = Integer.parseInt(br.readLine());
        dp = new int[W + 1][W + 1];
        for (int i = 0; i <= W; i++) {
            for (int j = 0; j <= W; j++) {
                Arrays.fill(dp[i], -1);
            }
        }
        acc = new ArrayList<>();
        acc.add(new int[]{0, 0});
        for (int i = 0; i < W; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            acc.add(new int[]{a, b});
        }
        System.out.println(dfs(0, 0));
        route(0, 0);
        System.out.println(answer);
    }

    static int dfs(int police1, int police2) {
        if (police1 == W || police2 == W)
            return 0;
        if (dp[police1][police2] != -1)
            return dp[police1][police2];

        int next = Math.max(police1, police2) + 1;
        int dist1 = 0, dist2 = 0;

        if (police1 == 0) {
            dist1 = getDist(1, 1, acc.get(next)[0], acc.get(next)[1]);
        } else {
            dist1 = getDist(acc.get(police1)[0], acc.get(police1)[1], acc.get(next)[0], acc.get(next)[1]);
        }

        if (police2 == 0) {
            dist2 = getDist(N, N, acc.get(next)[0], acc.get(next)[1]);
        } else {
            dist2 = getDist(acc.get(police2)[0], acc.get(police2)[1], acc.get(next)[0], acc.get(next)[1]);
        }

        int answer1 = dist1 + dfs(next, police2);
        int answer2 = dist2 + dfs(police1, next);
        dp[police1][police2] = Math.min(answer1, answer2);
        return dp[police1][police2];
    }

    static int getDist(int x, int y, int xx, int yy) {
        return Math.abs(xx - x) + Math.abs(yy - y);
    }

    static void route(int police1, int police2) {
        if (police1 == W || police2 == W)
            return;

        int next = Math.max(police1, police2) + 1;
        int dist1 = 0, dist2 = 0;

        if (police1 == 0) {
            dist1 = getDist(1, 1, acc.get(next)[0], acc.get(next)[1]);
        } else {
            dist1 = getDist(acc.get(police1)[0], acc.get(police1)[1], acc.get(next)[0], acc.get(next)[1]);
        }

        if (police2 == 0) {
            dist2 = getDist(N, N, acc.get(next)[0], acc.get(next)[1]);
        } else {
            dist2 = getDist(acc.get(police2)[0], acc.get(police2)[1], acc.get(next)[0], acc.get(next)[1]);
        }

        if (dist1 + dp[next][police2] < dist2 + dp[police1][next]) {
            answer.append(1).append('\n');
            route(next, police2);
        } else {
            answer.append(2).append('\n');
            route(police1, next);
        }
    }
}