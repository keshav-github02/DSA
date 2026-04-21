#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {

        vector<int> parent(source.size());
        iota(parent.begin(), parent.end(), 0);
        function<int(int)> find = [&](int u) {
            if (parent[u] != u) parent[u] = find(parent[u]);
            return parent[u];
        };

        for (auto& swap : allowedSwaps) {
            int u = find(swap[0]);
            int v = find(swap[1]);
            if (u != v) parent[u] = v;
        }

       unordered_map<int, multiset<int>> groups;
        for (int i = 0; i < source.size(); i++) {
            groups[find(i)].insert(source[i]);
        }

        int ans=0;
        for(int i=0;i<target.size();i++){
            int group=find(i);
            if(groups[group].count(target[i])){
                groups[group].erase(groups[group].find(target[i]));
            }else{
                ans++;
            }
        }

        return ans;
    }
};