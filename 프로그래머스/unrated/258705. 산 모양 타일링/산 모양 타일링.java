class Solution {
    public int solution(int n, int[] tops) {
        final int MOD = 10007;
        int[][] dp = new int[n + 1][2];

        dp[0][0] = 1;

        for (int i = 0; i < n; i++) {
            if (tops[i] == 1) {
                dp[i + 1][0] = (dp[i][0] * 3 + dp[i][1] * 2) % MOD;
            } else {
                dp[i + 1][0] = (dp[i][0] * 2 + dp[i][1]) % MOD;
            }

            dp[i + 1][1] = (dp[i][0] + dp[i][1]) % MOD;
        }

        return (dp[n][0] + dp[n][1]) % MOD;
    }
}