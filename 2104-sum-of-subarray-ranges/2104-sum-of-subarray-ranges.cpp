class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long sum = 0;
        for(int i = 0; i<nums.size(); i++){
            int mini = INT_MAX;
            int maxi = INT_MIN;
            for(int j = i;j<nums.size(); j++){
                mini = min(nums[j], mini);
                maxi = max(nums[j], maxi);

                sum+=(maxi-mini);
            }
        
        }
        return sum;
    }
};