import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    static int[] xd = {0, 0, 1, -1};
    static int[] yd = {1, -1, 0, 0};
    static char[][] board;
    static int R, C;
    static Queue<int[]> water = new LinkedList<>();
    static Queue<int[]> start = new LinkedList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        board = new char[R][C];
        for (int i = 0; i < R; i++) {
            board[i] = br.readLine().toCharArray();
            for (int j = 0; j < C; j++) {
                if (board[i][j] == 'S') {
                    start.add(new int[]{i, j});
                } else if (board[i][j] == '*') {
                    water.add(new int[]{i, j});
                }
            }
        }
        int answer = getAnswer();
        System.out.println(answer == -1 ? "KAKTUS" : answer - 1);
    }

    static int getAnswer() {
        boolean[][] visit = new boolean[R][C];
        int cnt = 0;
        while (!start.isEmpty()) {
            cnt++;
            int qSize = water.size();
            while (qSize-- > 0) {
                int[] cur = water.poll();

                for (int i = 0; i < 4; i++) {
                    int nx = cur[0] + xd[i];
                    int ny = cur[1] + yd[i];

                    if (isInRange(nx, ny)) {
                        if (board[nx][ny] == '.') {
                            water.add(new int[]{nx, ny});
                            board[nx][ny] = '*';
                        }
                    }
                }
            }

            qSize = start.size();
            while (qSize-- > 0) {
                int[] cur = start.poll();

                if (board[cur[0]][cur[1]] == 'D')
                    return cnt;
                visit[cur[0]][cur[1]] = true;

                for (int i = 0; i < 4; i++) {
                    int nx = cur[0] + xd[i];
                    int ny = cur[1] + yd[i];

                    if (isInRange(nx, ny)) {
                        if (board[nx][ny] != '*' && board[nx][ny] != 'X' && !visit[nx][ny]) {
                            visit[nx][ny] = true;
                            start.add(new int[]{nx, ny});
                        }
                    }
                }
            }
        }
        return -1;
    }

    static boolean isInRange(int x, int y) {
        return x >= 0 && x < R && y >= 0 && y < C;
    }
}