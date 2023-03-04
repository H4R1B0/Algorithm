import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;

public class Main {
    static long answer = 0;
    static long M;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] tmp = br.readLine().split(" ");
        long N = Long.parseLong(tmp[0]);
        M = Long.parseLong(tmp[1]);
        long left = 1, right = -1;
        List<Long> arr = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            long num = Long.parseLong(br.readLine());
            right = Math.max(right, num);
            arr.add(num);
        }
        dfs(arr, right, left, right);
        System.out.println(answer);
    }

    static void dfs(List<Long> arr, long mid, long left, long right) {
//        System.out.println(mid);
        if (left > right)
            return;
        mid = (left + right) / 2;
        if (getCount(arr, mid) >= M) {
            answer = Math.max(answer, mid);
            dfs(arr, mid, mid + 1, right);
        } else {
            dfs(arr, mid, left, mid - 1);
        }
    }

    static long getCount(List<Long> arr, long num) {
        long cnt = 0;
        for (long a : arr) {
            cnt += a / num;
        }
        return cnt;
    }
}