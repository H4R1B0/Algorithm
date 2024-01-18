import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;

public class Main {

    public static void main(String[] args) throws IOException {
        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int K = Integer.parseInt(br.readLine());
        Set<Integer>[] set = new HashSet[9];
        for (int i = 1, num = 0; i <= 8; i++) {
            set[i] = new HashSet<>();
            num = num * 10 + K;
            set[i].add(num);
        }

        for (int i = 1; i <= 8; i++) {
            for (int j = 1; j <= i; j++) {
                int cnt = i + j;
                if (cnt > 8) {
                    continue;
                }

                for (int a : set[i]) {
                    for (int b : set[j]) {
                        set[cnt].add(a + b);
                        set[cnt].add(a * b);
                        set[cnt].add(Math.max(a, b) / Math.min(a, b));
                        if (a != b) {
                            set[cnt].add(Math.abs(a - b));
                        }
                    }
                }
            }


        }
        int N = Integer.parseInt(br.readLine());
        while (N-- > 0) {
            int n = Integer.parseInt(br.readLine());
            int answer = -1;
            for (int i = 1; i <= 8; i++) {
                if (set[i].contains(n)) {
                    answer = i;
                    break;
                }
            }
            System.out.println(answer == -1 ? "NO" : answer);
        }
    }
}