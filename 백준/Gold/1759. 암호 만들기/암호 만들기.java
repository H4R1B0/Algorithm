import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static int L, C;
    static char[] words;
    static char[] word;
    static StringBuilder answer = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        L = Integer.parseInt(input[0]);
        C = Integer.parseInt(input[1]);
        input = br.readLine().split(" ");
        words = new char[C];
        word = new char[L];
        for (int i = 0; i < input.length; i++)
            words[i] = input[i].charAt(0);
        Arrays.sort(words);
        dfs(0, 0, 0, 0);
        System.out.println(answer);
    }

    static void dfs(int idx, int cnt, int p, int c) {
        if (cnt == L) {
            if(p<1 || c<2)
                return;
            for (int i = 0; i < L; i++) {
                answer.append(word[i]);
            }
            answer.append('\n');
            return;
        }

        for (int i = idx; i < C; i++) {
            word[cnt] = words[i];
            if (isParent(i))
                dfs(i + 1, cnt + 1, p + 1, c);
            else
                dfs(i + 1, cnt + 1, p, c + 1);
        }
    }

    static boolean isParent(int x) {
        return words[x] == 'a' || words[x] == 'e' || words[x] == 'o' || words[x] == 'u' || words[x] == 'i';
    }
}