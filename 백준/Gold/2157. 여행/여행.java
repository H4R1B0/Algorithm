import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static final int MOD = 1000000000;

    public static void main(String[] args) throws IOException {
        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        int[][] dp = new int[N + 1][M + 1];
        List<int[]>[] bridges = new ArrayList[N + 1];
        for (int i = 1; i <= N; i++) {
            bridges[i] = new ArrayList<int[]>();
        }

        for (int i = 0; i < K; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            if (a > b) {
                continue;
            }

            bridges[a].add(new int[]{b, c});
        }

        Queue<Integer> q = new LinkedList<Integer>();
        q.add(1);
        int cnt = 1;
        while (!q.isEmpty() && cnt < M) {
            int qSize = q.size();

            while (qSize-- > 0) {
                int cur = q.poll();

                for (int i = 0; i < bridges[cur].size(); i++) {
                    int next = bridges[cur].get(i)[0];
                    int nextScore = bridges[cur].get(i)[1] + dp[cur][cnt];

                    if (dp[next][cnt + 1] >= nextScore) {
                        continue;
                    }

                    dp[next][cnt + 1] = nextScore;
                    q.add(next);
                }
            }
            cnt++;
        }

        int answer = 0;
        for (int i = 2; i <= M; i++) {
            answer = Math.max(answer, dp[N][i]);
        }
        System.out.println(answer);
    }
}