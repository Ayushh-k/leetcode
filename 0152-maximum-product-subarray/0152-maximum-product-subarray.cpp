class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty()) return 0; 
        int maxProduct = nums[0];
        int prefix = 1;
        int suffix = 1;

        for(int i=0;i<nums.size();i++){
            if(prefix==0) prefix = 1;
            if(suffix==0) suffix = 1;

            prefix*=nums[i];
            suffix*=nums[nums.size()-i-1];

            maxProduct = max(maxProduct, max(prefix,suffix));
        }
        return maxProduct;
    }
};