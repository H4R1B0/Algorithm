import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int[] xd = {0, 0, 1, -1};
    static int[] yd = {1, -1, 0, 0};
    static int H, W;
    static char[][] board;
    static int[][] dist;
    static int[] startC = new int[2];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        W = Integer.parseInt(st.nextToken());
        H = Integer.parseInt(st.nextToken());

        board = new char[H][W];
        dist = new int[H][W];
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                dist[i][j] = Integer.MAX_VALUE;
            }
        }

        for (int i = 0; i < H; i++) {
            board[i] = br.readLine().toCharArray();
            for (int j = 0; j < W; j++) {
                if (board[i][j] == 'C') {
                    startC[0] = i;
                    startC[1] = j;
                }
            }
        }
        System.out.println(getAnswer());
    }

    static int getAnswer() {
        boolean[][][] visit = new boolean[H][W][4];
        //x, y, dir, turnCount
        PriorityQueue<int[]> pq = new PriorityQueue<>((o1, o2) -> {
            return o1[3] - o2[3];
        });
        pq.add(new int[]{startC[0], startC[1], -1, 0});
        dist[startC[0]][startC[1]] = 0;
        int cntC = 0;
        while (!pq.isEmpty()) {
            int[] cur = pq.poll();
            int x = cur[0];
            int y = cur[1];
            int dir = cur[2];
            int cnt = cur[3];

            if (board[x][y] == 'C') {
                cntC++;
                if (cntC == 2)
                    return dist[x][y];
            }

            if (cnt > dist[x][y]) {
                continue;
            }

            for (int i = 0; i < 4; i++) {
                int nx = x + xd[i];
                int ny = y + yd[i];
                if (isInRange(nx, ny) && board[nx][ny] != '*') {
                    if (dir == i || dir == -1) {
                        if (dist[nx][ny] >= cnt && !visit[nx][ny][i]) {
                            visit[nx][ny][i] = true;
                            dist[nx][ny] = cnt;
                            pq.add(new int[]{nx, ny, i, cnt});
                        }
                    } else {
                        if (dist[nx][ny] >= cnt + 1 && !visit[nx][ny][i]) {
                            visit[nx][ny][i] = true;
                            dist[nx][ny] = cnt + 1;
                            pq.add(new int[]{nx, ny, i, cnt + 1});
                        }
                    }
                }
            }
        }
        return -1;
    }

    static boolean isInRange(int x, int y) {
        return x >= 0 && x < H && y >= 0 && y < W;
    }
}