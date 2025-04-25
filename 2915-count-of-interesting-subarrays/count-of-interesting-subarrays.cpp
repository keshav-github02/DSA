#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
            long long ans = 0;
           
            map<int, int> mp;   
            mp[0] = 1;
            long long cnt=0;
            for(auto x:nums){
                if(x%modulo==k) cnt++;
                ans += mp[(cnt-k+modulo)%modulo];
                mp[cnt%modulo]++;
            }
            return ans;
        }
    };
    