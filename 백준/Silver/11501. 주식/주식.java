import java.io.*;
import java.lang.reflect.Array;
import java.util.*;
import java.util.stream.Collectors;

public class Main {

    public static void main(String[] args) throws IOException {
        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        StringBuilder answer = new StringBuilder();
        while (T-- > 0) {
            int N = Integer.parseInt(br.readLine());
            int[] values = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            long sum = 0;
            int max = 0;
            for (int i = N - 1; i >= 0; i--) {
                if (values[i] < max) {
                    sum += (max - values[i]);
                } else {
                    max = values[i];
                }
            }
            answer.append(sum).append('\n');
        }
        System.out.println(answer);
    }
}