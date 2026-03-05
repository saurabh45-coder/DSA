class Solution {
public:
    int solve(vector<int>& nums, int val, int index, int k)
    {
        if(index == nums.size())
            return k;
        if(nums[index] != val)
        {
            nums[k] = nums[index];
            return solve(nums, val, index + 1, k + 1);
        }
        return solve(nums, val, index + 1, k);
    }

    int removeElement(vector<int>& nums, int val) {
        return solve(nums, val, 0, 0);
    }
};