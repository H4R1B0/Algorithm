import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static int N, answer = 0;
    static List<Integer> numbers = new ArrayList<>();
    static List<Integer> order = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            numbers.add(Integer.parseInt(st.nextToken()));
            order.add(i);
        }
        dfs(0);
        System.out.println(answer);
    }

    static void dfs(int sum) {
        if (order.size() == 2) {
            answer = Math.max(answer, sum);
            return;
        }

        for(int i=1;i<order.size()-1;i++){
            int value = order.get(i);
            int num = numbers.get(order.get(i-1))*numbers.get(order.get(i+1));
            order.remove(i);
            dfs(sum + num);
            order.add(i,value);
        }
    }

}