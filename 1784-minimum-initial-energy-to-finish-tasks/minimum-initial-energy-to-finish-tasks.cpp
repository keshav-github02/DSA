#include <bits/stdc++.h>
using namespace std;


class Solution {
public:

    bool isp(vector<vector<int>>& tasks, int mid) {
        int sum = 0;
        for (auto& t : tasks) {
            if (mid< t[1]) {
                return 0;
               
            }
             mid-= t[0];
        }
        return 1;
        return mid >= 0;
    }
    int minimumEffort(vector<vector<int>>& tasks) {

        sort(tasks.begin(), tasks.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] - a[0] > b[1] - b[0];
        });

        int left = 0, right = 1e9;

        int ans = right;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if(isp(tasks, mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }

           
        }
        return ans;
        
    }
};