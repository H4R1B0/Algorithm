import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    static int[][] board = new int[101][101];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        String[] tmp = null;
        for (int i = 0; i < N; i++) {
            tmp = br.readLine().split(" ");
            int x = Integer.parseInt(tmp[1]);
            int y = Integer.parseInt(tmp[0]);
            fill(x, y);
        }
        int answer = 0;
        for (int i = 1; i <= 100; i++) {
            for (int j = 1; j <= 100; j++) {
                if (board[i][j] == 1)
                    answer++;
            }
        }
        System.out.println(answer);
    }

    static void fill(int x, int y) {
        for (int i = x; i < x + 10; i++) {
            for (int j = y; j < y + 10; j++) {
                board[i][j] = 1;
            }
        }
    }
}
