import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;
        int M = Integer.parseInt(br.readLine());
        Set<Integer> set = new HashSet<>();
        StringBuilder answer = new StringBuilder();
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            String op = st.nextToken();
            if (op.equals("add")) {
                int x = Integer.parseInt(st.nextToken());
                set.add(x);
            } else if (op.equals("remove")) {
                int x = Integer.parseInt(st.nextToken());
                if (set.contains(x)) {
                    set.remove(x);
                }
            } else if (op.equals("check")) {
                int x = Integer.parseInt(st.nextToken());
                if (set.contains(x)) {
                    answer.append(1).append('\n');
                } else {
                    answer.append(0).append('\n');
                }
            } else if (op.equals("toggle")) {
                int x = Integer.parseInt(st.nextToken());
                if (set.contains(x)) {
                    set.remove(x);
                } else {
                    set.add(x);
                }
            } else if (op.equals("all")) {
                set.clear();
                set.addAll(List.of(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20));
            } else if (op.equals("empty")) {
                set.clear();
            }
        }
        System.out.println(answer);
    }
}