class Solution {
public:
    int print(vector<int>& nums,int index,int sum ,int target)
    {
        int n = nums.size();
         if(index == n)
         {
            if(sum == target)
            {
                return 1;
            }
            else
            {
                return 0;
            }
         }
       return print(nums,index+1,sum+nums[index],target)+print(nums,index+1,sum-nums[index],target);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return print(nums,0,0,target);
        
    }
};