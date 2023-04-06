import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Main {
    static int N = 2;
    static final int MOD = 1000000;
    static int[][] matrix = {{1, 1}, {1, 0}};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long B = Long.parseLong(br.readLine());
        int[][] result = pow(matrix, B);
        System.out.println(result[1][0]);
    }

    static int[][] pow(int[][] A, long B) {
        if (B == 1L)
            return A;

        int[][] result = pow(A, B / 2);
        result = multiple(result, result);
        if (B % 2 == 1L)
            result = multiple(result, matrix);
        return result;
    }

    static int[][] multiple(int[][] m1, int[][] m2) {
        int[][] result = new int[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < N; k++) {
                    result[i][j] += ((long) m1[i][k] * (long) m2[k][j]) % MOD;
                    result[i][j] %= MOD;
                }
            }
        }
        return result;
    }
}