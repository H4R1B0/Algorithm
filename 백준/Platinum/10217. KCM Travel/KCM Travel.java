import java.util.*;
import java.io.*;

public class Main {
    private static final int INF = 100001;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        br.readLine();
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        List<Point>[] bridges = new ArrayList[N + 1];
        for (int i = 1; i <= N; i++) {
            bridges[i] = new ArrayList<Point>();
        }
        for (int i = 0; i < K; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            int d = Integer.parseInt(st.nextToken());
            bridges[u].add(new Point(v, c, d));
        }
        //dist[비용][정점]=시간

        int[][] dist = new int[M + 1][N + 1];
        for (int i = 0; i <= M; i++) {
            Arrays.fill(dist[i], INF);
        }
        dist[0][1] = 0;
        for (int i = 0; i <= M; i++) {
            for (int j = 1; j <= N; j++) {
                for (Point bridge : bridges[j]) {
                    if (i + bridge.cost <= M) {
                        dist[i + bridge.cost][bridge.idx] = Math.min(dist[i + bridge.cost][bridge.idx], dist[i][j] + bridge.time);
                    }
                }
            }
        }
        int answer = INF;
        for (int i = 0; i <= M; i++) {
            answer = Math.min(answer, dist[i][N]);
        }
        System.out.println(answer == INF ? "Poor KCM" : answer);
    }

    static class Point {
        int idx;
        int cost;
        int time;

        public Point(int idx, int cost, int time) {
            this.idx = idx;
            this.cost = cost;
            this.time = time;
        }
    }
}