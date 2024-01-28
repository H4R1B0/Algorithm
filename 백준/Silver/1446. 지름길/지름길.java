import java.io.*;
import java.lang.reflect.Array;
import java.util.*;
import java.util.stream.Collectors;

public class Main {

    public static void main(String[] args) throws IOException {
        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int D = Integer.parseInt(st.nextToken());
        List<int[]>[] bridges = new ArrayList[10001];
        for (int i = 0; i < bridges.length; i++) {
            bridges[i] = new ArrayList<>();
        }
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());
            if (to > D || to - from <= cost) {
                continue;
            }
            bridges[from].add(new int[]{to, cost});
        }
        int[] dist = new int[D + 1];
        for (int i = 0; i <= D; i++) {
            dist[i] = i;
        }
        int prev = -1;
        for (int i = 0; i <= D; i++) {
            if (i != 0) {
                prev = dist[i - 1];
            }
            dist[i] = Math.min(dist[i], prev + 1);
            if (!bridges[i].isEmpty()) {
                for (int j = 0; j < bridges[i].size(); j++) {
                    int to = bridges[i].get(j)[0];
                    int cost = bridges[i].get(j)[1];
                    if (dist[to] > dist[i] + cost) {
                        dist[to] = dist[i] + cost;
                    }
                }
            }
        }
        System.out.println(dist[D]);
    }
}