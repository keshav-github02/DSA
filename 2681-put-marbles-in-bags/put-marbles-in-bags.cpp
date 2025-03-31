#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        long long putMarbles(vector<int>& weights, int k) {
          vector<long long> vec;
            int n=weights.size()-1;
            for(int i=0;i<n;i++){
              vec.push_back(weights[i]+weights[i+1]);
            }
           sort(vec.begin(),vec.end());
            long long ans=0;
            for(int i=0;i<k-1;i++){
              ans+=vec[n-i-1];
                ans-=vec[i];
            }
            return ans;
        }
    };