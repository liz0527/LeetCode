class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        if(len == 0)
            return 0;
        int ans = nums[0], temp = nums[0];
        for(int i = 1; i < len; i++) {
            if(temp > 0) {
                temp = temp + nums[i];
            } else {
                temp = nums[i];
            }
            ans = max(ans, temp);
        }
        return ans;
    }
};