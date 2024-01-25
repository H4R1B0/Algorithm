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
        int X = Integer.parseInt(st.nextToken());
        int[] arr = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        int sum = 0;
        for (int i = 0; i < X; i++) {
            sum += arr[i];
        }
        int left = 0;
        int right = X - 1;
        int answer = sum;
        Map<Integer, Integer> dic = new HashMap<>();
        dic.put(sum, dic.getOrDefault(sum, 0) + 1);
        for (int i = right + 1; i < N; i++, left++) {
            int tmp = sum - arr[left] + arr[i];
            sum = tmp;
            answer = Math.max(answer, tmp);
            dic.put(tmp, dic.getOrDefault(tmp, 0) + 1);
        }
        if (answer == 0) {
            System.out.println("SAD");
        } else {
            System.out.println(answer);
            System.out.println(dic.get(answer));
        }
    }
}