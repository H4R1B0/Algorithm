import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int N, M, K;
    static int[][] board;
    static boolean[][] visit;
    static int[] xd = {0, 0, 1, -1};
    static int[] yd = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        board = new int[N][M];
        int[] start = null;
        visit = new boolean[N][M];
        Queue<int[]> q = new LinkedList<int[]>();
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
                if (board[i][j] == 4) {
                    start = new int[]{i, j};
                } else if (board[i][j] == 3 && K > 0) {
                    q.add(new int[]{i, j, K});
                    visit[i][j] = true;
                }
            }
        }

        //마네킹 영역 확인
        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int x = cur[0];
            int y = cur[1];
            int cnt = cur[2];

            for (int i = 0; i < 4; i++) {
                int nx = x + xd[i];
                int ny = y + yd[i];

                if (isRange(nx, ny) && !visit[nx][ny]) {
                    visit[nx][ny] = true;
                    if (board[nx][ny] == 0 || board[nx][ny] == 2) {
                        board[nx][ny] = 3;
                    }
                    if (cnt > 1) {
                        q.add(new int[]{nx, ny, cnt - 1});
                    }
                }
            }
        }

//        Arrays.stream(board).forEach(
//            i -> System.out.println(Arrays.toString(i))
//        );

        //정답
        System.out.println(bfs(start));
    }

    static int bfs(int[] start) {
        for (int i = 0; i < N; i++) {
            Arrays.fill(visit[i], false);
        }
        Queue<int[]> q = new LinkedList<int[]>();
        q.add(new int[]{start[0], start[1], 0});
        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int x = cur[0];
            int y = cur[1];
            int cnt = cur[2];

            if (board[x][y] == 2) {
                return cnt;
            }

            for (int i = 0; i < 4; i++) {
                int nx = x + xd[i];
                int ny = y + yd[i];

                if (isRange(nx, ny) && !visit[nx][ny] && (board[nx][ny] == 0 || board[nx][ny] == 2)) {
                    visit[nx][ny] = true;
                    q.add(new int[]{nx, ny, cnt + 1});
                }
            }
        }
        return -1;
    }

    static boolean isRange(int x, int y) {
        return x >= 0 && x < N && y >= 0 && y < M;
    }
}