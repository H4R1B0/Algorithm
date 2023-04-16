import java.util.*;

class Solution {
    public int solution(int[][] targets) {
        Arrays.sort(targets, (o1, o2)->{
            if(o1[1] == o2[1]){
                return o1[0] - o2[0];
            }
            return o1[1] - o2[1];
        });
        int end = targets[0][1];
        int answer = 1;
        for(int i=1;i<targets.length;i++){
            if(end <= targets[i][0]){
                end = targets[i][1];
                answer++;
            }
        }
        return answer;
    }
}