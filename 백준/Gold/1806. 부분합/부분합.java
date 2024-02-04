import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int S = Integer.parseInt(st.nextToken());
        int[] arr = new int[N];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            int num = Integer.parseInt(st.nextToken());
            arr[i] = num;
        }
        int left = 0;
        int right = 0;
        int sum = arr[0];
        int answer = Integer.MAX_VALUE;
        while (true) {
            if (sum < S) {
                if (right == N-1) {
                    break;
                }
                sum += arr[++right];
            } else {
                answer = Math.min(answer, right - left + 1);
                sum -= arr[left++];
            }
        }
        System.out.println(answer == Integer.MAX_VALUE ? 0 : answer);
    }
}