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
        M = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        arr = new int[N + 1];
        for (int i = 0; i < M; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        int left = 1;
        int right = N;
        int answer = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (isAble(mid)) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        System.out.println(answer);
    }

    static boolean isAble(int mid) {
        int end = 0;
        for (int i = 0; i < M; i++) {
            if (arr[i] - mid <= end) {
                end = arr[i] + mid;
            } else {
                return false;
            }
        }
        return N - end <= 0;
    }
}