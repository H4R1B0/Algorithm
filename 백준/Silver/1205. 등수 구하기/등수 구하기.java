import java.io.*;
import java.lang.reflect.Array;
import java.util.*;
import java.util.stream.Collectors;

public class Main {

    public static void main(String[] args) throws IOException {
        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int score = Integer.parseInt(st.nextToken());
        int P = Integer.parseInt(st.nextToken());
        int[] arr = new int[N];
        if (N != 0) {
            st = new StringTokenizer(br.readLine());
        }
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        int cnt = 0;
        int rank = 1;
        for (int i = 0; i < N; i++) {
            if (arr[i] > score) {
                rank++;
            } else if (arr[i] < score) {
                break;
            }
            cnt++;
        }

        if (cnt == P) {
            rank = -1;
        }
        if (N == 0) {
            rank = 1;
        }
        System.out.println(rank);
    }
}