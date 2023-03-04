import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    static int N;
    static StringBuilder answer = new StringBuilder();

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        System.out.println((int) Math.pow(2, N) - 1);

        dfs(N, 1, 3);
        System.out.println(answer);
    }

    static void dfs(int cnt, int from, int to) {
        if (cnt == 1) {
            answer.append(from + " " + to+"\n");
            return;
        }
        dfs(cnt - 1, from, 6 - from - to);
        answer.append(from + " " + to+"\n");
        dfs(cnt - 1, 6 - from - to, to);
    }
}