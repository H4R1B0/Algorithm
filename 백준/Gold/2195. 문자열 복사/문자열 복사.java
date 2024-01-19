import java.io.*;

public class Main {
    static String S, P;

    public static void main(String[] args) throws IOException {
        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        S = br.readLine();
        P = br.readLine();

        int answer = 0;
        for (int i = 0; i < P.length(); ) {
            int max = 0;
            for (int j = 0; j < S.length(); j++) {
                int tmp = 0;
                while ((j + tmp) < S.length() && (i + tmp) < P.length() && S.charAt(j + tmp) == P.charAt(i + tmp)) {
                    tmp++;
                }
                max = Math.max(max, tmp);
            }
            i += max;
            answer++;
        }
        System.out.println(answer);
    }
}