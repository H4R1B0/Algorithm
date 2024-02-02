import java.io.*;
import java.util.*;

public class Main {
    static int N, idx;
    static int[] nums, answer;
    static boolean[] visit;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        nums = new int[N + 1];
        answer = new int[N];
        visit = new boolean[N + 1];
        for (int i = 1; i <= N; i++) {
            nums[i] = Integer.parseInt(br.readLine());
        }
        for (int i = 1; i <= N; i++) {
            int num = nums[i];
            Arrays.fill(visit, false);
            dfs(i, i);
        }
        System.out.println(idx);
        for (int i = 0; i < idx; i++) {
            System.out.println(answer[i]);
        }
    }

    static void dfs(int start, int end) {
        if (visit[start]) {
            if (start == end) {
                answer[idx++] = end;
            }
            return;
        } else {
            visit[start] = true;
            dfs(nums[start], end);
        }
    }
}