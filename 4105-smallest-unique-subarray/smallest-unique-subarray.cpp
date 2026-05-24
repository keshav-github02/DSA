#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    bool check(vector<int>& nums, int k) {

        const long long BASE = 1000003;
        const long long MOD = 1e18;

        unordered_map<unsigned long long,int> mp;

        unsigned long long hash = 0;
        unsigned long long power = 1;

        for(int i=0;i<k;i++) {
            hash = hash * BASE + nums[i] + 1;
            if(i) power *= BASE;
        }

        mp[hash]++;

        for(int i=k;i<nums.size();i++) {

            hash -= (unsigned long long)(nums[i-k] + 1) * power;
            hash = hash * BASE + nums[i] + 1;

            mp[hash]++;
        }

        for(auto &x: mp) {
            if(x.second == 1)
                return true;
        }

        return false;
    }

    int smallestUniqueSubarray(vector<int>& nums) {

        int n = nums.size();

        int l = 1, r = n;
        int ans = n;

        while(l <= r) {

            int mid = (l + r) / 2;

            if(check(nums, mid)) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        return ans;
    }
};