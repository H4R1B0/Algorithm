import java.util.*;

class Solution {
    // List<Integer>[] brigdes = new ArrayList[1000001];
    Map<Integer, int[]> dic = new HashMap<>();
    public int[] solution(int[][] edges) {
        int[] answer = {0,0,0,0};
        
        //횟수 저장
        for(int[] edge : edges){
            int a = edge[0];
            int b = edge[1];
            
            //a,b가 존재하지 않는 경우 put
            dic.putIfAbsent(a, new int[]{0,0});
            dic.putIfAbsent(b, new int[]{0,0});
            
            //나간 횟수, 들어온 횟수 증가
            dic.get(a)[0]++;
            dic.get(b)[1]++;
        }
        
        for(Map.Entry<Integer, int[]> entry : dic.entrySet()){
            int key = entry.getKey();
            int[] cnt = entry.getValue();
            if(cnt[0]>=2 && cnt[1] == 0){
                answer[0] = key;
            } else if(cnt[0]==0 && cnt[1]>0){
                answer[2]++;
            } else if(cnt[0]>=2 && cnt[1]>=2){
                answer[3]++;
            }   
        }
        answer[1] = dic.get(answer[0])[0] - answer[2] - answer[3];
        return answer;
    }
}