class Solution {
public:
    int solve(vector<int>& nums,int i,int j,int n)
    {
        if(i == n)
        return j;
        if(nums[i] != nums[j-2])
        {
            nums[j] = nums[i];
            return solve(nums,i+1,j+1,n);
        }
        else
        return solve(nums,i+1,j,n);
    }
    int removeDuplicates(vector<int>& nums) {
        int n= nums.size();
        if(n <=2)
        {
            return n;
        }
        return solve(nums,2,2,n);
        
    }
};