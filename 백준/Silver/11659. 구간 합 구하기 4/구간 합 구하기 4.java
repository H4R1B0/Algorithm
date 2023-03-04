import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class Main {
    static int N, M;
    static int[] arr;
    static StringBuilder answer = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] tmp = br.readLine().split(" ");
        N = Integer.parseInt(tmp[0]);
        M = Integer.parseInt(tmp[1]);

        arr = (Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray());
        for (int i = 1; i < N; i++) {
            arr[i] += arr[i-1];
        }
        List<Integer> arrSum = Arrays.stream(arr)
                .boxed()
                .collect(Collectors.toList());
        arrSum.add(0,0);
//        System.out.println(arrSum);
        for (int i = 0; i < M; i++) {
            tmp = br.readLine().split(" ");
            int a = Integer.parseInt(tmp[0]);
            int b = Integer.parseInt(tmp[1]);
            answer.append(arrSum.get(b) - arrSum.get(a-1)+"\n");
        }
        System.out.println(answer);
    }
}