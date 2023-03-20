import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int[] xd = {0, 0, 1, -1};
    static int[] yd = {1, -1, 0, 0};
    static int N, M;
    static int[][] board, resultBoard;
    static boolean[][] visit;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        board = new int[N][M];
        resultBoard = new int[N][M];
        visit = new boolean[N][M];

        for (int i = 0; i < N; i++) {
            board[i] = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        }
        for (int i = 0; i < N; i++) {
            resultBoard[i] = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        }
        System.out.println(getAnswer());
    }

    static String getAnswer() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (board[i][j] != resultBoard[i][j]) {
                    if (!bfs(i, j, resultBoard[i][j]))
                        return "NO";
                }
            }
        }
        return "YES";
    }

    static boolean bfs(int a, int b, int num) {
        List<int[]> positions = new ArrayList<>();
        positions.add(new int[]{a, b});
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{a, b});
        visit[a][b] = true;
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
                        positions.add(new int[]{nx, ny});
                    }
                }
            }
        }

        for (int[] position : positions) {
            board[position[0]][position[1]] = num;
        }
        return isMatch();
    }

    static boolean isMatch() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (board[i][j] != resultBoard[i][j])
                    return false;
            }
        }
        return true;
    }

    static boolean isInRange(int x, int y) {
        return x >= 0 && x < N && y >= 0 && y < M;
    }
}