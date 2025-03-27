#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minimumIndex(vector<int>& nums) {
            int cnt=0;
            int maj=-1;
            for(auto x:nums){
                if(cnt==0){
                    maj=x;
                    cnt++;
                }else{
                    if(maj==x){
                        cnt++;
                    }else{
                        cnt--;
                    }
                }
            }

            cnt=0;
            for(auto x:nums){
                if(x==maj){
                    cnt++;
                }
            }
            int u=0;

            for(int i=0;i<nums.size();i++){
                if(nums[i]==maj){
                    u++;
                    cnt--;
                }
               if(2*u>(i+1) && 2*cnt>(nums.size()-i-1)){
                   return i;
               }
                

            }
            return -1;
            
        }
    };