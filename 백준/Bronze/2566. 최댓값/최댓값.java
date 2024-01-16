import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int max = Integer.MIN_VALUE;
        int x = 0, y = 0;
        StringTokenizer st = null;
        for (int i = 1; i <= 9; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= 9; j++) {
                int a = Integer.parseInt(st.nextToken());
                if (max < a) {
                    max = a;
                    x = i;
                    y = j;
                }
            }
        }
        System.out.println(max);
        System.out.println(x + " " + y);
    }
}