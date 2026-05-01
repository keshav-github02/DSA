#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans+=i*nums[i];
        }
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }

        int ans1=ans;
        for(int i=nums.size()-1;i>=0;i--){
            ans=ans+sum-nums.size()*nums[i];
            ans1=max(ans1,ans);
        }
        return ans1;
    }
};