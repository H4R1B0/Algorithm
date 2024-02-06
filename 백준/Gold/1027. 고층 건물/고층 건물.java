import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[] arr = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        int[] cnt = new int[N];

        for (int i = 0; i < N; i++) {
            double maxL = -1000000000;
            for (int j = i + 1; j < N; j++) {
                int h = arr[j] - arr[i];
                int w = j - i;
                double l = (double) h / w;
                if (l <= maxL) {
                    continue;
                }
                maxL = l;
                cnt[i]++;
                cnt[j]++;
            }
        }
        System.out.println(Arrays.stream(cnt).max().getAsInt());
    }
}