import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static private int N,M;
    static private List<int[]>[] arr;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        arr = new ArrayList[N+1];
        for(int i=0;i<=N;i++){
            arr[i] = new ArrayList<>();
        }
        for(int i=0;i<M;i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            arr[a].add(new int[]{b,i});
            arr[b].add(new int[]{a,i});
        }
        long[] dist = new long[N+1];
        Arrays.fill(dist,Long.MAX_VALUE);
        dist[1] = 0;
        //cost,cur
        PriorityQueue<Node> pq = new PriorityQueue<>((o1,o2)->{
            return Long.compare(o1.cost,o2.cost);
        });
        pq.add(new Node(0L,1));
        while(!pq.isEmpty()){
            Node cur = pq.poll();
            if(cur.idx==N){
                System.out.println(cur.cost);
                return;
            }
            if(dist[cur.idx]<cur.cost){
                continue;
            }
            for(int[] next : arr[cur.idx]){
                long nextCost = ((cur.cost-next[1]+M-1)/M)*M+next[1]+1;
                if(dist[next[0]] > nextCost){
                    dist[next[0]] = nextCost;
                    pq.add(new Node(nextCost, next[0]));
                }
            }
        }
    }

    static class Node{
        Long cost;
        int idx;
        public Node(Long cost, int idx){
            this.cost = cost;
            this.idx = idx;
        }
    }
}