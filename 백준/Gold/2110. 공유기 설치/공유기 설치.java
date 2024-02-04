import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int C = Integer.parseInt(st.nextToken());
        int[] arr = new int[N];
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }
        Arrays.sort(arr);
        int left = 1;
        int right = arr[N - 1] - arr[0];
        int answer = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (isAble(arr, mid, C)) {
                answer = Math.max(answer, mid);
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        System.out.println(answer);
    }

    static boolean isAble(int[] arr, int mid, int C) {
        int cnt = 1;
        int prev = arr[0];
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] - prev >= mid) {
                cnt++;
                prev = arr[i];
            }
        }
        return cnt >= C;
    }
}