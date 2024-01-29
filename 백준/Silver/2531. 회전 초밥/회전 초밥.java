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
        int d = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());

        int[] arr = new int[N];
        int[] cnt = new int[d + 1];
        for (int i = 0; i < N; i++) {
            int num = Integer.parseInt(br.readLine());
            arr[i] = num;
        }

        int total = 0;
        for (int i = 0; i < k; i++) {
            int num = arr[i];
            if (cnt[num] == 0) {
                total++;
            }
            cnt[num]++;
        }
        int answer = total;
        if (cnt[c] == 0) {
            answer++;
        }
        for (int i = 1; i < N; i++) {
            int end = (i + k - 1) % N;
            if (cnt[arr[end]] == 0) {
                total++;
            }
            cnt[arr[end]]++;

            cnt[arr[i - 1]]--;
            if (cnt[arr[i - 1]] == 0) {
                total--;
            }

            if (answer <= total) {
                if (cnt[c] == 0) {
                    answer = total + 1;
                    answer = Math.max(answer, total + 1);
                } else {
                    answer = total;
                }
            }
        }

        System.out.println(answer);
    }
}