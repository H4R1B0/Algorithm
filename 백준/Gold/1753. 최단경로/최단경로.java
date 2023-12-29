import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    private static int V, E;
    private static int[] dist;
    private static List<int[]>[] bridges;

    public static void main(String[] args) throws IOException {
        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        V = Integer.parseInt(st.nextToken());
        E = Integer.parseInt(st.nextToken());
        int start = Integer.parseInt(br.readLine());

        //정점간에 연결할 리스트
        bridges = new ArrayList[V + 1];
        for (int i = 1; i <= V; i++) {
            bridges[i] = new ArrayList<int[]>();
        }
        //정점 거리 저장
        dist = new int[V + 1];
        Arrays.fill(dist, Integer.MAX_VALUE);
        //start에서 시작하므로 0
        dist[start] = 0;

        //양방향
        for (int i = 1; i <= E; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            bridges[a].add(new int[]{b, c});
        }

        //다익스트라
        //idx, cost
        PriorityQueue<int[]> pq = new PriorityQueue<int[]>((o1, o2) -> {
            return o1[1] - o2[1];
        });
        pq.add(new int[]{start, 0});

        while (!pq.isEmpty()) {
            int[] cur = pq.poll();
            int curIdx = cur[0];
            int curCost = cur[1];

            if (dist[curIdx] > curCost)
                continue;

            for (int i = 0; i < bridges[curIdx].size(); i++) {
                int nextIdx = bridges[curIdx].get(i)[0];
                int nextCost = curCost + bridges[curIdx].get(i)[1];

                if (dist[nextIdx] > nextCost) {
                    dist[nextIdx] = nextCost;
                    pq.add(new int[]{nextIdx, nextCost});
                }
            }
        }

        //정답
        StringBuilder sb = new StringBuilder();
        for (int i = 1; i <= V; i++) {
            if (dist[i] != Integer.MAX_VALUE) {
                sb.append(dist[i]);
            } else {
                sb.append("INF");
            }
            sb.append('\n');
        }
        System.out.println(sb);
    }
}