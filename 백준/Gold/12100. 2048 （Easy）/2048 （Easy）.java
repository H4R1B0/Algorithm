import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    static int[] xd = {0, 0, 1, -1};
    static int[] yd = {1, -1, 0, 0};
    static int N;
    static int[][] board;
//    static int[][] tmp;
    static int answer = 0;
    static Queue<Integer> q = new LinkedList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        board = new int[N][N];
//        tmp = new int[N][N];
        for (int i = 0; i < N; i++) {
            board[i] = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        }

        dfs(0);
        System.out.println(answer);
    }

    static void dfs(int cnt) {
        if (cnt == 5) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    answer = Math.max(answer, board[i][j]);
                }
            }
            return;
        }

        int[][] tmp = new int[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                tmp[i][j] = board[i][j];
            }
        }

        for (int dir = 0; dir < 4; dir++) {
            move(dir);
            dfs(cnt + 1);
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    board[i][j] = tmp[i][j];
                }
            }
        }
    }

    static void copy(int[][] from, int[][] to) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                to[i][j] = from[i][j];
            }
        }
    }

    private static void move(int dir) {
        q.clear();
        if (dir == 0) {
            for (int i = 0; i < N; i++) {
                for (int j = N - 1; j >= 0; j--) {
                    if (board[i][j] != 0)
                        q.add(board[i][j]);
                    board[i][j] = 0;
                }

                int idx = N - 1;
                while (!q.isEmpty()) {
                    int cur = q.poll();
                    if (board[i][idx] == 0)
                        board[i][idx] = cur;
                    else if (board[i][idx] == cur) {
                        board[i][idx] *= 2;
                        idx--;
                    } else {
                        idx--;
                        board[i][idx] = cur;
                    }
                }
            }
        }
        else if (dir == 1) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (board[i][j] != 0)
                        q.add(board[i][j]);
                    board[i][j] = 0;
                }

                int idx = 0;
                while (!q.isEmpty()) {
                    int cur = q.poll();
                    if (board[i][idx] == 0)
                        board[i][idx] = cur;
                    else if (board[i][idx] == cur) {
                        board[i][idx] *= 2;
                        idx++;
                    } else {
                        idx++;
                        board[i][idx] = cur;
                    }
                }
            }
        }
        else if (dir == 2) {
            for (int j = 0; j < N; j++) {
                for (int i = N - 1; i >= 0; i--) {
                    if (board[i][j] != 0)
                        q.add(board[i][j]);
                    board[i][j] = 0;
                }

                int idx = N - 1;
                while (!q.isEmpty()) {
                    int cur = q.poll();
                    if (board[idx][j] == 0) {
                        board[idx][j] = cur;
                    } else if (board[idx][j] == cur) {
                        board[idx][j] *= 2;
                        idx--;
                    } else {
                        idx--;
                        board[idx][j] = cur;
                    }
                }
            }
        }
        else if (dir == 3) {
            for (int j = 0; j < N; j++) {
                for (int i = 0; i < N; i++) {
                    if (board[i][j] != 0)
                        q.add(board[i][j]);
                    board[i][j] = 0;
                }

                int idx = 0;
                while (!q.isEmpty()) {
                    int cur = q.poll();
                    if (board[idx][j] == 0) {
                        board[idx][j] = cur;
                    } else if (board[idx][j] == cur) {
                        board[idx][j] *= 2;
                        idx++;
                    } else {
                        idx++;
                        board[idx][j] = cur;
                    }
                }
            }
        }
    }
}