import java.io.*;
import java.lang.reflect.Array;
import java.util.*;
import java.util.stream.Collectors;

public class Main {
    static int N;

    public static void main(String[] args) throws IOException {
        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        int[] arr1 = new int[N];
        int[] result = new int[N];
        char[] tmp = br.readLine().toCharArray();
        for (int i = 0; i < N; i++) {
            arr1[i] = tmp[i] - '0';
        }
        int[] arr2 = Arrays.copyOf(arr1, arr1.length);
        tmp = br.readLine().toCharArray();
        for (int i = 0; i < N; i++) {
            result[i] = tmp[i] - '0';
        }

        arr2[0] = 1 - arr2[0];
        arr2[1] = 1 - arr2[1];
        int answer1 = change(arr1, result);
        int answer2 = change(arr2, result);
        if (answer2 != -1) {
            answer2++;
        }
        if (answer1 == -1) {
            System.out.println(answer2);
        } else if (answer2 == -1) {
            System.out.println(answer1);
        } else {
            System.out.println(Math.min(answer1, answer2));
        }
    }

    static int change(int[] from, int[] to) {
        int cnt = 0;
        for (int i = 1; i < N; i++) {
            if (from[i - 1] != to[i - 1]) {
                cnt++;
                from[i - 1] = 1 - from[i - 1];
                from[i] = 1 - from[i];
                if (i != N - 1) {
                    from[i + 1] = 1 - from[i + 1];
                }
            }
        }
        return from[N - 1] == to[N - 1] ? cnt : -1;
    }
}