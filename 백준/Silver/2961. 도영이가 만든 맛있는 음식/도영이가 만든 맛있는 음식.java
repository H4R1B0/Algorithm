import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Main {
    static int N;
    static int[][] board;
    static int answer = Integer.MAX_VALUE;
    static List<Integer> taste1 = new ArrayList<>();
    static List<Integer> taste2 = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        String[] tmp;
        for (int i = 0; i < N; i++) {
            tmp = br.readLine().split(" ");
            taste1.add(Integer.parseInt(tmp[0]));
            taste2.add(Integer.parseInt(tmp[1]));
        }
        dfs(0, 1, 0);
        System.out.println(answer);
    }

    static void dfs(int cnt, int multi, int sum) {
        if (cnt == N) {
            if(multi ==1 || sum==0)
                return;
            answer = Math.min(answer, Math.abs(multi - sum));
            return;
        }
        dfs(cnt + 1, multi * taste1.get(cnt), sum + taste2.get(cnt));
        dfs(cnt + 1, multi, sum);
    }
}