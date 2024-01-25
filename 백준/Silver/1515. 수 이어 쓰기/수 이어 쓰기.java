import java.io.*;
import java.lang.reflect.Array;
import java.util.*;
import java.util.stream.Collectors;

public class Main {

    public static void main(String[] args) throws IOException {
        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        int cnt = 0;
        for (int i = 1; i <= 30000; i++) {
            String num = Integer.toString(i);
            for (int j = 0; j < num.length(); j++) {
                if (str.charAt(cnt) == num.charAt(j)) {
                    cnt++;
                }
                if (cnt == str.length()) {
                    System.out.println(i);
                    return;
                }
            }
        }
    }
}