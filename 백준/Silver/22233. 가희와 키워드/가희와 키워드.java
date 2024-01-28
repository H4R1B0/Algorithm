import java.io.*;
import java.lang.reflect.Array;
import java.util.*;
import java.util.stream.Collectors;

public class Main {

    public static void main(String[] args) throws IOException {
        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        Set<String> dic = new HashSet<>();
        for (int i = 0; i < N; i++) {
            dic.add(br.readLine());
        }
        StringBuilder answer = new StringBuilder();
        for (int i = 0; i < M; i++) {
            String[] list = br.readLine().split(",");
            for (String str : list) {
                dic.remove(str);
            }
            answer.append(dic.size()).append("\n");
        }
        System.out.println(answer);
    }
}