import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static int[] xd = {0, 0, 1, -1};
    static int[] yd = {1, -1, 0, 0};
    static int N, M;
    static char[][] board;
    static int[] start;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        board = new char[N][M];
        for (int i = 0; i < N; i++) {
            board[i] = br.readLine().toCharArray();
            for (int j = 0; j < M; j++) {
                if (board[i][j] == '0') {
                    board[i][j] = '.';
                    start = new int[]{i, j};
                }
            }
        }
        System.out.println(bfs());
    }

    static int bfs() {
        //x, y, cnt, key
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{start[0],start[1],0,0});
        boolean[][][] visit = new boolean[N][M][1 << 6];
        visit[start[0]][start[1]][0] = true;
        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int x = cur[0];
            int y = cur[1];
            int cnt = cur[2];
            int key = cur[3];

            if (board[x][y] == '1')
                return cnt;

            for (int i = 0; i < 4; i++) {
                int nx = x + xd[i];
                int ny = y + yd[i];
                if (isInRange(nx, ny) && !visit[nx][ny][key]) {
                    if (board[nx][ny] == '.' || board[nx][ny] == '1') {
                        visit[nx][ny][key] = true;
                        q.add(new int[]{nx, ny, cnt + 1, key});
                    } else if ('a' <= board[nx][ny] && board[nx][ny] <= 'f') {
                        int nextKey = key | (1 << (board[nx][ny] - 'a'));
                        visit[nx][ny][nextKey] = true;
                        q.add(new int[]{nx, ny, cnt + 1, nextKey});
                    } else if ('A' <= board[nx][ny] && board[nx][ny] <= 'F') {
                        if (isValid(key, board[nx][ny])) {
                            visit[nx][ny][key] = true;
                            q.add(new int[]{nx, ny, cnt + 1, key});
                        }
                    }
                }
            }
        }
        return -1;
    }

    private static boolean isValid(int key, char c) {
        return (key & (1 << (c - 'A'))) != 0;
    }

    static boolean isInRange(int x, int y) {
        return x >= 0 && x < N && y >= 0 && y < M;
    }
}