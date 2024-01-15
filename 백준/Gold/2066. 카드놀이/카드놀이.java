import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static String[][] card = new String[10][5];
    static Map<List<Integer>, Double> cache = new HashMap<>();

    public static void main(String[] args) throws IOException {
        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;
        for (int i = 1; i <= 9; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= 4; j++) {
                card[i][j] = st.nextToken();
            }
        }
        List<Integer> start = new ArrayList<>(10);
        for (int i = 0; i < 10; i++) {
            start.add(4);
        }
        System.out.printf("%.6f", dfs(start));
    }

    static boolean check(List<Integer> l) {
        for (int i = 1; i < 10; i++) {
            if (l.get(i) != 0) {
                return false;
            }
        }
        return true;
    }

    static double dfs(List<Integer> now) {
        if (check(now)) {
            return 1.0;
        }

        if (cache.containsKey(now)) {
            return cache.get(now);
        }

        double answer = 0.0;

        List<int[]> select = new ArrayList<>();
        for (int i = 1; i < 10; i++) {
            for (int j = i + 1; j < 10; j++) {
                if (now.get(i) != 0 && now.get(j) != 0 && card[i][now.get(i)].charAt(0) == card[j][now.get(j)].charAt(0)) {
                    select.add(new int[]{i, j});
                }
            }
        }
        if (select.isEmpty()) {
            cache.put(now, 0.0);
            return cache.get(now);
        }
        for (int[] s : select) {
            int idx1 = s[0];
            int idx2 = s[1];
            List<Integer> next = new ArrayList<>(now);
            next.set(idx1, next.get(idx1) - 1);
            next.set(idx2, next.get(idx2) - 1);
            answer += dfs(next) * (1.0 / select.size());
        }
        cache.put(now, answer);
        return cache.get(now);
    }

}