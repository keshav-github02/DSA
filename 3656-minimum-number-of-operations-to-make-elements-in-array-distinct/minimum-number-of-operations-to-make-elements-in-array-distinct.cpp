class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        set<int>st;
        for(int i=nums.size()-1;i>=0;i--){
            if(st.find(nums[i])!=st.end()){
                return (i+3)/3;
            }
            st.insert(nums[i]);
        }
        return 0;
    }
};