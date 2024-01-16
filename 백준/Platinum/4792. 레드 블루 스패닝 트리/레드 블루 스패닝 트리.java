import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int N, M, K;
    static int[] parent = new int[1001];
    static List<int[]>[] bridges = new ArrayList[2];

    public static void main(String[] args) throws IOException {
        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;
        bridges[0] = new ArrayList<>();
        bridges[1] = new ArrayList<>();
        StringBuilder answer = new StringBuilder();

        while (true) {
            st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());
            K = Integer.parseInt(st.nextToken());

            if (N == 0 && M == 0 && K == 0) {
                break;
            }

            bridges[0].clear();
            bridges[1].clear();
            for (int i = 0; i < M; i++) {
                st = new StringTokenizer(br.readLine());
                char c = st.nextToken().charAt(0);
                int f = Integer.parseInt(st.nextToken());
                int t = Integer.parseInt(st.nextToken());
                int w = c == 'B' ? 1 : 0;
                bridges[0].add(new int[]{w, f, t});
                bridges[1].add(new int[]{w, f, t});
            }

            bridges[0].sort((o1, o2) -> {
                return o1[0] - o2[0];
            });
            bridges[1].sort((o1, o2) -> {
                return o2[0] - o1[0];
            });

            int min = kruskal(0);
            int max = kruskal(1);
            if (min == -1 || max == -1) {
                answer.append(0).append('\n');
                continue;
            }
            if (min <= K && K <= max) {
                answer.append(1).append('\n');
            } else {
                answer.append(0).append('\n');
            }
        }

        System.out.println(answer);
    }

    //0: 파란색 간선 최소화
    //1: 파란색 간선 최대화
    static int kruskal(int mode) {
        int cnt = 0, sum = 0;

        for (int i = 1; i <= N; i++) {
            parent[i] = i;
        }

        for (int i = 0; i < M; i++) {
            int[] cur = bridges[mode].get(i);
            int w = cur[0];
            int f = cur[1];
            int t = cur[2];
            if (find(f) != find(t)) {
                union(f, t);
                sum += w;
                cnt++;

                if (cnt == N - 1) {
                    return sum;
                }
            }
        }
        return -1;
    }

    static int find(int x) {
        if (x == parent[x]) {
            return x;
        }
        return find(parent[x]);
    }

    static void union(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            parent[x] = y;
        }
    }
}