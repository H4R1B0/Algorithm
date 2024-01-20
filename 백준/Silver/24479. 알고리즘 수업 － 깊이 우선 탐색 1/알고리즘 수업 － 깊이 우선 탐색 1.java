import java.io.*;
import java.util.*;

public class Main {
    static int N, M, R;
    static List<Integer>[] bridges;
    static int[] visit;
    static int cnt = 1;

    public static void main(String[] args) throws IOException {
        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        R = Integer.parseInt(st.nextToken());
        bridges = new ArrayList[N + 1];
        visit = new int[N + 1];
        Arrays.fill(visit, -1);
        for (int i = 0; i <= N; i++) {
            bridges[i] = new ArrayList<>();
        }

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            bridges[u].add(v);
            bridges[v].add(u);
        }
        for (int i = 0; i <= N; i++) {
            bridges[i].sort(Comparator.comparingInt(o -> o));
        }
        dfs(R, -1);
        for (int i = 1; i <= N; i++) {
            if (visit[i] != -1) {
                System.out.println(visit[i]);
            } else {
                System.out.println(0);
            }
        }
    }

    static void dfs(int cur, int prev) {
        if (visit[cur] != -1) {
            return;
        }
        if (visit[cur] == -1) {
            visit[cur] = cnt++;
        }
        for (int i = 0; i < bridges[cur].size(); i++) {
            int next = bridges[cur].get(i);
            dfs(next, cur);
        }
    }
}