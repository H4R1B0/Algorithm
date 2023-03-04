import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    static int cnt = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] tmp = br.readLine().split(" ");
        int N = Integer.parseInt(tmp[0]);
        int r = Integer.parseInt(tmp[1]);
        int c = Integer.parseInt(tmp[2]);
        System.out.println(dfs(N, r, c));
    }

    static int dfs(int N, int r, int c) {
        if (N == 0)
            return 0;
        return 2 * (r % 2) + (c % 2) + 4 * dfs(N - 1, r / 2, c / 2);
    }
}