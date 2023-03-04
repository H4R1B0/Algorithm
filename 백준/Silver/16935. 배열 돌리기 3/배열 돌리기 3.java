import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;

public class Main {
    //    static int N, M;
    static int[][] board;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] tmp = br.readLine().split(" ");
        int N = Integer.parseInt(tmp[0]);
        int M = Integer.parseInt(tmp[1]);
        int R = Integer.parseInt(tmp[2]);
        board = new int[N][M];
        for (int i = 0; i < N; i++) {
            board[i] = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        }
        int[] nums = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        for(int num : nums)
            rotate(num);
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                System.out.print(board[i][j] + " ");
            }
            System.out.println();
        }
    }

    static void rotate(int num) {
        if (num == 1) {
            rotate1();
        } else if (num == 2) {
            rotate2();
        } else if (num == 3) {
            rotate3();
        } else if (num == 4) {
            rotate4();
        } else if (num == 5) {
            rotate5();
        }
        else if (num == 6) {
            rotate6();
        }
    }

    static void rotate1() {
        int N = board.length;
        int M = board[0].length;
        int[][] tmp = new int[N][M];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                tmp[i][j] = board[N - 1 - i][j];
            }
        }
        writeBoard(tmp);
    }

    static void rotate2() {
        int N = board.length;
        int M = board[0].length;
        int[][] tmp = new int[N][M];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                tmp[i][j] = board[i][M - 1 - j];
            }
        }
        writeBoard(tmp);
    }

    static void rotate3() {
        int N = board.length;
        int M = board[0].length;
        int[][] tmp = new int[M][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
//                System.out.println(i+" "+j);
                tmp[j][N - 1 - i] = board[i][j];
            }
        }
        writeBoard(tmp);
    }

    static void rotate4() {
        int N = board.length;
        int M = board[0].length;
        int[][] tmp = new int[M][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
//                System.out.println(i+" "+j);
                tmp[M - 1 - j][i] = board[i][j];
            }
        }
        writeBoard(tmp);
    }

    static void rotate5() {

        int N = board.length / 2;
        int M = board[0].length / 2;
        int[][] tmp = new int[N][M];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                tmp[i][j] = board[i][j];
            }
        }
        for (int i = N; i < N * 2; i++) {
            for (int j = 0; j < M; j++) {
                board[i - N][j] = board[i][j];
            }
        }
        for (int i = N; i < N * 2; i++) {
            for (int j = M; j < M * 2; j++) {
                board[i][j - M] = board[i][j];
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = M; j < M * 2; j++) {
                board[i + N][j] = board[i][j];
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                board[i][j + M] = tmp[i][j];
            }
        }
//        writeBoard(tmp);
    }

    static void rotate6() {

        int N = board.length / 2;
        int M = board[0].length / 2;
        int[][] tmp = new int[N][M];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                tmp[i][j] = board[i][j];
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = M; j < M * 2; j++) {
                board[i][j - M] = board[i][j];
            }
        }
        for (int i = N; i < N * 2; i++) {
            for (int j = M; j < M * 2; j++) {
                board[i - N][j] = board[i][j];
            }
        }
        for (int i = N; i < N * 2; i++) {
            for (int j = 0; j < M; j++) {
                board[i][j + M] = board[i][j];
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                board[i + N][j] = tmp[i][j];
            }
        }
//        writeBoard(tmp);
    }

    static void writeBoard(int[][] tmp) {
        int N = tmp.length;
        int M = tmp[0].length;
        board = new int[N][M];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                board[i][j] = tmp[i][j];
            }
        }
    }
}
