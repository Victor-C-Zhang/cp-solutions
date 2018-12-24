n = int(raw_input())
dp = [0]*(n+1)
for i in xrange(2,n+1):
    dp[i] = 3**(i-1) - dp[i-1]
print dp[n]%1000000007
