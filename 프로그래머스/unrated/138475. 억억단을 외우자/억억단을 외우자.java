import java.util.*;

class Solution {
    public int[] solution(int e, int[] starts) {
        int[] answer = new int[starts.length];
        int[] counts = new int[e+1];
        for(int i=1;i<=e;i++){
            for(int j=i;j<=e;j+=i){
                counts[j]++;
            }
        }
        
        int[][] arr = new int[e][2];
        for(int i=1;i<counts.length;i++){
            arr[i-1] = new int[]{i, counts[i]};
        }
        
        Arrays.sort(arr, (o1,o2) -> {
            if(o2[1] == o1[1]){
                return o1[0] - o2[0];
            }
            return o2[1] - o1[1];
        });
        
        for(int i=0;i<starts.length;i++){
            int min = starts[i];
            for(int j=0;j<arr.length;j++){
                if(arr[j][0] >= min){
                    answer[i] = arr[j][0];
                    break;
                }
            }
        }
        return answer;
    }
}