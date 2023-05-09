import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Main {
    static int N;
    static char[][] board;
    static boolean[][][] visit;

    // U, D, L, R, T
    static int[] xd = { -1, 1, 0, 0 };
    static int[] yd = { 0, 0, -1, 1 };

    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        board = new char[N][N];
        visit = new boolean[N][N][2];
        // B 리스트
        List<int[]> Blist = new ArrayList<>();
        //E 리스트
        List<int[]> Elist = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            board[i] = br.readLine().toCharArray();
            for (int j = 0; j < N; j++) {
                if (board[i][j] == 'B') {
                    board[i][j] = '0';
                    Blist.add(new int[] { i, j });
                } else if (board[i][j] == 'E') {
                    board[i][j] = '0';
                    Elist.add(new int[] { i, j });
                }
            }
        }

        // x, y, 현재 기둥 방향, 횟수
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[] { Blist.get(1)[0], Blist.get(1)[1], isColRow(Blist), 0 });
        //현재 좌표와 현재 방향 체크
        visit[Blist.get(1)[0]][Blist.get(1)[1]][isColRow(Blist)] = true;
        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int x = cur[0];
            int y = cur[1];
            int dir = cur[2];
            int cnt = cur[3];

//			System.out.println(x + " " + y + " " + cnt);

            // B와 E의 중심 좌표가 같고 방향이 같다면 리턴
            if (x == Elist.get(1)[0] && y == Elist.get(1)[1] && dir == isColRow(Elist)) {
                System.out.println(cnt);
                return;
            }

            // U
            // 세로
            if (dir == 0) {
                if (isInRange(x - 2, y) && board[x - 2][y] == '0' && !visit[x - 1][y][dir]) {
                    visit[x - 1][y][dir] = true;
                    q.add(new int[] { x - 1, y, dir, cnt + 1 });
                }
            }
            // 가로
            else {
                if (isInRange(x - 1, y - 1) && isInRange(x - 1, y) && isInRange(x - 1, y + 1)) {
                    if (board[x - 1][y - 1] == '0' && board[x - 1][y] == '0' && board[x - 1][y + 1] == '0') {
                        if (!visit[x - 1][y][dir]) {
                            visit[x - 1][y][dir] = true;
                            q.add(new int[] { x - 1, y, dir, cnt + 1 });
                        }
                    }
                }
            }

            // D
            // 세로
            if (dir == 0) {
                if (isInRange(x + 2, y) && board[x + 2][y] == '0' && !visit[x + 1][y][dir]) {
                    visit[x + 1][y][dir] = true;
                    q.add(new int[] { x + 1, y, dir, cnt + 1 });
                }
            }
            // 가로
            else {
                if (isInRange(x + 1, y - 1) && isInRange(x + 1, y) && isInRange(x + 1, y + 1)) {
                    if (board[x + 1][y - 1] == '0' && board[x + 1][y] == '0' && board[x + 1][y + 1] == '0') {
                        if (!visit[x + 1][y][dir]) {
                            visit[x + 1][y][dir] = true;
                            q.add(new int[] { x + 1, y, dir, cnt + 1 });
                        }
                    }
                }
            }

            // L
            // 세로
            if (dir == 0) {
                if (isInRange(x - 1, y - 1) && isInRange(x, y - 1) && isInRange(x + 1, y - 1)) {
                    if (board[x - 1][y - 1] == '0' && board[x][y - 1] == '0' && board[x + 1][y - 1] == '0') {
                        if (!visit[x][y - 1][dir]) {
                            visit[x][y - 1][dir] = true;
                            q.add(new int[] { x, y - 1, dir, cnt + 1 });
                        }
                    }
                }
            }
            // 가로
            else {
                if (isInRange(x, y - 2) && board[x][y - 2] == '0' && !visit[x][y - 1][dir]) {
                    visit[x][y - 1][dir] = true;
                    q.add(new int[] { x, y - 1, dir, cnt + 1 });
                }
            }

            // R
            // 세로
            if (dir == 0) {
                if (isInRange(x - 1, y + 1) && isInRange(x, y + 1) && isInRange(x + 1, y + 1)) {
                    if (board[x - 1][y + 1] == '0' && board[x][y + 1] == '0' && board[x + 1][y + 1] == '0') {
                        if (!visit[x][y + 1][dir]) {
                            visit[x][y + 1][dir] = true;
                            q.add(new int[] { x, y + 1, dir, cnt + 1 });
                        }
                    }
                }
            }
            // 가로
            else {
                if (isInRange(x, y + 2) && board[x][y + 2] == '0' && !visit[x][y + 1][dir]) {
                    visit[x][y + 1][dir] = true;
                    q.add(new int[] { x, y + 1, dir, cnt + 1 });
                }
            }

            // T
            // 세로
            if (dir == 0) {
                if (isColTurn(x, y)) {
                    if (!visit[x][y][(dir + 1) % 2]) {
//						System.out.println(x + " " + y + " " + cnt);
                        visit[x][y][(dir + 1) % 2] = true;
                        q.add(new int[] { x, y, (dir + 1) % 2, cnt + 1 });
                    }
                }
            }
            // 가로
            else {
                if (isRowTurn(x, y)) {
                    if (!visit[x][y][(dir + 1) % 2]) {
//						System.out.println(x + " " + y + " " + cnt);
                        visit[x][y][(dir + 1) % 2] = true;
                        q.add(new int[] { x, y, (dir + 1) % 2, cnt + 1 });
                    }
                }
            }
        }
        System.out.println(0);
    }

    // 가로 중심좌표를 기준으로 회전 가능한지
    static boolean isRowTurn(int x, int y) {
        // 6개 범위 안에 있는지
        if (isInRange(x - 1, y - 1) && isInRange(x - 1, y) && isInRange(x - 1, y + 1) && isInRange(x + 1, y - 1)
                && isInRange(x + 1, y) && isInRange(x + 1, y + 1)) {
            // 6개 모두 0인지
            if (board[x - 1][y - 1] == '0' && board[x - 1][y] == '0' && board[x - 1][y + 1] == '0'
                    && board[x + 1][y - 1] == '0' && board[x + 1][y] == '0' && board[x + 1][y + 1] == '0') {
                return true;
            }
        }
        return false;
    }

    // 세로 중심좌표를 기준으로 회전 가능한지
    static boolean isColTurn(int x, int y) {
        // 6개 범위 안에 있는지
        if (isInRange(x - 1, y - 1) && isInRange(x, y - 1) && isInRange(x + 1, y - 1) && isInRange(x - 1, y + 1)
                && isInRange(x, y + 1) && isInRange(x + 1, y + 1)) {
            // 6개 모두 0인지
            if (board[x - 1][y - 1] == '0' && board[x][y - 1] == '0' && board[x + 1][y - 1] == '0'
                    && board[x - 1][y + 1] == '0' && board[x][y + 1] == '0' && board[x + 1][y + 1] == '0') {
                return true;
            }
        }
        return false;
    }

    static boolean isInRange(int x, int y) {
        return x >= 0 && x < N && y >= 0 && y < N;
    }

    // 기둥이 가로인지 세로인지 확인
    // 가로는 1, 세로는 0
    static int isColRow(List<int[]> list) {
        if (list.get(0)[0] == list.get(1)[0])
            return 1;
        return 0;
    }

}