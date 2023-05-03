import java.util.*;

class Solution {
    List<int[]>[] routes;
    boolean[] isSummit;
    int[] intensities;
    public int[] solution(int n, int[][] paths, int[] gates, int[] summits) {
        //번호, 최소값
        int[] answer = {-1, Integer.MAX_VALUE};
        routes = new ArrayList[n+1];
        isSummit = new boolean[n+1];
        intensities = new int[n+1];
        Arrays.fill(intensities, -1); //거리 -1로 초기화
        for(int i=1;i<=n;i++){
            routes[i] = new ArrayList<>();
        }
        //등산로 연결
        for(int i=0;i<paths.length;i++){
            int from = paths[i][0];
            int to = paths[i][1];
            int cost = paths[i][2];
            routes[from].add(new int[]{to, cost});
            routes[to].add(new int[]{from, cost});
        }
        //산봉우리 체크
        for(int i=0;i<summits.length;i++){
            isSummit[summits[i]] = true;
        }
        //거리, 위치
        PriorityQueue<int[]> pq = new PriorityQueue<>((o1,o2) -> {
            return o1[0] - o2[0];
        });
        //입구는 당연히 거리가 0
        for(int gate : gates){
            pq.add(new int[]{0, gate});
            intensities[gate] = 0;
        }
        while(!pq.isEmpty()){
            int[] tmp = pq.poll();
            int cost = tmp[0];
            int cur = tmp[1];
            
            //해당 위치까지의 intensity 최소값보다 큰 경우 패스
            if(cost > intensities[cur])
                continue;
            //산봉우리인 경우 답 체크
            if(isSummit[cur]){
                if(answer[1] > cost){
                    answer[0] = cur;
                    answer[1] = cost;
                } else if(answer[1] == cost && answer[0] > cur){
                    answer[0] = cur;
                }
                continue;
            }
            
            for(int[] route : routes[cur]){
                int next = route[0];
                int nextCost = Math.max(route[1], cost);
                if(intensities[next] == -1 || intensities[next] > nextCost){
                    intensities[next] = nextCost;
                    pq.add(new int[]{nextCost, next});
                }
            }
        }
        
        return answer;
    }
}