import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int N, M, H;
    static int answer = -1;
    static boolean[][] linked;

    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        H = Integer.parseInt(st.nextToken());
        linked = new boolean[H + 2][N + 2];
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            linked[a][b] = true;
        }

        for (int i = 0; i < 4; i++) {
            dfs(i, 0);
        }
        System.out.println(answer);
    }

    static void dfs(final int depth, int cnt) {
        if (answer != -1)
            return;
        if (depth == cnt) {
            if (isValid())
                answer = depth;
            return;
        }

        for (int j = 1; j < N; j++) {
            for (int i = 1; i <= H; i++) {
                if (linked[i][j - 1] || linked[i][j] || linked[i][j + 1])
                    continue;
                linked[i][j] = true;
                dfs(depth, cnt + 1);
                linked[i][j] = false;
            }
        }
    }

    static boolean isValid() {
        for (int j = 1; j <= N; j++) {
            int cur = j;
            for (int i = 1; i <= H; i++) {
                if (linked[i][j])
                    j++;
                else if (linked[i][j - 1])
                    j--;
            }
            if (cur != j)
                return false;
        }
        return true;
    }
}