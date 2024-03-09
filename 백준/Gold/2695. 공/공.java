import java.util.*;
import java.lang.*;
import java.io.*;

// The main method must be in a class named "Main".
class Main {
    static int[][] dp = new int[1001][51];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // StringTokenizer st = new StringTokenizer(br.readLine());
        int T = Integer.parseInt(br.readLine());
        for (int i = 1; i <= 1000; i++) {
            Arrays.fill(dp[i],-1);
			dp[i][1] = i; // 공이 하나일때는 현재 floor만큼 확인해야 됨
		}

        dfs(1000,50);
        while(T-->0){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            System.out.println(dp[b][a]);
        }
    }

    static int dfs(int n, int k){
        if(n==0){
            return 0;
        }
        if(k==0){
            return Integer.MAX_VALUE;
        }
        if(dp[n][k]!=-1){
            return dp[n][k];
        }
        int result = dp[n][1];

        for(int i=1;i<=n;i++){
            result = Math.min(result, Math.max(dfs(i-1,k-1),dfs(n-i,k))+1);
        }
        return dp[n][k]=result;
    }
}