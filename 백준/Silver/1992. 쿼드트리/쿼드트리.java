import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    static char[][] board;
    static int N;
    static StringBuilder answer = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        board = new char[N][N];
        for (int i = 0; i < N; i++) {
            board[i] = br.readLine().toCharArray();
        }
        divide(0, 0, N);
        System.out.println(answer);
    }

    static void divide(int r, int c, int size) {
        int sum = 0;
        for (int i = r; i < r + size; i++) {
            for (int j = c; j < c + size; j++) {
                sum += (board[i][j] - '0');
            }
        }
        if (sum == size * size) {
            answer.append(1);
        } else if (sum == 0) {
            answer.append(0);
        } else {
            answer.append('(');
            divide(r, c, size / 2);
            divide(r, c + size / 2, size / 2);
            divide(r + size / 2, c, size / 2);
            divide(r + size / 2, c + size / 2, size / 2);
            answer.append(')');
        }
    }
}