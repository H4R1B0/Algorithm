import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        Set<String> set = new HashSet<>();
        List<String> arr = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            String str = br.readLine();
            if (!set.contains(str)) {
                set.add(str);
                arr.add(str);
            }
        }
        int max = 0;
        int a = 0;
        int b = 0;
        for (int i = 0; i < arr.size(); i++) {
            String str1 = arr.get(i);
            for (int j = i + 1; j < arr.size(); j++) {
                String str2 = arr.get(j);
                int cnt = 0;
                int len = Math.min(str1.length(), str2.length());
                for (int k = 0; k < len; k++) {
                    if (str1.charAt(k) != str2.charAt(k)) {
                        break;
                    }
                    cnt++;
                }
                if (max < cnt) {
                    max = cnt;
                    a = i;
                    b = j;
                }
            }
        }
        System.out.println(arr.get(a) + "\n" + arr.get(b));
    }
}