import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;
import java.io.FileInputStream;

class Solution {
    static int N, M, C, answer;
    static int[][] board, profit;

    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());

        for (int test_case = 1; test_case <= T; test_case++) {
            // N, M, C 입력
            String[] input = br.readLine().split(" ");
            N = Integer.parseInt(input[0]);
            M = Integer.parseInt(input[1]);
            C = Integer.parseInt(input[2]);
            // 맵 입력
            board = new int[N][N];
            profit = new int[N][N];
            for (int i = 0; i < N; i++) {
                board[i] = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            }
            // 이익 계산
            profitCalculate();
            // 정답 계산
            answer = 0;
            getAnswer(0, 0, 0, 0);
            System.out.printf("#%d %d\n", test_case, answer);
        }
    }

    // 맵 전체에서 이익들 계산
    static void profitCalculate() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j <= N - M; j++) {
                setProfit(i, j, 0, 0, 0);
            }
        }
    }

    // 부분 집합으로 이익 계산
    static void setProfit(int x, int y, int cnt, int sum, int total) {
        if (sum > C)
            return;
        if (cnt == M) {
            profit[x][y - M] = Math.max(profit[x][y - M], total);
            return;
        }

        setProfit(x, y + 1, cnt + 1, sum + board[x][y], total + board[x][y] * board[x][y]);
        setProfit(x, y + 1, cnt + 1, sum, total);
    }

    // 두 사람 선택으로 값 계산
    static void getAnswer(int x, int y, int cnt, int sum) {
        if (cnt == 2) {
            answer = Math.max(answer, sum);
            return;
        }

        for (int i = x; i < N; i++) {
            for (int j = y; j <= N - M; j++) {
                getAnswer(i, j + M, cnt + 1, sum + profit[i][j]);
            }
            y=0;
        }
    }
}