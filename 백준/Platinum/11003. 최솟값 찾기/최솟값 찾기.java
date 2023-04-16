import java.io.*;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int L = Integer.parseInt(st.nextToken());
        Deque<int[]> dq = new ArrayDeque<>();
        StringBuilder answer = new StringBuilder();
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            int num = Integer.parseInt(st.nextToken());
            while (!dq.isEmpty() && dq.peekLast()[0] > num)
                dq.pollLast();
            dq.offer(new int[]{num, i});
            if(dq.peekFirst()[1] < i-L+1)
                dq.pollFirst();
            answer.append(dq.peekFirst()[0]).append(" ");
        }
        System.out.println(answer);
    }
}