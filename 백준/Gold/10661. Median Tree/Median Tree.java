import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static int V, E;
    static Bridge[] bridges;
    static int[] parent;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            V = Integer.parseInt(st.nextToken());
            E = Integer.parseInt(st.nextToken());
            if (V == 0 && E == 0)
                break;
            bridges = new Bridge[E];
            bridges[0] = new Bridge(0, 0, 0);
            for (int i = 0; i < E; i++) {
                st = new StringTokenizer(br.readLine());
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());
                int c = Integer.parseInt(st.nextToken());
                bridges[i] = new Bridge(a, b, c);
            }

            Arrays.sort(bridges, (o1, o2) -> {
                return o1.dist - o2.dist;
            });

            makeSet();
            int cnt =0;
            List<Integer> answer = new ArrayList<>();
            for (int i = 0; i < E; i++) {
                Bridge bridge = bridges[i];
                int from = bridge.from;
                int to = bridge.to;
                int dist = bridge.dist;
                if (union(from, to)) {
                    answer.add(dist);
                    cnt++;
                }
                if(cnt == V-1)
                    break;
            }
            System.out.println(answer.get(answer.size()/2));
        }
    }

    static void makeSet() {
        parent = new int[V + 1];
        for (int i = 1; i <= V; i++)
            parent[i] = i;
    }

    static int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    static boolean union(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y)
            return false;
        parent[y] = x;
        return true;
    }

    static class Bridge {
        int from, to, dist;

        public Bridge(int from, int to, int dist) {
            this.from = from;
            this.to = to;
            this.dist = dist;
        }
    }
}