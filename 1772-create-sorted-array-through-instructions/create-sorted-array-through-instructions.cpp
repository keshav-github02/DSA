#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        vector<int> bit;
        int query(int i) {
            int ans = 0;
            while (i > 0) {
                ans += bit[i];
                i -= (i & -i);
            }
            return ans;
        }
        void update(int i, int val) {
            while (i < bit.size()) {
                bit[i] += val;
                i += (i & -i);
            }
        }
        int createSortedArray(vector<int>& instructions) {
            int n = instructions.size(), mod = 1e9 + 7;
            int maxi=*max_element(instructions.begin(),instructions.end());
           bit.resize(maxi+ 1, 0);
          
            long long ans = 0;
            for (int i = 0; i < n; ++i) {
                int left = query(instructions[i] - 1);
                int right = i - query(instructions[i]);
                ans += min(left, right);
                update(instructions[i], 1);
            }
            return ans % mod;
            
        }
    };