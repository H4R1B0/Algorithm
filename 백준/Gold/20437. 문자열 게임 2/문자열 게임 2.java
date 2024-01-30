import java.io.*;
import java.lang.reflect.Array;
import java.util.*;
import java.util.stream.Collectors;

public class Main {

    public static void main(String[] args) throws IOException {
        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        int[] cnt = new int[26];
        while (T-- > 0) {
            char[] str = br.readLine().toCharArray();
            int K = Integer.parseInt(br.readLine());

            int left = 0, right = 0;
            Arrays.fill(cnt, 0);
            for (int i = 0; i < str.length; i++) {
                cnt[str[i] - 'a']++;
            }

            int[] answer = {Integer.MAX_VALUE, -1};

            for (int i = 0; i < str.length; i++) {
                if (cnt[str[i] - 'a'] < K) {
                    continue;
                }

                int k = 0;
                for (int j = i; j < str.length; j++) {
                    if (str[i] == str[j]) {
                        k++;
                    }
                    if (k == K) {
                        answer[0] = Math.min(answer[0], j - i + 1);
                        answer[1] = Math.max(answer[1], j - i + 1);
                        break;
                    }
                }
            }
            if (answer[0] == Integer.MAX_VALUE || answer[1] == -1) {
                System.out.println(-1);
            } else {
                System.out.println(answer[0] + " " + answer[1]);
            }
        }
    }
}