import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    private static int N, M;
    private static int dist[];
    private static int parent[];
    private static List<int[]>[] bridges;

    public static void main(String[] args) throws IOException {
        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        //컴퓨터간에 연결할 리스트
        bridges = new ArrayList[N + 1];
        for (int i = 1; i <= N; i++) {
            bridges[i] = new ArrayList<int[]>();
        }
        //거리 계산 배열
        dist = new int[N + 1];
        parent = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            parent[i] = i;
        }

        //양방향
        for (int i = 1; i <= M; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            bridges[a].add(new int[]{b, c});
            bridges[b].add(new int[]{a, c});
        }

        dijkstra();

        System.out.println(N - 1);
        for (int i = 2; i <= N; i++) {
            System.out.println(i + " " + parent[i]);
        }
    }

    private static void dijkstra() {
        //dist 거리 초가화
        for (int i = 2; i <= N; i++) {
            dist[i] = Integer.MAX_VALUE;
        }

        //우선순위 큐
        //거리, 현재 위치
        PriorityQueue<int[]> pq = new PriorityQueue<int[]>((o1, o2) -> {
            return o1[0] - o2[0];
        });
        pq.add(new int[]{0, 1});
        while (!pq.isEmpty()) {
            int[] cur = pq.poll();
            int curCost = cur[0];
            int curIdx = cur[1];

            if (dist[curIdx] > curCost)
                continue;

            for (int i = 0; i < bridges[curIdx].size(); i++) {
                int next = bridges[curIdx].get(i)[0];
                int nextCost = curCost + bridges[curIdx].get(i)[1];

                if (dist[next] > nextCost) {
                    dist[next] = nextCost;
                    parent[next] = curIdx;
                    pq.add(new int[]{nextCost, next});
                }
            }
        }
    }
}