import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    static int N, idx;
    static int[] numbers;
    static int[] answer;
    static boolean[] visit;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        numbers = new int[N + 1];
        answer = new int[N];
        visit = new boolean[N+1];
        for (int i = 1; i <= N; i++) {
            numbers[i] = Integer.parseInt(br.readLine());
        }

        for (int i = 1; i <= N; i++) {
            Arrays.fill(visit,false);
            dfs(i,i);
        }
        System.out.println(idx);
        for(int i=0;i<idx;i++){
            System.out.println(answer[i]);
        }
    }

    static void dfs(int start, final int end) {
        if(visit[start]){
            if(start == end){
                answer[idx++] = end;
            }
            return;
        }else{
            visit[start] = true;
            dfs(numbers[start], end);
        }
    }
}