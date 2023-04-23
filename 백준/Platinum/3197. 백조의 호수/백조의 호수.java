import java.io.*;
import java.util.*;

public class Main {
    static int N, M;
    static boolean isFind;
    static char[][] board;
    static boolean[][] visit;
    static int[] swan;
    static Queue<int[]> waterQ = new LinkedList<>();
    static Queue<int[]> swanQ = new LinkedList<>();
    static int[] xd = {0, 0, 1, -1};
    static int[] yd = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        board = new char[N][M];
        visit = new boolean[N][M];
        for (int i = 0; i < N; i++) {
            board[i] = br.readLine().toCharArray();
            for (int j = 0; j < M; j++) {
                if (board[i][j] != 'X')
                    waterQ.add(new int[]{i, j});
                if (board[i][j] == 'L')
                    swan = new int[]{i, j};
            }
        }
        System.out.println(getAnswer());
    }

    static int getAnswer() {
        int day = 0;
        isFind = false;
        swanQ.add(swan);
        visit[swan[0]][swan[1]] = true;

        while (!isFind) {
            //백조 이동
            move();
            if(!isFind){
                melt();
                day++;
            }
        }
        return day;
    }

    static void move() {
        //백조가 다음에 이동할 위치를 저장하는 임시 큐
        Queue<int[]> tmp = new LinkedList<int[]>();
        while (!swanQ.isEmpty() && !isFind) {
            int[] cur = swanQ.poll();

            for (int i = 0; i < 4; i++) {
                int nx = cur[0] + xd[i];
                int ny = cur[1] + yd[i];

                if (isInRange(nx, ny) && !visit[nx][ny]) {
                    if (board[nx][ny] == '.') {
                        visit[nx][ny] = true;
                        swanQ.add(new int[]{nx, ny});
                    } else if (board[nx][ny] == 'X') {
                        visit[nx][ny] = true;
                        tmp.add(new int[]{nx, ny});
                    } else if (board[nx][ny] == 'L') {
                        visit[nx][ny] = true;
                        isFind = true;
                        return;
                    }
                }
            }
        }

        swanQ.clear();
        while (!tmp.isEmpty()) {
            swanQ.add(tmp.poll());
        }
    }

    static void melt() {
        int qSize = waterQ.size();
        while (qSize-- > 0) {
            int[] cur = waterQ.poll();
//            System.out.println(cur);
            for (int i = 0; i < 4; i++) {
                int nx = cur[0] + xd[i];
                int ny = cur[1] + yd[i];

                if (isInRange(nx, ny) && board[nx][ny] == 'X') {
                    board[nx][ny] = '.';
                    waterQ.add(new int[]{nx, ny});
                }
            }
        }
    }


    static boolean isInRange(int x, int y) {
        return x >= 0 && x < N && y >= 0 && y < M;
    }
}