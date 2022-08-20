class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n= stations.size();
        long long dp[n+1][n+1]; //Maximum fuel exist after refuel j times till ith station
        
        memset(dp,0,sizeof(dp));
        for(int i=0;i<=n;++i){
            dp[i][0] = startFuel;
        }
        
        for(int i=1;i<=n;++i){
            for(int j=1;j<=i;++j){
                dp[i][j] = dp[i-1][j];
                
                if(dp[i-1][j-1] >=stations[i-1][0]){
                    dp[i][j] = max(dp[i][j],dp[i-1][j-1] + stations[i-1][1]);
                }
            }
        }
        
        for(int j=0;j<=n;++j){
            cout<<dp[n][j]<<endl;
            if(dp[n][j] >= target)return j;
        }
        
        return -1;
    }
};