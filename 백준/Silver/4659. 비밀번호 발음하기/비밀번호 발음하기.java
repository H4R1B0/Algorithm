import java.io.*;
import java.util.*;

public class Main {
    static final String AC = "<%s> is acceptable.";
    static final String NAC = "<%s> is not acceptable.";

    public static void main(String[] args) throws IOException {
        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder answer = new StringBuilder();
        while (true) {
            String str = br.readLine();
            if (str.equals("end")) {
                break;
            }
            boolean flag = isAble(str);
            if (flag) {
                answer.append(String.format(AC, str)).append('\n');
            } else {
                answer.append(String.format(NAC, str)).append('\n');
            }
        }
        System.out.println(answer);
    }

    static boolean isAble(String str) {
        int cnt = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == 'a' || str.charAt(i) == 'e' || str.charAt(i) == 'i' || str.charAt(i) == 'o' || str.charAt(i) == 'u') {
                cnt++;
            }
        }
        if (cnt == 0) {
            return false;
        }
        if (str.matches(".*[aeoui][aeoui][aeoui].*")) {
            return false;
        }
        if (str.matches(".*[^aeoui][^aeoui][^aeoui].*")) {
            return false;
        }
        if (!str.contains("ee") && !str.contains("oo") && str.matches(".*(\\w)\\1.*")) {
            return false;
        }

        return true;
    }
}