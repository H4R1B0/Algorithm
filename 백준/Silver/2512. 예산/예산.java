import java.io.*;
import java.lang.reflect.Array;
import java.util.*;
import java.util.stream.Collectors;

public class Main {
    static int N, M;
    static int[] arr;

    public static void main(String[] args) throws IOException {
        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        arr = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        M = Integer.parseInt(br.readLine());

        int left = 1;
        int right = Arrays.stream(arr).max().getAsInt();
        int answer = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (isAble(mid)) {
                left = mid + 1;
                answer = mid;
            } else {
                right = mid - 1;
            }
        }
        System.out.println(answer);
    }

    static boolean isAble(int mid) {
        int sum = 0;
        for (int i = 0; i < N; i++) {
            sum += Math.min(arr[i], mid);
        }
        return sum <= M;
    }
}