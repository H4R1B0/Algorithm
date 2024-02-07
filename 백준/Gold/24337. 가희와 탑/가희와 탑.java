import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        List<Integer> arr = new ArrayList<>();
        for (int i = 1; i < a; i++) {
            arr.add(i);
        }
        arr.add(Math.max(a, b));
        for (int i = b - 1; i > 0; i--) {
            arr.add(i);
        }
        if (arr.size() > N) {
            System.out.println(-1);
        } else {
            StringBuilder answer = new StringBuilder();
            answer.append(arr.get(0)).append(' ');
            for (int i = 0; i < N - arr.size(); i++) {
                answer.append(1).append(' ');
            }
            for (int i = 1; i < arr.size(); i++) {
                answer.append(arr.get(i)).append(' ');
            }
            System.out.println(answer);
        }
    }
}