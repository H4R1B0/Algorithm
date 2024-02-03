import java.io.*;
import java.util.*;

public class Main {
    static boolean[][] status = {{true, true, true, false, true, true, true},
        {false, false, true, false, false, false, true},
        {false, true, true, true, true, true, false},
        {false, true, true, true, false, true, true},
        {true, false, true, true, false, false, true},
        {true, true, false, true, false, true, true},
        {true, true, false, true, true, true, true},
        {false, true, true, false, false, false, true},
        {true, true, true, true, true, true, true},
        {true, true, true, true, false, true, true}
    };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        int P = Integer.parseInt(st.nextToken());
        int X = Integer.parseInt(st.nextToken());

        int answer = 0;
        for (int i = 1; i <= N; i++) {
            if (i == X) {
                continue;
            }
            int cnt = 0;
            int from = X, to = i;
            for (int k = 0; k < K; k++) {
                for (int idx = 0; idx < 7; idx++) {
                    if (status[from % 10][idx] != status[to % 10][idx]) {
                        cnt++;
                    }
                }
                from /= 10;
                to /= 10;
            }
            if (cnt <= P) {
                answer++;
            }
        }
        System.out.println(answer);
    }
}