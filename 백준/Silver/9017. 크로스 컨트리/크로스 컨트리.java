import java.io.*;
import java.lang.reflect.Array;
import java.util.*;
import java.util.stream.Collectors;

public class Main {

    public static void main(String[] args) throws IOException {
        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        int[] cnt = new int[201];
        int[] arr = new int[1001];
        List<Integer>[] teams = new ArrayList[201];
        for (int i = 0; i < 201; i++) {
            teams[i] = new ArrayList<Integer>();
        }
        int[] answer = new int[2];
        StringTokenizer st = null;
        while (T-- > 0) {
            Arrays.fill(cnt, 0);
            for (int i = 0; i < 201; i++) {
                teams[i].clear();
            }
            int min = Integer.MAX_VALUE;

            int N = Integer.parseInt(br.readLine());
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < N; i++) {
                arr[i] = Integer.parseInt(st.nextToken());
                cnt[arr[i]]++;
            }
//            System.out.println(Arrays.toString(cnt));
            int score = 1;
            for (int i = 0; i < N; i++) {
                int num = arr[i];
                if (cnt[num] != 6) {
                    continue;
                }
                teams[num].add(score++);
            }

            for (int i = 1; i < 201; i++) {
                if (cnt[i] != 6) {
                    continue;
                }
                int sum = 0;
                for (int j = 0; j < 4; j++) {
                    sum += teams[i].get(j);
                }
                if (min > sum) {
                    min = sum;
                    answer[0] = i;
                    answer[1] = teams[i].get(4);
                } else if (min == sum && answer[1] > teams[i].get(4)) {
                    answer[0] = i;
                    answer[1] = teams[i].get(4);
                }
            }
            System.out.println(answer[0]);
        }
    }
}