class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int max_sub;
        int cur_sum = 0;
        for(int i = 0; i < k; i++){
        cur_sum += nums[i];
        }
        max_sub = cur_sum;
        for(int i = k; i < nums.size(); i++){
            cur_sum = (cur_sum - nums[i - k] + nums[i]);
            if(cur_sum > max_sub) max_sub = cur_sum;
        }
        
        return max_sub/(1.0 * k);
    }
};