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
        int M = Integer.parseInt(st.nextToken());
        String[] titles = new String[N];
        int[] powers = new int[N];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            titles[i] = st.nextToken();
            powers[i] = Integer.parseInt(st.nextToken());
        }
        StringBuilder answer = new StringBuilder();
        while (M-- > 0) {
            int num = Integer.parseInt(br.readLine());
            int left = 0;
            int right = N - 1;
            while (left <= right) {
                int mid = (left + right) / 2;
                if (powers[mid] < num) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            answer.append(titles[left]).append('\n');
        }
        System.out.println(answer);
    }
}