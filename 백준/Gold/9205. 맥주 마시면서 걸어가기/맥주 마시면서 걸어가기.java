import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main {
    static int[][] points;
    static int[][] board;
    static int N;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            N = Integer.parseInt(br.readLine());
            points = new int[N + 2][2];
            for (int i = 0; i < N + 2; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                points[i][0] = Integer.parseInt(st.nextToken());
                points[i][1] = Integer.parseInt(st.nextToken());
            }
            System.out.println(getAnswer());
        }

    }

    static String getAnswer() {
        board = new int[N + 2][N + 2];
        for (int i = 0; i < N + 2; i++) {
            for (int j = 0; j < N + 2; j++) {
                if (i != j) {
                    if (check(i, j))
                        board[i][j] = 1;
                    else
                        board[i][j] = Integer.MAX_VALUE;
                }
            }
        }

        for (int k = 0; k < N + 2; k++) {
            for (int i = 0; i < N + 2; i++) {
                for (int j = 0; j < N + 2; j++) {
                    if (board[i][k] != Integer.MAX_VALUE && board[k][j] != Integer.MAX_VALUE) {
                        board[i][j] = Math.min(board[i][j], board[i][k] + board[k][j]);
                    }
                }
            }
        }
        if (board[0][N + 1] > 0 && board[0][N + 1] < Integer.MAX_VALUE)
            return "happy";
        return "sad";
    }

    static boolean check(int from, int to) {
        return (Math.abs(points[from][0] - points[to][0]) + Math.abs(points[from][1] - points[to][1])) <= 1000;
    }
}