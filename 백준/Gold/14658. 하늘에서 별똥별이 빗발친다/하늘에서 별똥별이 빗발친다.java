import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int L = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        List<int[]> arr = new ArrayList<int[]>();
        for (int i = 0; i < K; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            arr.add(new int[]{a, b});
        }
        int answer = 0;
        for (int[] a : arr) {
            for (int[] b : arr) {
                int cnt = 0;
                for (int[] c : arr) {
                    if (a[0] <= c[0] && c[0] <= a[0] + L && b[1] <= c[1] && c[1] <= b[1] + L) {
                        cnt++;
                    }
                }
                answer = Math.max(answer, cnt);
            }
        }
        System.out.println(K - answer);
    }
}