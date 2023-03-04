import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] tmp = br.readLine().split(" ");
        int N = Integer.parseInt(tmp[0]);
        int L = Integer.parseInt(tmp[1]);

        int[] arr = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();

        System.out.println(getAnswer(arr, L));
    }

    static int getAnswer(int[] arr, int L) {
        Arrays.sort(arr);
        int cnt = 0;
        for (int i = 1, start = arr[0]; i < arr.length; i++) {
            if (L <= arr[i] - start) {
                cnt++;
                start = arr[i];
            }
        }
        return cnt + 1;
    }

}