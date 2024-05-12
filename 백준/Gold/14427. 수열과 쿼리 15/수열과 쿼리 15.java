import java.util.*;
import java.lang.*;
import java.io.*;

// The main method must be in a class named "Main".
class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        PriorityQueue<int[]> pq = new PriorityQueue<>((o1,o2) -> {
            if(o1[0]==o2[0]){
                return o1[1]-o2[1];
            }
            return o1[0]-o2[0];
        });
        st = new StringTokenizer(br.readLine());
        int[] arr = new int[N];
        for(int i=0;i<N;i++){
            arr[i] = Integer.parseInt(st.nextToken());
            pq.add(new int[]{arr[i],i});
        }
        StringBuilder answer = new StringBuilder();
        int M = Integer.parseInt(br.readLine());
        for (int i=0;i<M;i++) {
            String[] cmd = br.readLine().split(" ");
            if(cmd.length==3){
                int idx = Integer.parseInt(cmd[1])-1;
                int value = Integer.parseInt(cmd[2]);
                arr[idx] = value;
                pq.add(new int[]{value, idx});
            }else{
                while(!pq.isEmpty() && arr[pq.peek()[1]] != pq.peek()[0]) {
                    pq.poll();
                }
                answer.append(pq.peek()[1] + 1).append('\n');
            }
        }
        System.out.println(answer);
    }
}