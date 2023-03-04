import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int N;
    static StringBuilder answer = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        Stack<Pos> stack = new Stack<>();
        for (int i = 1; i <= N; i++) {
            int num = Integer.parseInt(st.nextToken());
            while(!stack.isEmpty()){
                if(stack.peek().num >= num){
                    answer.append(stack.peek().idx).append(" ");
                    break;
                }
                stack.pop();
            }
            if(stack.isEmpty()){
                answer.append("0 ");
            }
            stack.add(new Pos(num, i));
        }
        System.out.println(answer);
    }

    static class Pos {
        int num, idx;

        Pos(int num, int idx) {
            this.num = num;
            this.idx = idx;
        }
    }
}
