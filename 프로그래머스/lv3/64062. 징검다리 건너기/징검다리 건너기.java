import java.util.*;

class Solution {
    public int solution(int[] stones, int k) {
        int answer = 0;
        
        int left = 1;
        int right = Arrays.stream(stones).max().getAsInt();
        
        while(left <= right){
            int mid = (left + right) / 2;
            if(isValid(stones, mid, k)){
                left = mid + 1;
                answer = Math.max(answer, mid);
            }
            else{
                right = mid - 1;
            }
        }
        
        return answer;
    }
    
    boolean isValid(int[] stones, int mid, int k){
        int cnt = 0;
        for(int i=0;i<stones.length;i++){
            if(stones[i] < mid)
                cnt++;
            else
                cnt = 0;
            if(cnt >= k)
                return false;
        }
        return true;
    }
}