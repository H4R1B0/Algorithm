import java.io.*;
import java.lang.reflect.Array;
import java.util.*;
import java.util.stream.Collectors;

public class Main {
    static String S, T;
    static Set<String> visit = new HashSet<>();
    static int len;

    public static void main(String[] args) throws IOException {
        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        S = br.readLine();
        T = br.readLine();
        len = S.length();
        boolean answer = dfs(T);
        if (answer) {
            System.out.println(1);
        } else {
            System.out.println(0);
        }
    }

    static boolean dfs(String str) {
        if (str.length() == len) {
            return str.equals(S);
        }
        if (str.charAt(str.length() - 1) == 'A') {
            if (dfs(str.substring(0, str.length() - 1))) {
                return true;
            }
        }
        if (str.charAt(0) == 'B') {
            StringBuilder sb = new StringBuilder(str.substring(1, str.length()));
            if (dfs(sb.reverse().toString())) {
                return true;
            }
        }
        return false;
    }
}