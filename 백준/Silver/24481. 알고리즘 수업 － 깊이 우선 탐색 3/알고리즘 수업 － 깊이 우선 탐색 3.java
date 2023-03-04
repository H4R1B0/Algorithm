import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    static int N, M, R;
    static List<List<Integer>> graph = new ArrayList<List<Integer>>();
    static int[] visit;
//    static int tmp = 0;

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        R = Integer.parseInt(st.nextToken());
        visit = new int[N + 1];

        for (int i = 1; i <= N; i++) {
            visit[i] = -1;
        }

        for (int i = 0; i <= N; i++) {
            graph.add(new ArrayList<Integer>());
        }

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            graph.get(a).add(b);
            graph.get(b).add(a);
        }

        for (int i = 1; i < N; i++) {
            Collections.sort(graph.get(i));
//            System.out.println(graph.get(i));
        }
        visit[R] = 0;
        DFS(R, 0);

        for(int i=1;i<=N;i++){
            System.out.println(visit[i]);
        }
//        System.out.println(Arrays.toString(visit));

    }

    private static void DFS(int num, int depth) {
        if (num != R && visit[num] != -1)
            return;

        visit[num] = depth;
        for (int next : graph.get(num)) {
            if (visit[next] == -1) {
                DFS(next, depth + 1);
            }
        }

    }
}