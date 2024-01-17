import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.*;

public class Main {
    static int N, M, K;
    static int[] parent = new int[1001];
    static List<int[]>[] bridges = new ArrayList[2];

    public static void main(String[] args) throws IOException {
        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        char[] str = br.readLine().toCharArray();
        SortedSet<Character> set = new TreeSet<>();
        for (char s : str) {
            set.add(s);
        }
        List<Character> alphabets = new ArrayList<>(set);
        int[] alphabetLeft = new int[alphabets.size()];
        Arrays.fill(alphabetLeft, Integer.MAX_VALUE);
        int[] alphabetRight = new int[alphabets.size()];

        for (int i = 0; i < str.length; i++) {
            int idx = alphabets.indexOf(str[i]);
            alphabetLeft[idx] = Math.min(i, alphabetLeft[idx]);
            alphabetRight[idx] = Math.max(i, alphabetRight[idx]);
        }

        int[][] dp = new int[alphabets.size()][2];
        int left = alphabetLeft[0];
        int right = alphabetRight[0];
        int distance = right - left;
        dp[0][0] = left + distance;
        dp[0][1] = right + distance;

        for (int i = 1; i < alphabets.size(); i++) {
            int prevLeft = alphabetLeft[i - 1];
            int prevRight = alphabetRight[i - 1];
            left = alphabetLeft[i];
            right = alphabetRight[i];
            distance = right - left;

            dp[i][0] = Math.min(dp[i - 1][0] + Math.abs(prevRight - left), dp[i - 1][1] + Math.abs(prevLeft - left)) + distance;
            dp[i][1] = Math.min(dp[i - 1][0] + Math.abs(prevRight - right), dp[i - 1][1] + Math.abs(prevLeft - right)) + distance;
        }

        System.out.println(Math.min(dp[alphabets.size()-1][0], dp[alphabets.size() - 1][1]) + str.length);
    }
}