import java.io.*;
import java.util.*;

public class Main {
    static int[] dp;
    static int answer;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int T = Integer.parseInt(st.nextToken());
        int A = Integer.parseInt(st.nextToken());
        int B = Integer.parseInt(st.nextToken());
        int ans = 0;
        boolean[][] check = new boolean[5000050][2];
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(o -> o[1]));
        pq.add(new int[]{1, A});
        pq.add(new int[]{1, B});
        while (!pq.isEmpty()) {
            int cnt = pq.peek()[0];
            int cur = pq.peek()[1];
            pq.poll();
            if (cur > T)
                continue;
            check[cur][cnt] = true;
            ans = Math.max(ans, cur);
            if (cnt == 1 && !check[cur / 2][0])
                pq.add(new int[]{0, cur / 2});
            if (T - cur >= A)
                pq.add(new int[]{cnt, cur + A * ((T - cur) / A)});
            if (T - cur >= B)
                pq.add(new int[]{cnt, cur + B * ((T - cur) / B)});
        }
        System.out.println(ans);
    }
}