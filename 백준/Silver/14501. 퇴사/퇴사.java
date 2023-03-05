import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    static int N, M;
    static int answer = 0;
    static int[] T, P;
    static int[] dp;


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        T = new int[17];
        P = new int[17];
        dp = new int[17];
        String[] tmp = null;
        for (int i = 1; i <= N; i++) {
            tmp = br.readLine().split(" ");
            T[i] = Integer.parseInt(tmp[0]);
            P[i] = Integer.parseInt(tmp[1]);
        }

        for(int i=1;i<=N;i++){
            if(i+T[i] <= N+1){
                dp[i+T[i]] = Math.max(dp[i+T[i]], dp[i]+P[i]);
                answer = Math.max(answer, dp[i+T[i]]);
            }
            dp[i+1] = Math.max(dp[i],dp[i+1]);
            answer = Math.max(answer, dp[i+1]);
        }

        System.out.println(answer);
    }
}