import java.io.*;
import java.lang.reflect.Array;
import java.util.*;
import java.util.stream.Collectors;

public class Main {

    public static void main(String[] args) throws IOException {
        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[] arr = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        int left = 0;
        int right = N - 1;

        int min = Math.abs(arr[left] + arr[right]);
        int l = arr[left];
        int r = arr[right];
        while (left < right) {
            int tmp = arr[left] + arr[right];
            if (min > Math.abs(tmp)) {
                min = Math.abs(tmp);
                l = arr[left];
                r = arr[right];
            }
            if (tmp < 0) {
                left++;
            } else {
                right--;
            }
        }
        System.out.println(l + " " + r);
    }
}