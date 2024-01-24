import java.io.*;
import java.lang.reflect.Array;
import java.util.*;
import java.util.stream.Collectors;

public class Main {
    static int N, M;
    static int[] arr;

    public static void main(String[] args) throws IOException {
        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        long[] dist = new long[N + 2];
        long[] cost = new long[N + 1];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 1; i < N; i++) {
            dist[i] = Long.parseLong(st.nextToken());
        }
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            cost[i] = Long.parseLong(st.nextToken());
        }

        long oil = cost[0];
        long answer = oil * dist[1];
        for (int i = 1; i < N; i++) {
            if (oil > cost[i]) {
                oil = cost[i];
            }
            answer += oil * dist[i + 1];
        }
        System.out.println(answer);
    }
}