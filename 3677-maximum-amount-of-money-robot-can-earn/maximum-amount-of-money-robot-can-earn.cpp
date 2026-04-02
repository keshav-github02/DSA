class Solution {
public:
    int m, n;
    vector<vector<vector<int>>> dp;
    
    int solve(int i, int j, int k, vector<vector<int>>& coins) {
        if(i >= m || j >= n) return -1e9;
        
        if(i == m-1 && j == n-1) {
            if(coins[i][j] >= 0) return coins[i][j];
            if(k > 0) return 0;
            return coins[i][j];
        }
        
        if(dp[i][j][k] != -1e9) return dp[i][j][k];
        
        int res = -1e9;
        
        int val = coins[i][j];
        
        int down = solve(i+1, j, k, coins);
        int right = solve(i, j+1, k, coins);
        
        int best_next = max(down, right);
        
        if(best_next != -1e9) {
            res = max(res, val + best_next);
        }
        
        if(val < 0 && k > 0) {
            int down2 = solve(i+1, j, k-1, coins);
            int right2 = solve(i, j+1, k-1, coins);
            
            int best_next2 = max(down2, right2);
            
            if(best_next2 != -1e9) {
                res = max(res, best_next2);
            }
        }
        
        return dp[i][j][k] = res;
    }
    
    int maximumAmount(vector<vector<int>>& coins) {
        m = coins.size();
        n = coins[0].size();
        
        dp.assign(m, vector<vector<int>>(n, vector<int>(3, -1e9)));
        
        return solve(0, 0, 2, coins);
    }
};