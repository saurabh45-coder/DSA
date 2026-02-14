class Solution {
public:
    int solve(vector<int>& nums,int i,int j,int n)
    {
        if(i == n)
        {
            return j+1;
        }
        if(nums[i] != nums[j])
        {
            nums[j+1] = nums[i];
            return solve(nums,i+1,j+1,n);
        }
        else
        return solve(nums,i+1,j,n);
    }
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
        return 0;
        return solve(nums,1,0,n);
        
        
    }
};