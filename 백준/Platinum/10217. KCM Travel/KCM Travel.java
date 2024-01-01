import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    private static int N, M;
    private static List<Point>[] bridges;

    public static void main(String[] args) throws IOException {
        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        br.readLine();
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        bridges = new ArrayList[N + 1];
        for (int i = 1; i <= N; i++) {
            bridges[i] = new ArrayList<>();
        }

        for (int i = 0; i < K; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            int d = Integer.parseInt(st.nextToken());

            bridges[u].add(new Point(v, c, d));
        }

        for (int i = 1; i <= N; i++) {
            bridges[i].sort((o1, o2) -> {
                return o1.time - o2.time;
            });
        }

        int answer = dijkstra();

        System.out.println(answer == Integer.MAX_VALUE ? "Poor KCM" : answer);
    }

    private static int dijkstra() {
        int answer = Integer.MAX_VALUE;

        int[][] dist = new int[N + 1][M + 1];
        for (int i = 1; i <= N; i++) {
            Arrays.fill(dist[i], Integer.MAX_VALUE);
        }
        dist[1][0] = 0;

        Queue<Point> q = new LinkedList<>();
        q.offer(new Point(1, 0, 0));
        while (!q.isEmpty()) {
            Point cur = q.poll();
            int curIdx = cur.idx;
            int curCost = cur.cost;
            int curTime = cur.time;

            if (curIdx == N) {
                answer = Math.min(answer, dist[curIdx][curCost]);
                continue;
            }

            if (answer < dist[curIdx][curCost]) {
                continue;
            }

            if (dist[curIdx][curCost] < curTime) {
                continue;
            }

            for (int i = 0; i < bridges[curIdx].size(); i++) {
                Point next = bridges[curIdx].get(i);
                int nextIdx = next.idx;
                int nextCost = next.cost + curCost;
                int nextTime = next.time + curTime;

                if (nextCost > M) {
                    continue;
                }

                if (dist[nextIdx][nextCost] <= nextTime) {
                    continue;
                }

                for (int j = nextCost; j <= M; j++) {
                    if (dist[nextIdx][j] > nextTime) {
                        dist[nextIdx][j] = nextTime;
                    } else {
                        break;
                    }
                }
                q.offer(new Point(nextIdx, nextCost, nextTime));
            }
        }

        for (int i = 0; i <= M; i++) {
            answer = Math.min(answer, dist[N][i]);
        }

        return answer;
    }

    static class Point {
        int idx, cost, time;

        public Point(int idx, int cost, int time) {
            this.idx = idx;
            this.cost = cost;
            this.time = time;
        }
    }
}