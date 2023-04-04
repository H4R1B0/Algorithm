import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
    static int N, M, answer;
    static int[][] board;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        for (int test_case = 1; test_case <= T; test_case++) {
            answer = 0;
            N = Integer.parseInt(br.readLine());
            M = Integer.parseInt(br.readLine());
            board = new int[N][N];
            for (int i = 0; i < M; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                int a = Integer.parseInt(st.nextToken()) - 1;
                int b = Integer.parseInt(st.nextToken()) - 1;
                board[a][b] = 1;
                board[b][a] = -1;
            }
            floyd();

            
            for (int i = 0; i < N; i++) {
                int cnt = 0;
                for (int j = 0; j < N; j++) {
                    if (board[i][j] != 0)
                        cnt++;
                }
                if (cnt == N - 1)
                    answer++;
            }
            System.out.printf("#%d %d\n", test_case, answer);
        }
    }

    static void floyd() {
        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (board[i][k] == 1 && board[k][j] == 1) {
                        board[i][j] = 1;
                        board[j][i] = -1;
                    }
                }
            }
        }
    }
}