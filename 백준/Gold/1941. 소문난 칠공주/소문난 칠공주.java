import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    static int N = 5, M = 5;
    static char[][] board = new char[N][M];
    static int answer = 0;
    static int[] xd = {0, 0, 1, -1};
    static int[] yd = {1, -1, 0, 0};
    static List<Integer> list = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        for (int i = 0; i < N; i++) {
            board[i] = br.readLine().toCharArray();
        }
        dfs(0, 0);
        System.out.println(answer);
    }

    static void dfs(int idx, int cnt) {
        if (cnt == 7) {
            if (isValid()) {
//                System.out.println(list);
                answer++;
            }
            return;
        }

        for (int i = idx; i < N * M; i++) {
            list.add(i);
            dfs(i + 1, cnt + 1);
            list.remove(list.size() - 1);
        }
    }

    private static boolean isValid() {
        Queue<Integer> q = new ArrayDeque<>();
        boolean[] visit = new boolean[7];
        visit[0] = true;
        q.add(list.get(0));
        int cnt = 1, cntS = 0;
        while (!q.isEmpty()) {
            int cur = q.poll();
            if (board[cur / M][cur % M] == 'S')
                cntS++;
            for (int i = 0; i < 4; i++) {
                int nx = cur / M + xd[i];
                int ny = cur % M + yd[i];
                if(!(nx>=0 && nx<N && ny>=0 && ny<M))
                    continue;

                for (int next = 1; next < 7; next++) {
                    if (!visit[next] && list.get(next) == (nx * M + ny)) {
//                        System.out.println(list.get(next));
                        visit[next] = true;
                        q.add(list.get(next));
                        cnt++;
                    }
                }
            }
        }
        return cnt == 7 && cntS >= 4;
    }
}