import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static final int[] team1 = {0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 3, 3, 4};
    static final int[] team2 = {1, 2, 3, 4, 5, 2, 3, 4, 5, 3, 4, 5, 4, 5, 5};
    static int[][] result = new int[6][3];

    static int[][] score = new int[6][3];
    static boolean answer = false;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        A:
        for (int i = 0; i < 4; i++) {
            answer = false;
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < 6; j++) {
                result[j][0] = Integer.parseInt(st.nextToken());
                result[j][1] = Integer.parseInt(st.nextToken());
                result[j][2] = Integer.parseInt(st.nextToken());
                if (result[j][0] + result[j][1] + result[j][2] != 5) {
                    sb.append(0).append(" ");
                    continue A;
                }
            }
            dfs(0);
            sb.append(answer ? 1 : 0).append(" ");
        }
        System.out.println(sb);
    }

    static void dfs(int round) {
        if (round == 15) {
            answer = true;
            return;
        }

        int a = team1[round];
        int b = team2[round];


        if (score[a][0] < result[a][0] && score[b][2] < result[b][2]) {
            score[a][0]++;
            score[b][2]++;
            dfs(round + 1);
            score[a][0]--;
            score[b][2]--;
        }

        if (score[a][1] < result[a][1] && score[b][1] < result[b][1]) {
            score[a][1]++;
            score[b][1]++;
            dfs(round + 1);
            score[a][1]--;
            score[b][1]--;
        }

        if (score[a][2] < result[a][2] && score[b][0] < result[b][0]) {
            score[a][2]++;
            score[b][0]++;
            dfs(round + 1);
            score[a][2]--;
            score[b][0]--;
        }
    }
}