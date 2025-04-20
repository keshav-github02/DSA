class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int,int>mp;
        for(auto x:answers){
            mp[x]++;
        }
        int ans=0;
        for(auto x:mp){
            ans+=(((x.second+x.first)/(x.first+1))*(x.first+1));

        }
        return ans;
    }
};