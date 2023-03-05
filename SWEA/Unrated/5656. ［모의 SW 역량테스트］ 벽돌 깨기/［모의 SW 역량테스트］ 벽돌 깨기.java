import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

class Solution {
    // 상하좌우
    static int[] xd = {-1, 1, 0, 0};
    static int[] yd = {0, 0, -1, 1};
    static int H, W, N, answer;
    static int[][] board, tmpBoard;
    static int[] order;

    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        for (int test_case = 1; test_case <= T; test_case++) {
            answer = Integer.MAX_VALUE;
            StringTokenizer st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            W = Integer.parseInt(st.nextToken());
            H = Integer.parseInt(st.nextToken());
            order = new int[N];
            board = new int[H][W];
            tmpBoard = new int[H][W];

            for (int i = 0; i < H; i++) {
                board[i] = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
//                System.out.println(Arrays.toString(board[i]));
            }

//            System.out.println(getPosition(0));
            select(0);
            System.out.printf("#%d %d\n", test_case, answer);
        }
    }

    static void select(int cnt) {
        if (cnt == N) {
//            System.out.println("------");
//            System.out.println(Arrays.toString(order));
            play();
            return;
        }

        for (int i = 0; i < W; i++) {
            order[cnt] = i;
            select(cnt + 1);
        }
    }

    static void play() {
        //맵 복사
        for (int i = 0; i < H; i++) {
            tmpBoard[i] = board[i].clone();
        }

        int result = 0;
        Queue<Pos> explosions = new LinkedList<>();
        Queue<Pos> q = new LinkedList<Pos>();
        for (int cnt = 0; cnt < N; cnt++) {
            boolean[][] visit = new boolean[H][W];
            explosions.clear();
            //시작점
            int y = order[cnt];
            int x = getPosition(y).x;
            //해당 줄에 벽돌이 없으면 패스
            if (x == H)
                continue;

            //폭발 범위 전체 확인
            q.add(new Pos(x, y));
            visit[x][y] = true;
            explosions.add(new Pos(x, y));
            while (!q.isEmpty()) {
                Pos cur = q.poll();
//                System.out.println(cur.x);
                int num = tmpBoard[cur.x][cur.y];

                for (int dir = 0; dir < 4; dir++) {
                    for (int j = 1; j < num; j++) {
                        int nx = cur.x + xd[dir] * j;
                        int ny = cur.y + yd[dir] * j;
                        if (isInRange(nx, ny) && !visit[nx][ny] && tmpBoard[nx][ny] != 0) {
                            visit[nx][ny] = true;
                            explosions.add(new Pos(nx, ny));
                            q.add(new Pos(nx, ny));
                        }
                    }
                }
            }

            for (Pos explosion : explosions) {
                tmpBoard[explosion.x][explosion.y] = 0;
            }

            //벽돌 떨어짐
            gravity();
        }

        for (int i = 0; i < H; i++) {
//            System.out.println(Arrays.toString(tmpBoard[i]));
            for (int j = 0; j < W; j++) {
                if(tmpBoard[i][j] != 0)
                    result++;
            }
        }
        answer = Math.min(answer, result);
    }

    static void gravity() {
        for (int j = 0; j < W; j++) {
            Queue<Integer> q = new LinkedList<>();
            for (int i = H - 1; i >= 0; i--) {
                if (tmpBoard[i][j] != 0) {
                    q.add(tmpBoard[i][j]);
                    tmpBoard[i][j] = 0;
                }
            }
            for (int i = H - 1; i >= 0 && !q.isEmpty(); i--) {
                tmpBoard[i][j] = q.poll();
            }
        }
    }

    static Pos getPosition(int y) {
        int x = 0;
        while (x < H) {
//            System.out.println(x);
            if (tmpBoard[x][y] != 0) {
//                x -= xd[1];
                break;
            }
            x++;
        }
//        System.out.println(x);
        return new Pos(x, y);
    }

    static boolean isInRange(int x, int y) {
        return x >= 0 && x < H && y >= 0 && y < W;
    }

    static class Pos {
        int x, y;

        public Pos(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public String toString() {
            return "Pos{" +
                    "x=" + x +
                    ", y=" + y +
                    '}';
        }
    }
}