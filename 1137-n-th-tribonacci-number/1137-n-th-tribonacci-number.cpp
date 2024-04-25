class Solution {
public:
    int dp[38];
    int solve(int n){
        if(n==0){
            return 0;
        }
        if(n==1 || n==2){
            return 1;
        }
        if(dp[n]!=-1){return dp[n];}
        int a=solve(n-1);
        int b=solve(n-2);
        int c=solve(n-3);
        return dp[n]=a+b+c;
    } 
    int tribonacci(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n);
    }
};