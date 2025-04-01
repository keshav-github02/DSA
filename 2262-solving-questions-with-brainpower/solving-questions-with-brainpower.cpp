#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:

	
		long long mostPoints(vector<vector<int>>& questions) {
			vector<long long> dp(questions.size(),-1);

			for(int i=questions.size()-1;i>=0;i--){
				int points = questions[i][0];
				int jump = questions[i][1];
				long long take = points + (i+jump+1 < questions.size() ? dp[i+jump+1] : 0);
				long long notTake = (i+1 < questions.size() ? dp[i+1] : 0);
				dp[i] = max(take,notTake);
			}

			return dp[0];
			
		}
	};