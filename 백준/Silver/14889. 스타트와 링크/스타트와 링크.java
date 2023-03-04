import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;

class Main {
    static int N;
    static int answer = 987654321;
    static int[][] board;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        board = new int[N][N];
        for (int i = 0; i < N; i++) {
            board[i] = Arrays.asList(br.readLine().split(" ")).stream().mapToInt(Integer::parseInt).toArray();
        }

        dfs(new int[N / 2], 0, new int[N / 2], 0);
        System.out.println(answer);
    }

    static int getSum(int[] arr) {
        int sum = 0;
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr.length; j++) {
                if (i != j) {
                    sum += board[arr[i]][arr[j]];
                }
            }
        }
        return sum;
    }

    static void dfs(int[] left, int leftCnt, int[] right, int rightCnt) {
        if (leftCnt + rightCnt == N) {
            answer = Math.min(answer, Math.abs(getSum(left) - getSum(right)));
            return;
        }

        if (leftCnt < N / 2) {
            left[leftCnt] = leftCnt + rightCnt;
            dfs(left, leftCnt + 1, right, rightCnt);
        }
        if (rightCnt < N / 2) {
            right[rightCnt] = leftCnt + rightCnt;
            dfs(left, leftCnt, right, rightCnt + 1);
        }
    }
}