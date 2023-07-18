class Solution {
    public int[] solution(int[] sequence, int k) {
        int[] answer = {0, 0};
        int len = sequence.length, start = 0, end = len;
        int sum = 0;
        for(int left = 0, right = 0; left < sequence.length; left++){
            while(right < sequence.length && sum < k){
                sum += sequence[right++];
            }
            
            if(sum == k){
                int range = right - left;
                if((end - start) > range){
                    len = range;
                    start = left;
                    end = right;
                }
            }
            
            sum -= sequence[left];
        }
        
        return new int[]{start, end-1};
    }
}