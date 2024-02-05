import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[] arr = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();

        long answer = 0;
        boolean[] visit = new boolean[100001];
        for (int left = 0, right = 0; left < N; left++) {
            while (right < N) {
                if (visit[arr[right]]) {
                    break;
                }
                visit[arr[right]] = true;
                right++;
            }
            answer += (right - left);
            visit[arr[left]] = false;
        }
        System.out.println(answer);
    }
}