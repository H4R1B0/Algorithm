import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

class Solution {
    static int[] xd = {0, 0, 1, -1};
    static int[] yd = {1, -1, 0, 0};
    static int N, H, W, answer;
    static int[][] board;
    static int[][] tmpBoard;
    static int[] order;

    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        for (int test_case = 1; test_case <= T; test_case++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            W = Integer.parseInt(st.nextToken());
            H = Integer.parseInt(st.nextToken());
            board = new int[H][W];
            tmpBoard = new int[H][W];
            order = new int[N];
            for (int i = 0; i < H; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < W; j++) {
                    board[i][j] = Integer.parseInt(st.nextToken());
                }
            }
            answer = Integer.MAX_VALUE;
            select(0);
            System.out.printf("#%d %d\n", test_case, answer);
//            System.out.println(getX(0));
        }
    }

    static void select(int idx) {
        if (idx == N) {
//            System.out.println(Arrays.toString(order));
            play();
            return;
        }
        for (int i = 0; i < W; i++) {
            order[idx] = i;
            select(idx + 1);
        }
    }

    static void play() {
//        System.out.println("------------");
        for (int i = 0; i < H; i++) {
            tmpBoard[i] = board[i].clone();
//            System.out.println(Arrays.toString(tmpBoard[i]));
        }
        Queue<int[]> q = new LinkedList<>();
        for (int cnt = 0; cnt < N; cnt++) {
            int y = order[cnt];
            int x = getX(y);
            if (x == H)
                continue;
            if (tmpBoard[x][y] > 1)
                q.offer(new int[]{x, y, tmpBoard[x][y]});
            tmpBoard[x][y] = 0;
//            tmpBoard[getX(order[cnt])][order[cnt]] = 0;
            while (!q.isEmpty()) {
                int[] cur = q.poll();
                x = cur[0];
                y = cur[1];
                int num = cur[2];
//                System.out.println(num);
//                System.out.printf("%d %d %d\n", x, y, num);
                for (int dir = 0; dir < 4; dir++) {
                    for (int i = 1; i < num; i++) {
                        int nx = x + xd[dir] * i;
                        int ny = y + yd[dir] * i;
                        if (isInRange(nx, ny) && tmpBoard[nx][ny] != 0) {
                            if (tmpBoard[nx][ny] > 1)
                                q.offer(new int[]{nx, ny, tmpBoard[nx][ny]});
                            tmpBoard[nx][ny] = 0;
                        }
                    }
                }
            }

            gravity();
//            print();
        }

        int cnt = 0;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (tmpBoard[i][j] > 0)
                    cnt++;
            }
        }
        answer = Math.min(answer, cnt);
    }

    static void print() {
        System.out.println("----------------");
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                System.out.print(tmpBoard[i][j] + " ");
            }
            System.out.println();
        }
    }

    private static void gravity() {
        for (int j = 0; j < W; j++) {
            Queue<Integer> q = new LinkedList<>();
            for (int i = H - 1; i >= 0; i--) {
                if (tmpBoard[i][j] != 0) {
                    q.offer(tmpBoard[i][j]);
                    tmpBoard[i][j] = 0;
                }
            }
            for (int i = H - 1; i >= 0 && !q.isEmpty(); i--) {
                tmpBoard[i][j] = q.poll();
            }
        }
//        print();
    }

    static boolean isInRange(int x, int y) {
        return x >= 0 && x < H && y >= 0 & y < W;
    }

    static int getX(int y) {
        int x = 0;
        for (; x < H; x++) {
            if (tmpBoard[x][y] != 0)
                break;
        }
        return x;
    }
}