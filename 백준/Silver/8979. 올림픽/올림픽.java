import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        List<int[]> conturies = new ArrayList<int[]>();
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            int d = Integer.parseInt(st.nextToken());
            conturies.add(new int[]{a, b, c, d});
        }
        conturies.sort((o1, o2) -> {
            if (o1[1] == o2[1]) {
                if (o1[2] == o2[2]) {
                    return o2[3] - o1[3];
                }
                return o2[2] - o1[2];
            }
            return o2[1] - o1[1];
        });
        int answer = 0;
        for(int i=0;i<K-1;i++){
            if(conturies.get(i)[1] == conturies.get(K-1)[1] && conturies.get(i)[2] == conturies.get(K-1)[2] && conturies.get(i)[3] == conturies.get(K-1)[3]){
                continue;
            }
            answer++;
        }
        System.out.println(answer+1);
    }
}