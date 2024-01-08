import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.stream.Collectors;

public class Main {
    static int[][] dp;
    static char[] s;

    public static void main(String[] args) throws IOException {
        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        s = str.toCharArray();
        dp = new int[s.length][s.length];
        for (int l = 1; l < s.length; l++) {
            for (int i = 0; i + l < s.length; i++) {
                int j = i + l;
                if ((s[i] == 'a' && s[j] == 't') || (s[i] == 'g' && s[j] == 'c')) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }
                for (int k = i; k < j; k++) {
                    dp[i][j] = Math.max(dp[i][j], dp[i][k] + dp[k + 1][j]);
                }
            }
        }
        System.out.println(dp[0][s.length-1]);
    }
}