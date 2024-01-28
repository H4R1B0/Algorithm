import java.io.*;
import java.lang.reflect.Array;
import java.util.*;
import java.util.stream.Collectors;

public class Main {

    public static void main(String[] args) throws IOException {
        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        char[] balls = br.readLine().toCharArray();
        int redCnt = 0, blueCnt = 0;
        for (int i = 0; i < N; i++) {
            if (balls[i] == 'R') {
                redCnt++;
            } else {
                blueCnt++;
            }
        }
        int answer = Math.min(redCnt, blueCnt);
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            if (balls[i] != balls[0]) {
                break;
            }
            cnt++;
        }
        if (balls[0] == 'R') {
            answer = Math.min(answer, redCnt - cnt);
        } else {
            answer = Math.min(answer, blueCnt - cnt);
        }
        cnt = 0;
        for (int i = N - 1; i >= 0; i--) {
            if (balls[i] != balls[N - 1]) {
                break;
            }
            cnt++;
        }
        if (balls[N - 1] == 'R') {
            answer = Math.min(answer, redCnt - cnt);
        } else {
            answer = Math.min(answer, blueCnt - cnt);
        }

        System.out.println(answer);
    }
}