def solution(temperature, t1, t2, a, b, onboard):
    temperature += 10
    t1 += 10
    t2 += 10
    dp = [[1e9]*55 for _ in range(len(onboard))]
    dp[0][temperature] = 0
    for i in range(0,len(onboard)-1):
        for j in range(52):
            if dp[i][j]==1e9:
                continue
            if onboard[i] and not t1<=j<=t2:
                continue
            # 에어컨 사용
            dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]+a)
            if j>=1:
                dp[i+1][j-1] = min(dp[i+1][j-1], dp[i][j]+a)
            dp[i+1][j] = min(dp[i+1][j],dp[i][j]+b)
            next_tmp = j
            if j<temperature:
                next_tmp+=1
            elif j>temperature:
                next_tmp-=1
            if next_tmp>=0:
                dp[i+1][next_tmp] = min(dp[i+1][next_tmp], dp[i][j])
    answer = 1e9
    for i in range(52):
        if onboard[-1] and not t1<=i<=t2:
            continue
        answer = min(answer,dp[-1][i])
    return answer