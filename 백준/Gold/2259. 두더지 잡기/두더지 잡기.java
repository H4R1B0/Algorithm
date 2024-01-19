import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {
    static int N, S;

    public static void main(String[] args) throws IOException {
        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        S = Integer.parseInt(st.nextToken());

        List<Point> pos = new ArrayList<>(N + 1);
        pos.add(new Point(0, 0, 0));

        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            int T = Integer.parseInt(st.nextToken());

            pos.add(new Point(x, y, T));
        }
        pos.sort((Comparator.comparingInt(o -> o.t)));

        int[] dp = new int[N + 1];
        Arrays.fill(dp, -1);
        dp[0] = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] != -1 && check(pos.get(j), pos.get(i))) {
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                }
            }
        }
        int answer = Arrays.stream(dp).max().getAsInt();
        System.out.println(answer);
    }

    static boolean check(Point from, Point to) {
        return Math.sqrt(Math.pow(to.x - from.x, 2) + Math.pow(to.y - from.y, 2)) <= S * (to.t - from.t);
    }

    static class Point {
        int x, y, t;

        public Point(int x, int y, int t) {
            this.x = x;
            this.y = y;
            this.t = t;
        }
    }
}