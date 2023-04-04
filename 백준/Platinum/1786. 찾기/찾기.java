import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main {
    static int N, M;
    static char[] text, pattern;
    static int[] pi;
    static List<Integer> answer = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        text = br.readLine().toCharArray();
        N = text.length;
        pattern = br.readLine().toCharArray();
        M = pattern.length;

        makePi();
        setAnswer();
        System.out.println(answer.size());
        for (int ans : answer)
            System.out.print(ans + " ");
    }

    static void makePi() {
        pi = new int[M];

        for (int i = 1, j = 0; i < M; i++) {
            while (j > 0 && pattern[i] != pattern[j]) {
                j = pi[j - 1];
            }
            if (pattern[i] == pattern[j]) {
                pi[i] = ++j;
            }
        }
    }

    static void setAnswer() {
        for (int i = 0, j = 0; i < N; i++) {
            while (j > 0 && text[i] != pattern[j]) {
                j = pi[j - 1];
            }

            if (text[i] == pattern[j]) {
                if (j == M - 1) {
                    answer.add(i - j + 1);
                    j = pi[j];
                } else {
                    j++;
                }
            }
        }
    }
}