import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[] arr = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        int M = Integer.parseInt(br.readLine());
        int[] cmds = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        Arrays.sort(arr);
        for (int i = 0; i < cmds.length; i++) {
            if (Arrays.binarySearch(arr, cmds[i]) >= 0)
                System.out.println(1);
            else
                System.out.println(0);
        }
    }

    static int binarySearch(int[] arr, int num) {
        int left = 0, right = arr.length - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (arr[mid] < num) {
                left = mid + 1;
            } else if (num > arr[mid]) {
                right = mid - 1;
            } else if (arr[mid] == num) {
                return mid;
            }
        }
        return -1;
    }
}