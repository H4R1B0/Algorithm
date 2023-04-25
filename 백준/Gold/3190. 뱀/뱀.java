import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int[] xd = {-1, 0, 1, 0};
    static int[] yd = {0, 1, 0, -1};
    static int N;
    static int[][] board;
    //    static int[][] tmp;
    static List<Dir> arr = new LinkedList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        board = new int[N][N];
        int K = Integer.parseInt(br.readLine());
        String[] tmpSplit = null;
        for (int i = 0; i < K; i++) {
            tmpSplit = br.readLine().split(" ");
            int x = Integer.parseInt(tmpSplit[0]);
            int y = Integer.parseInt(tmpSplit[1]);
            board[x - 1][y - 1] = 1;
        }
        int L = Integer.parseInt(br.readLine());
        for (int i = 0; i < L; i++) {
            tmpSplit = br.readLine().split(" ");
            int time = Integer.parseInt(tmpSplit[0]);
            char dir = tmpSplit[1].charAt(0);
            arr.add(new Dir(time, dir));
        }

        System.out.println(getAnswer());
    }

    static int getAnswer() {
        int x = 0, y = 0, dir = 1, time = 0, idx = 0;
        Deque<Pos> dq = new LinkedList<>();
        dq.add(new Pos(x, y));
        board[x][y] = 2;
        while (true) {
            int nx = x + xd[dir];
            int ny = y + yd[dir];
            time++;

            if (nx < 0 || nx >= N || ny < 0 || ny >= N || board[nx][ny] == 2)
                break;

            if (board[nx][ny] == 0) {
                dq.addFirst(new Pos(nx, ny));
                board[nx][ny] = 2;
                board[dq.peekLast().x][dq.peekLast().y] = 0;
                dq.pollLast();
            } else if (board[nx][ny] == 1) {
                dq.addFirst(new Pos(nx, ny));
                board[nx][ny] = 2;
            }

            if (idx < arr.size()) {
                if (time == arr.get(idx).time) {
                    if (arr.get(idx).dir == 'L')
                        dir = (dir + 3) % 4;
                    else
                        dir = (dir + 1) % 4;
                    idx++;
                }
            }
            x=nx;
            y=ny;
        }
        return time;
    }

    static class Pos {
        int x, y;

        Pos(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static class Dir {
        int time;
        char dir;

        Dir(int time, char dir) {
            this.time = time;
            this.dir = dir;
        }
    }
}