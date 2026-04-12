#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> pos=vector<vector<int>>(26,vector<int>(26,-1));
    int n;
    int val(int i,int j){
        int x1=i/6,y1=i%6;
        int x2=j/6,y2=j%6;

        return abs(x1-x2)+abs(y1-y2);
    }
    map<tuple<int,int,int>,int> mp;
    int func(int idx,int f1,int f2,string &word){
        if(idx>=n){
            return 0;
        }
            if(mp.find({idx,f1,f2})!=mp.end()){
                return mp[{idx,f1,f2}];
            }
        int c=word[idx]-'A';
        if(c==f1){
            return mp[{idx,f1,f2}] = func(idx+1,f1,f2,word);
        }
        else if(c==f2){
            return mp[{idx,f1,f2}] = func(idx+1,f1,f2,word);
        }
        else{
            int ans=INT_MAX;
            ans=min(ans,pos[f1][c]+func(idx+1,c,f2,word));
            ans=min(ans,pos[f2][c]+func(idx+1,f1,c,word));
            mp[{idx,f1,f2}] = ans;  
            return ans;
        }
       
        }
    int minimumDistance(string word) {

       

        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                pos[i][j]=val(i,j);
            }
        }
        n=word.size();
        int ans=INT_MAX;

        
        for(int f1=0;f1<26;f1++){
            for(int f2=0;f2<26;f2++){
                if(f1==f2){
                    continue;
                }

                ans=min(ans,func(0,f1,f2,word));


            }
        }
        return ans;
        




    }
};