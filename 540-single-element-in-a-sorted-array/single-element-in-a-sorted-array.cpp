class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int index = 0;
        while(index < n-1)
        {
            if(nums[index] != nums[index + 1])
            {
                return nums[index];
            }
            else
            {
                index = index+2;
            }
        }
        return nums[n-1];   
    }
};