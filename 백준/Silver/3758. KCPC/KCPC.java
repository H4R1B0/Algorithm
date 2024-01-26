import java.io.*;
import java.lang.reflect.Array;
import java.util.*;
import java.util.stream.Collectors;

public class Main {

    public static void main(String[] args) throws IOException {
        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        StringTokenizer st = null;
        StringBuilder answer = new StringBuilder();
        while (T-- > 0) {
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int k = Integer.parseInt(st.nextToken());
            int t = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());

            Team[] teams = new Team[n];
            for (int i = 0; i < m; i++) {
                st = new StringTokenizer(br.readLine());
                int id = Integer.parseInt(st.nextToken());
                int num = Integer.parseInt(st.nextToken());
                int score = Integer.parseInt(st.nextToken());
                if (teams[id - 1] == null) {
                    teams[id - 1] = new Team();
                    teams[id - 1].id = id;
                    teams[id - 1].scores = new int[k + 1];
                }
                teams[id - 1].scores[num] = Math.max(score, teams[id - 1].scores[num]);
                teams[id - 1].submitCnt++;
                teams[id - 1].lastSubmit = i;
            }

            for (int i = 0; i < n; i++) {
                int sum = 0;
                for (int j = 1; j <= k; j++) {
                    sum += teams[i].scores[j];
                }
                teams[i].sum = sum;
            }
            Arrays.sort(teams, (o1, o2) -> {
                if (o2.sum == o1.sum) {
                    if (o1.submitCnt == o2.submitCnt) {
                        return o1.lastSubmit - o2.lastSubmit;
                    }
                    return o1.submitCnt - o2.submitCnt;
                }
                return o2.sum - o1.sum;
            });
            for (int i = 0; i < n; i++) {
                if (teams[i].id == t) {
                    answer.append(i + 1).append('\n');
                }
            }
        }
        System.out.println(answer);
    }

    static class Team {
        int id, submitCnt, lastSubmit, sum;
        int[] scores;
    }
}