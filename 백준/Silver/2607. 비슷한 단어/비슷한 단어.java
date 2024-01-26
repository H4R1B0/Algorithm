import java.io.*;
import java.lang.reflect.Array;
import java.util.*;
import java.util.stream.Collectors;

public class Main {

    public static void main(String[] args) throws IOException {
        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        String str = br.readLine();
        int[] strCnt = new int[26];
        for (int i = 0; i < str.length(); i++) {
            strCnt[str.charAt(i) - 'A']++;
        }

        int answer = 0;
        int[] check = new int[26];
        for (int i = 0; i < N - 1; i++) {
            String tmp = br.readLine();
            Arrays.fill(check, 0);
            for (int j = 0; j < tmp.length(); j++) {
                check[tmp.charAt(j) - 'A']++;
            }
            int diff = 0;
            for (int j = 0; j < 26; j++) {
                diff += Math.abs(strCnt[j] - check[j]);
            }
            if (diff <= 2 && Math.abs(str.length() - tmp.length()) <= 1) {
                answer++;

            }
        }
        System.out.println(answer);
    }
}