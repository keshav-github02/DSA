#include<bits/stdc++.h>
using namespace std;


class Solution {
    public:
        vector<int> partitionLabels(string s) {
            vector<int> last(26, -1);
            vector<int> ans;
            int n = s.size();
            for (int i = 0; i < n; i++) {
                last[s[i] - 'a'] = i;
            }
            int j = 0, k = 0;
            for (int i = 0; i < n; i++) {
                j = max(j, last[s[i] - 'a']);
                if (i == j) {
                    ans.push_back(j - k + 1);
                    k = j + 1;
                }
            }
            return ans;
            
            
        }
    };