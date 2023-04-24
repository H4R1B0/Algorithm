import java.util.*;

class Solution {
    int answer = 0;
    List<Integer>[] routes;
    public int solution(int[] info, int[][] edges) {
        routes = new ArrayList[info.length];
        for(int i=0;i<info.length;i++){
            routes[i] = new ArrayList<>();
        }
        for(int i=0;i<edges.length;i++){
            int a = edges[i][0];
            int b = edges[i][1];
            routes[a].add(b);
        }
        List<Integer> start = new ArrayList<>();
        for(int i=0;i<routes[0].size();i++){
            start.add(routes[0].get(i));
        }
        dfs(0,0,0,info,start);
        return answer;
    }
    
    void dfs(int cur, int sheep, int wolf, int[] info, List<Integer> node){
        //양인 경우
        if(info[cur] == 0)
            sheep++;
        else
            wolf++;
        answer = Math.max(answer, sheep);
        //늑대가 양보다 같거나 많다면 안되므로 반환
        if(wolf >= sheep)
            return;
        for(int i=0;i<node.size();i++){
            //다음 노드로 가는 리스트
            List<Integer> next = new ArrayList<>();
            for(int j=0;j<node.size();j++){
                if(i != j){
                    next.add(node.get(j));
                }
            }
            for(int j=0;j<routes[node.get(i)].size();j++){
                next.add(routes[node.get(i)].get(j));
            }
            dfs(node.get(i), sheep, wolf, info, next);
        }
    }
}