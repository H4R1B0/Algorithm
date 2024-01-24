import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int M = Integer.parseInt(st.nextToken());
        char c = st.nextToken().charAt(0);
        Set<String> set = new HashSet<String>();
        for (int i = 0; i < M; i++) {
            String s = br.readLine();
            set.add(s);
        }
        if (c == 'Y') {
            System.out.println(set.size() / 1);
        } else if (c == 'F') {
            System.out.println(set.size() / 2);
        } else if (c == 'O') {
            System.out.println(set.size() / 3);
        }
    }
}