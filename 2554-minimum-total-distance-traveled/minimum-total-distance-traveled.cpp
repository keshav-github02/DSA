class Solution {
public:
long long solve(int i,int j, vector<int>& robot,vector<int>&pos, vector<vector<long long
>>&dp){
    if(i>=robot.size())
    return 0;
    if(j>=pos.size())
    return 1e12;
    if(dp[i][j]!=-1)
    return dp[i][j];
    long long take=abs(robot[i]-pos[j])+solve(i+1,j+1,robot,pos,dp);
    long long not_take=solve(i,j+1,robot,pos,dp);
    return dp[i][j]=min(take,not_take);
}
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {

        int n=robot.size();
        sort(factory.begin(),factory.end());
        vector<int> pos;
        for(auto x:factory){
            for(int i=0;i<x[1];i++){
                pos.push_back(x[0]);
            }
        }
        sort(pos.begin(),pos.end());
        sort(robot.begin(),robot.end());
        int m=pos.size();
        vector<vector<long long>> dp(n+1,vector<long long>(m+1,-1));
        return solve(0,0,robot,pos,dp);
        
    }
};