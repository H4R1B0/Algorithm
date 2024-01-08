import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.stream.Collectors;

public class Main {
    static int N;
    static int[] arr;
    static int[][] dp;
    static List<Integer>[] bridges;
    static boolean[] visit;
    static List<Integer> answer = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        arr = new int[N + 1];
        visit = new boolean[N + 1];
        dp = new int[N + 1][2];
        bridges = new ArrayList[N + 1];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            bridges[i] = new ArrayList<>();
            arr[i] = Integer.parseInt(st.nextToken());
        }
        for (int i = 0; i < N - 1; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            bridges[a].add(b);
            bridges[b].add(a);
        }
        dfs(1);
        System.out.println(Math.max(dp[1][0], dp[1][1]));

        Arrays.fill(visit, false);
        route(1, 0);
        answer.sort((o1, o2) -> o1 - o2);
        System.out.println(answer.stream()
                .map(Object::toString)
                .collect(Collectors.joining(" ")));
    }

    static void dfs(int cur) {
        dp[cur][0] = 0;
        dp[cur][1] = arr[cur];

        visit[cur] = true;

        for (int i = 0; i < bridges[cur].size(); i++) {
            int next = bridges[cur].get(i);
            if (!visit[next]) {
                dfs(next);
                dp[cur][0] += Math.max(dp[next][0], dp[next][1]);
                dp[cur][1] += dp[next][0];
            }
        }
    }

    static void route(int cur, int prev) {
        if (dp[cur][1] > dp[cur][0] && !visit[prev]) {
            answer.add(cur);
            visit[cur] = true;
        }

        for (int i = 0; i < bridges[cur].size(); i++) {
            int next = bridges[cur].get(i);
            if (next != prev) {
                route(next, cur);
            }
        }
    }
}