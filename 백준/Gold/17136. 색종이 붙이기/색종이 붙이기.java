import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int N = 10;
    static int[][] board = new int[10][10];
    static int[] squareCount = {0, 5, 5, 5, 5, 5};
    static boolean isFind = false;
    static int answer = Integer.MAX_VALUE;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        dfs(0);
        System.out.println(answer == Integer.MAX_VALUE ? -1 : answer);
    }

    static void dfs(int cnt) {
        if (cnt > answer)
            return;
        if (isOver()) {
            answer = Math.min(answer, cnt);
            return;
        }

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (board[i][j] == 1) {
                    for (int len = 5; len >= 1; len--) {
                        if (squareCount[len] > 0 && isInRange(i + len, j + len) && isSquare(i, j, len)) {
                            if (isSquare(i, j, len)) {
                                squareCount[len]--;
                                fill(i,j,len,0);
                                dfs(cnt + 1);
                                fill(i,j,len,1);
                                squareCount[len]++;
                            }
                        }
                    }
                    return;
                }
            }
        }
    }

    static void fill(int x, int y, int len, int num) {
        for (int i = x; i < x + len; i++) {
            for (int j = y; j < y + len; j++) {
                board[i][j] = num;
            }
        }
    }

    static boolean isSquare(int x, int y, int len) {
        for (int i = x; i < x + len; i++) {
            for (int j = y; j < y + len; j++) {
                if (board[i][j] == 0)
                    return false;
            }
        }
        return true;
    }

    static boolean isInRange(int x, int y) {
        return x <= N && y <= N;
    }

    static boolean isOver() {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (board[i][j] == 1)
                    return false;
            }
        }
        return true;
    }
}