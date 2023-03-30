import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int[][] board = new int[9][9];
    static boolean[] used = new boolean[10];
    static Main.Pos[] positions;
    static StringBuilder answer = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        List<Main.Pos> tmp = new ArrayList<>();
        for (int i = 0; i < 9; i++) {
            char[] str = br.readLine().toCharArray();
            for (int j = 0; j < 9; j++) {
                int num = str[j] - '0';
                board[i][j] = num;
                if (num == 0) {
                    tmp.add(new Main.Pos(i, j));
                }
            }
        }
        positions = tmp.toArray(new Main.Pos[tmp.size()]);
        dfs(0, positions.length);
//        System.out.println(answer);
    }

    static void dfs(int cnt, final int N) {
        if (!answer.toString().equals(""))
            return;
        if (cnt == N) {
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    answer.append(board[i][j]);
                }
                answer.append("\n");
            }
            System.out.println(answer);
            System.exit(0);
        }

        for (int num = 1; num < 10; num++) {
            int x = positions[cnt].x;
            int y = positions[cnt].y;

            if (board[x][y] == 0) {
                board[x][y] = num;
                if (isValid(x, y)) {
                    dfs(cnt + 1, N);
                }
                board[x][y] = 0;
            }
        }
    }

    static boolean isValid(int x, int y) {
        if (!isValidRow(x) || !isValidCol(y) || !isValidSquare(x, y))
            return false;
        return true;
    }

    static boolean isValidRow(int x) {
        Arrays.fill(used, false);
        for (int i = 0; i < 9; i++) {
            if (board[x][i] == 0)
                continue;
            if (used[board[x][i]])
                return false;
            used[board[x][i]] = true;
        }
        return true;
    }

    static boolean isValidCol(int y) {
        Arrays.fill(used, false);
        for (int i = 0; i < 9; i++) {
            if (board[i][y] == 0)
                continue;
            if (used[board[i][y]])
                return false;
            used[board[i][y]] = true;
        }
        return true;
    }

    static boolean isValidSquare(int x, int y) {
        Arrays.fill(used, false);
        for (int i = x / 3 * 3; i < (x / 3 + 1) * 3; i++) {
            for (int j = y / 3 * 3; j < (y / 3 + 1) * 3; j++) {
                if (board[i][j] == 0)
                    continue;
                if (used[board[i][j]])
                    return false;
                used[board[i][j]] = true;
            }
        }
        return true;
    }

    static class Pos {
        int x, y;

        Pos(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}