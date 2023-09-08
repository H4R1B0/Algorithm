import java.util.*;

class Solution {
    int[][] costs = {
        {1,7,6,7,5,4,5,3,2,3},
        {7,1,2,4,2,3,5,4,5,6},
        {6,2,1,2,3,2,3,5,4,5},
        {7,4,2,1,5,3,2,6,5,4},
        {5,2,3,5,1,2,4,2,3,5},
        {4,3,2,3,2,1,2,3,2,3},
        {5,5,3,2,4,2,1,5,3,2},
        {3,4,5,6,2,3,5,1,2,4},
        {2,5,4,5,3,2,3,2,1,2},
        {3,6,5,4,5,3,2,4,2,1},
    };
    int len;
    int[][][] dp;
    String number;
    public int solution(String numbers) {
        number = numbers;
        len = numbers.length();
        dp = new int[len+1][10][10];
        
        for(int i=0;i<=len;i++){
            for(int j=0;j<10;j++){
                Arrays.fill(dp[i][j], -1);
            }
        }
        return dfs(0, 4, 6);
    }
    
    private int dfs(int cnt, int left, int right){
        if(cnt == len)
            return 0;
        
        if(dp[cnt][left][right] != -1)
            return dp[cnt][left][right];
        
        int num = number.charAt(cnt) - '0';
        int result = Integer.MAX_VALUE;
        
        if(num != right){
            result = Math.min(result, dfs(cnt+1, num, right) + costs[left][num]);
        }
        
        if(num != left){
            result = Math.min(result, dfs(cnt+1, left, num) + costs[right][num]);
        }
        
        return dp[cnt][left][right] = result;
    }
}