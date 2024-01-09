import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int N;
    static int[] xd = {0, -1, 1, 0, 0};
    static int[] yd = {0, 0, 0, -1, 1};
    static List<int[]> people = new ArrayList<>();
    static long[][] dist;

    public static void main(String[] args) throws IOException {
        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        dist = new long[N + 1][5];
        for (int i = 0; i <= N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            people.add(new int[]{a, b});
        }
        for (int i = 0; i <= N; i++) {
            Arrays.fill(dist[i], Long.MAX_VALUE);
        }

        //x, y, idx, cost
        PriorityQueue<Point> pq = new PriorityQueue<>((o1, o2) -> {
            return Long.compare(o1.cost, o2.cost);
        });
        pq.offer(new Point(people.get(0)[0], people.get(0)[1], 0, 0));
        long answer = Long.MAX_VALUE;
        while (!pq.isEmpty()) {
            Point cur = pq.poll();
            int curX = cur.x;
            int curY = cur.y;
            int curIdx = cur.idx;
            long curCost = cur.cost;

            if (curIdx == N) {
                answer = Math.min(answer, curCost);
                continue;
            }

            int nextIdx = curIdx + 1;
            for (int i = 0; i < 5; i++) {
                int nextX = people.get(nextIdx)[0] + xd[i];
                int nextY = people.get(nextIdx)[1] + yd[i];
                long nextCost = curCost + getDistance(curX, curY, nextX, nextY);

                if (dist[nextIdx][i] > nextCost) {
                    dist[nextIdx][i] = nextCost;
                    pq.offer(new Point(nextX, nextY, nextIdx, nextCost));
                }
            }
        }
        System.out.println(answer);
    }

    static long getDistance(int x, int y, int xx, int yy) {
        return Math.abs(xx - x) + Math.abs(yy - y);
    }

    static class Point {
        int x, y, idx;
        long cost;

        public Point(int x, int y, int idx, long cost) {
            this.x = x;
            this.y = y;
            this.idx = idx;
            this.cost = cost;
        }
    }
}