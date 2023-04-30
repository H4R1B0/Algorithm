import java.io.*;
import java.util.*;

public class Main {
    static int N, M;
    static List<Integer>[] routes;
    static int[] parent;
    static int[] depth;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        //해당 노드의 부모 노드 저장
        parent = new int[N + 1];
        depth = new int[N + 1];
        //루트 저장
        routes = new ArrayList[N + 1];
        for (int i = 0; i <= N; i++) {
            routes[i] = new ArrayList<>();
        }
        for (int i = 0; i < N - 1; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            routes[a].add(b);
            routes[b].add(a);
        }
        setDepth();

        StringBuilder answer = new StringBuilder();
        M = Integer.parseInt(br.readLine());
        for (int i = 0; i < M; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            answer.append(lca(a, b)).append('\n');
        }
        System.out.println(answer);
    }

    //각 노드별로 depth저장
    static void setDepth() {
        boolean[] visit = new boolean[N + 1];
        visit[1] = true;
        Queue<Integer> q = new LinkedList<Integer>();
        q.add(1);
        while (!q.isEmpty()) {
            int cur = q.poll();
            for (int i = 0; i < routes[cur].size(); i++) {
                int next = routes[cur].get(i);
                if (!visit[next]) {
                    visit[next] = true;
                    depth[next] = depth[cur] + 1;
                    parent[next] = cur;
                    q.add(next);
                }
            }
        }
    }

    static int lca(int a, int b) {
        //depth를 기준으로 작은것은 a, 큰것은 b에 저장
        if (depth[a] > depth[b]) {
            int tmp = b;
            b = a;
            a = tmp;
        }

        //b의 depth가 a의 depth와 같을 때까지 부모 노드로 이동
        while (depth[a] != depth[b]) {
            b = parent[b];
        }

        //depth가 같아졌다면 a와 b의 부모 노드가 같아질 때까지 부모로 이동
        while (a != b) {
            a = parent[a];
            b = parent[b];
        }
        return a;
    }
}