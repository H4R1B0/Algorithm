import java.io.*;
import java.lang.reflect.Array;
import java.util.*;
import java.util.stream.Collectors;

public class Main {

    public static void main(String[] args) throws IOException {
        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        char[] str = br.readLine().toCharArray();
        int[] cnt = new int[2];
        for (int i = 0; i < str.length; i++) {
            cnt[str[i] - '0']++;
        }
        cnt[0]/=2;
        cnt[1]/=2;
        for (int i = 0; i < str.length; i++) {
            if (str[i] == '1' && cnt[1] > 0) {
                str[i] = '_';
                cnt[1]--;
            }
        }
        for (int i = str.length - 1; i >= 0; i--) {
            if (str[i] == '0' && cnt[0] > 0) {
                str[i] = '_';
                cnt[0]--;
            }
        }
        StringBuilder answer = new StringBuilder();
        for (int i = 0; i < str.length; i++) {
            if (str[i] != '_') {
                answer.append(str[i]);
            }
        }
        System.out.println(answer);
    }
}