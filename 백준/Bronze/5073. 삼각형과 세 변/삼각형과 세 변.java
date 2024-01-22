import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;
        StringBuilder answer = new StringBuilder();
        while (true) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            if (a == 0 && a == b && b == c) {
                break;
            }
            int max = Math.max(a, Math.max(b, c));
            int remain = a + b + c - max;
            if (remain <= max) {
                answer.append("Invalid");
            } else if (a == b && b == c) {
                answer.append("Equilateral");
            } else if (a == b || a == c || b == c) {
                answer.append("Isosceles");
            } else {
                answer.append("Scalene");
            }
            answer.append("\n");
        }
        System.out.println(answer);
    }
}