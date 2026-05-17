#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(vector<int>& arr, int start, vector<bool>& visited,int n){
        if(start<0 || start>=n || visited[start]) return false;
        if(arr[start] == 0) return true;
        visited[start] = true;
        return dfs(arr, start+arr[start], visited,n) || dfs(arr, start-arr[start], visited,n);
    }
    
    bool canReach(vector<int>& arr, int start) {
        int n =arr.size();
        vector<bool> visited(n, false);
        return dfs(arr, start, visited,n);
        
    }
};