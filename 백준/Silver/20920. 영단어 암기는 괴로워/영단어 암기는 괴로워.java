import java.io.*;
import java.lang.reflect.Array;
import java.util.*;
import java.util.stream.Collectors;

public class Main {
    static int N, M;
    static int[] arr;

    public static void main(String[] args) throws IOException {
        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        List<String> list = new ArrayList<String>();
        Map<String, Integer> dic = new HashMap<String, Integer>();
        for (int i = 0; i < N; i++) {
            String str = br.readLine();
            if (str.length() < M) {
                continue;
            }
            if (dic.getOrDefault(str, 0) != 0) {
                dic.put(str, dic.getOrDefault(str, 0) + 1);
                continue;
            }

            list.add(str);
            dic.put(str, dic.getOrDefault(str, 0) + 1);
        }
        list.sort((o1, o2) -> {
            if (dic.get(o2) == dic.get(o1)) {
                if (o2.length() == o1.length()) {
                    return o1.compareTo(o2);
                }
                return o2.length() - o1.length();
            }
            return dic.get(o2) - dic.get(o1);
        });
        StringBuilder answer = new StringBuilder();
        list.stream().forEach(
            i -> answer.append(i).append('\n')
        );
        System.out.println(answer);
    }
}