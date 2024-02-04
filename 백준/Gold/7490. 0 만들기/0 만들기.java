import java.io.*;
import java.util.*;

public class Main {
    static int N;
    static StringBuilder answer = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            N = Integer.parseInt(br.readLine());
            comb(1, "1");
            answer.append('\n');
        }
        System.out.println(answer);
    }

    static void comb(int num, String str) {
        if (num == N) {
            if (cal(str) == 0) {
                answer.append(str).append('\n');
            }
            return;
        }

        comb(num + 1, str + " " + (num + 1));
        comb(num + 1, str + "+" + (num + 1));
        comb(num + 1, str + "-" + (num + 1));
    }

    static int cal(String str) {
        str = str.replaceAll(" ", "");
        String[] sp = str.split("[+,-]");
        int answer = Integer.parseInt(sp[0]);
        for (int i = 0, idx = 1; i < str.length(); i++) {
            if (str.charAt(i) == '+') {
                answer += Integer.parseInt(sp[idx++]);
            } else if (str.charAt(i) == '-') {
                answer -= Integer.parseInt(sp[idx++]);
            }
        }
        return answer;
    }
}