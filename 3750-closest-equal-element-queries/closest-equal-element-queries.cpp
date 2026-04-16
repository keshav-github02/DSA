#include<bits/stdc++.h>
using namespace std;


class Solution {
public: 
    int n;
    int func(int x, vector<int>& v){
        if(v.size()==1){
            return -1;
        }

        int l=0,r=v.size()-1;
        int idx=-1;

        while(l<=r){
            int mid=l+(r-l)/2;
            if(v[mid]>x){   
                idx=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }

        int idx2=-1;
        l=0,r=v.size()-1;

        while(l<=r){
            int mid=l+(r-l)/2;
            if(v[mid]<x){   
                idx2=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }

        int ans = INT_MAX;

      if(idx!=-1){
            ans = min(ans, abs(v[idx] - x));
                    
      }

      else{
           ans=min(ans,v[0]+(n-v[v.size()-1]));

      }

      if(idx2!=-1){
            ans = min(ans, abs(v[idx2] - x));
      }

      else{
           ans=min(ans,n-v[v.size()-1]+(v[0]));
      }

    return (ans == INT_MAX ? -1 : ans);
    }

    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {

        vector<int>ans;
        n=nums.size();
        map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }

        for(auto x:queries){
            ans.push_back(func(x,mp[nums[x]]));
        }
        return ans;
    }
};