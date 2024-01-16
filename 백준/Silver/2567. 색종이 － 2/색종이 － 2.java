import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int[][] map = new int[110][110];

    public static void main(String[] args) throws IOException {
        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = null;
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            check(a, b);
        }

        int cnt = 0;
        for (int i = 1; i < 110; i++) {
            for (int j = 1; j < 100; j++) {
                if (map[i][j] == 1) {
                    if (map[i - 1][j] == 0) {
                        cnt++;
                    }
                    if (map[i + 1][j] == 0) {
                        cnt++;
                    }
                    if (map[i][j - 1] == 0) {
                        cnt++;
                    }
                    if (map[i][j + 1] == 0) {
                        cnt++;
                    }
                }
            }
        }
        System.out.println(cnt);
    }

    static void check(int a, int b) {
        for (int i = a; i < a + 10; i++) {
            for (int j = b; j < b + 10; j++) {
                map[i][j] = 1;
            }
        }
    }
}