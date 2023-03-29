import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static int N, answer;
    static int[][] board;
    static boolean[] visit = new boolean[10];

    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        board = new int[N][N];
        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        answer = Integer.MAX_VALUE;
        for (int i = 0; i < N; i++) {
            dfs(i, i, 0, 0);
        }
        System.out.println(answer);
    }

    static void dfs(final int start, int cur, int sum, int cnt) {
        if (start == cur && cnt == N) {
            answer = Math.min(answer, sum);
            return;
        }
        for (int i = 0; i < N; i++) {
            if (!visit[cur] && board[cur][i] != 0) {
                visit[cur] = true;
                dfs(start, i, sum + board[cur][i], cnt + 1);
                visit[cur] = false;
            }
        }
    }
}
