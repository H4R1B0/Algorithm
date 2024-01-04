import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    private static int N, M, answer = Integer.MAX_VALUE;
    private static int[] num;

    public static void main(String[] args) throws IOException {
        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(br.readLine());
        num = new int[M];
        for (int i = 0; i < M; i++) {
            num[i] = Integer.parseInt(br.readLine());
        }

        dfs(a, b, 0, 0);
        System.out.println(answer);
    }

    private static void dfs(int open1, int open2, int idx, int cnt) {
        if (idx == M) {
            answer = Math.min(answer, cnt);
            return;
        }

        int left = Math.abs(open1 - num[idx]);
        int right = Math.abs(open2 - num[idx]);

        dfs(num[idx], open2, idx + 1, cnt + left);
        dfs(open1, num[idx], idx + 1, cnt + right);
    }
}