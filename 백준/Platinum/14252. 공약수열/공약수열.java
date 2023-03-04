import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[] arr = new int[N];
        arr = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        Arrays.sort(arr);

        int answer = 0;
        for (int i = 0; i < N - 1; i++) {
            answer += cal(arr[i], arr[i + 1]);
        }
        System.out.println(answer);
    }

    static int cal(int a, int b) {
        if (gcd(a, b) == 1)
            return 0;

        for (int i = a + 1; i < b; i++) {
            if (gcd(a, i) == 1 && gcd(i, b) == 1)
                return 1;
        }
        for (int i = a + 1; i < b; i++) {
            for (int j = i + 1; j < b; j++) {
                if (gcd(a, i) == 1 && gcd(i, j) == 1 && gcd(j, b) == 1)
                    return 2;
            }
        }
        return 3;
    }

    static int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
}