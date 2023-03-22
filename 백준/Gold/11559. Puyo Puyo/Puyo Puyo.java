import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.file.WatchKey;
import java.util.*;

public class Main {
    static int[] xd = {0, 0, 1, -1};
    static int[] yd = {1, -1, 0, 0};
    static int N = 12, M = 6;
    static char[][] board;
    static boolean[][] visit;
    static List<int[]> positions = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        board = new char[N][M];
        for (int i = 0; i < N; i++) {
            board[i] = br.readLine().toCharArray();
        }
        System.out.println(getAnswer());
    }

    static int getAnswer() {
        int answer = 0;
        boolean isOver = false;
        while (!isOver) {
            isOver = true;
            visit = new boolean[N][M];

            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    if (board[i][j] != '.' && !visit[i][j]) {
                        int cnt = getCount(i, j);
                        if (cnt >= 4) {
                            isOver = false;
                        }
                    }
                }
            }
            if (!isOver) {
                answer++;
            }

            gravity();
        }
        return answer;
    }

    private static void gravity() {
        Queue<Character> q = new LinkedList<>();
        for (int j = 0; j < M; j++) {
            for (int i = N - 1; i >= 0; i--) {
                if (board[i][j] != '.') {
                    q.add(board[i][j]);
                    board[i][j] = '.';
                }
            }
            for (int i = N - 1; i >= 0 && !q.isEmpty(); i--) {
                board[i][j] = q.poll();
            }
        }
    }

    static int getCount(int a, int b) {
        positions.clear();
        int cnt = 1;
        Queue<int[]> q = new LinkedList<int[]>();
        q.add(new int[]{a, b});
        visit[a][b] = true;
        positions.add(new int[]{a, b});
        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int x = cur[0];
            int y = cur[1];
            for (int i = 0; i < 4; i++) {
                int nx = x + xd[i];
                int ny = y + yd[i];
                if (isInRange(nx, ny)) {
                    if (!visit[nx][ny] && board[nx][ny] == board[a][b]) {
                        visit[nx][ny] = true;
                        q.add(new int[]{nx, ny});
                        cnt++;
                        positions.add(new int[]{nx, ny});
                    }
                }
            }
        }
        if(cnt>=4){
            for (int[] position : positions) {
                board[position[0]][position[1]] = '.';
            }
        }
        return cnt;
    }

    static boolean isInRange(int x, int y) {
        return x >= 0 && x < N && y >= 0 && y < M;
    }
}