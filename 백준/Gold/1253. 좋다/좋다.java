import java.io.*;
import java.util.*;

public class Main {
    static int N;
    static StringBuilder answer = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[] arr = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).sorted().toArray();
        int answer = 0;
        for (int i = 0; i < N; i++) {
            int target = arr[i];
            int left = 0, right = N - 1;
            while (left < right) {
                if (arr[left] + arr[right] == target) {
                    if (left == i) {
                        left++;
                    } else if (right == i) {
                        right--;
                    } else {
                        answer++;
                        break;
                    }
                } else if (arr[left] + arr[right] > target) {
                    right--;
                } else if (arr[left] + arr[right] < target) {
                    left++;
                }
            }
        }
        System.out.println(answer);
    }
}