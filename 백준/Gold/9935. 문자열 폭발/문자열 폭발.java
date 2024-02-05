import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String A = br.readLine();
        String B = br.readLine();
        StringBuilder answer = new StringBuilder();
        Stack<Character> stk = new Stack<>();
        for (int i = 0; i < A.length(); i++) {
            stk.push(A.charAt(i));
            if (A.charAt(i) == B.charAt(B.length() - 1) && stk.size() >= B.length()) {
                StringBuilder tmp = new StringBuilder();
                for (int j = 0; j < B.length(); j++) {
                    tmp.append(stk.pop());
                }
                if (!tmp.reverse().toString().equals(B)) {
                    for (int j = 0; j < B.length(); j++) {
                        stk.push(tmp.charAt(j));
                    }
                }
            }
        }
        while (!stk.isEmpty()) {
            answer.append(stk.pop());
        }
        System.out.println(answer.length() == 0 ? "FRULA" : answer.reverse());
    }
}