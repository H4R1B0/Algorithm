import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main {
    static List<Integer> arr = new ArrayList<>();
    static List<Integer> answer = new ArrayList<>();
    static int N, M;
    static boolean[] visit;
    static StringBuilder answer1 = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] tmp = br.readLine().split(" ");
        N = Integer.parseInt(tmp[0]);
        M = Integer.parseInt(tmp[1]);
        for (int i = 1; i <= N; i++) {
            arr.add(i);
        }
        visit = new boolean[N];
        permutation(0,0);
    }

    static void permutation(int idx, int cnt) {
        if (cnt == M) {
            System.out.println(answer1);
            return;
        }
        for (int i = idx; i < N; i++) {
            if(!visit[i]){
                visit[i] = true;
                answer1.append(arr.get(i)+" ");
                permutation(i, cnt+1);
                answer1.deleteCharAt(answer1.length()-1);
                answer1.deleteCharAt(answer1.length()-1);
                visit[i] = false;
            }
        }
    }
}