import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int N, M;
    static int[] arr = new int[3];
    static int[][] growBoard, diffBoard;

    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        M = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());

        growBoard = new int[M][M];
        for (int i = 0; i < M; i++) {
            Arrays.fill(growBoard[i], 1);
        }
        diffBoard = new int[M][M];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            arr[0] = Integer.parseInt(st.nextToken());
            arr[1] = Integer.parseInt(st.nextToken());
            arr[2] = Integer.parseInt(st.nextToken());
            grow();
//            System.out.println("----");
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < M; j++) {
                sb.append(growBoard[i][j]).append(" ");
            }
            sb.append("\n");
        }
        System.out.println(sb.toString());
    }

    static void grow() {
        //가장자리 성장
        for (int d = 0, x = M - 1, y = 0; d < 2 * M - 1; d++) {
//            System.out.println(x+" "+ y);
            for (int i = 0; i < 3; i++) {
                if (arr[i] > 0) {
                    growBoard[x][y] += i;
                    diffBoard[x][y] = i;
                    arr[i]--;
                    break;
                }
            }
            //좌표 이동
            if (x == 0)
                y++;
            else
                x--;
        }
        //나머지 성장
        int idx = 1;
//        int x = idx, y = idx;
        for (int dist = M - 2; dist >= 0; dist--) {
            int x = idx, y = idx;
            int num = maxDiff(x, y);
            growBoard[x][y] += num;
            diffBoard[x][y] = num;

            for (int i = 1; i <= dist; i++) {
                num = maxDiff(x + i, y);
                growBoard[x + i][y] += num;
                diffBoard[x + i][y] = num;

                num = maxDiff(x, y + i);
                growBoard[x][y + i] += num;
                diffBoard[x][y + i] = num;
            }
            idx++;
        }
//        System.out.println("-----");
    }

    static int maxDiff(int x, int y) {
        return Math.max(Math.max(diffBoard[x - 1][y - 1], diffBoard[x - 1][y]), diffBoard[x][y - 1]);
    }

}