import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[] arr = new int[N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        int sum = 0;
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
            sum += arr[i];
        }
        int[][][][] dp = new int[81][81][81][81];
        dp[0][0][0][0] = 1;
        List<int[]> list = new ArrayList<>();
        for (int idx = 0; idx < N; idx++) {
            int x = arr[idx];
            list.clear();
            for (int i = 0; i <= sum; i++) {
                for (int j = i; i + j <= sum; j++) {
                    for (int k = 0; k <= sum; k++) {
                        for (int l = k; k + l <= sum; l++) {
                            if ((j + l) * 2 > sum) {
                                continue;
                            }
                            if (dp[i][j][k][l] != 0) {
                                continue;
                            }

                            if (i >= x && dp[i - x][j][k][l] != 0) {
                                list.add(new int[]{i, j, k, l});
                            } else if (j >= x && dp[Math.min(i, j - x)][Math.max(i, j - x)][k][l] != 0) {
                                list.add(new int[]{i, j, k, l});
                            } else if (k >= x && dp[i][j][k - x][l] != 0) {
                                list.add(new int[]{i, j, k, l});
                            } else if (l >= x && dp[i][j][Math.min(k, l - x)][Math.max(k, l - x)] != 0) {
                                list.add(new int[]{i, j, k, l});
                            }
                        }
                    }
                }
            }
            for (int[] l : list) {
                dp[l[0]][l[1]][l[2]][l[3]] = 1;
            }
        }
        int answer = 0;
        for (int i = 1; i <= 80; i++) {
            for (int j = 1; j <= 80; j++) {
                if (dp[i][i][j][j] != 0) {
                    answer = Math.max(answer, i * j);
                }
            }
        }
        System.out.println(answer != 0 ? answer : -1);
    }
}