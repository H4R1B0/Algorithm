import java.io.*;
import java.lang.reflect.Array;
import java.util.*;
import java.util.stream.Collectors;

public class Main {

    public static void main(String[] args) throws IOException {
        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        int[] arr = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        int[] cnt = new int[100001];
        int left = 0;
        int right = 0;
        int answer = 0;
        while (right < N) {
            if (cnt[arr[right]] < K) {
                cnt[arr[right]]++;
                right++;
            } else {
                cnt[arr[left]]--;
                left++;
            }
            answer = Math.max(answer, right - left);
        }
        System.out.println(answer);
    }
}