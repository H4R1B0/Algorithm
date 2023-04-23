import java.io.*;
import java.util.*;

public class Main {
    static int[] pi;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while (true) {
            String word = br.readLine();
            if (word.equals("."))
                break;

            makePi(word);
//            System.out.println(Arrays.toString(pi));
            int num = word.length() - pi[word.length() - 1];
            if (word.length() % num != 0)
                System.out.println(1);
            else
                System.out.println(word.length() / num);
        }
    }

    static void makePi(String word) {
        pi = new int[word.length()];

        for (int i = 1, j = 0; i < word.length(); i++) {
            while (j > 0 && word.charAt(i) != word.charAt(j)) {
                j = pi[j - 1];
            }
            if (word.charAt(i) == word.charAt(j)) {
                pi[i] = ++j;
            }
        }
    }
}