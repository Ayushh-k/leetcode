class Solution {
public:
    int trap(vector<int>& height) {
        int start = 0;
        int end = height.size()-1;

        int leftmax = 0, rightmax = 0, total =0;

        while(start < end){
            leftmax = max(leftmax, height[start]);
            rightmax = max(rightmax, height[end]);

            if(leftmax < rightmax){
                total += leftmax - height[start];
                start++;
            }else{
                total += rightmax - height[end];
                end--;
            }
        }

        return total;
    }
};