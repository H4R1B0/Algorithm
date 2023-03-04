import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    static StringBuilder answer = new StringBuilder();

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                dfs(N, i, j);
            }
            answer.append("\n");
        }
        System.out.println(answer);
    }

    static void dfs(int N, int x, int y) {
        if ((x / N) % 3 == 1 && (y / N) % 3 == 1) {
            answer.append(" ");
            return;
        }
        if (N == 1) {
            answer.append("*");
            return;
        }
        dfs(N / 3, x, y);
    }
}