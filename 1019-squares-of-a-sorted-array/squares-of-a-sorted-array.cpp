class Solution {
public:
    void squares(vector<int>& nums,int index,vector<int>& ans,int n)
    {
        if(index ==n)
        {
            return;
        }
        ans.push_back(nums[index] * nums[index]);
        squares(nums,index+1,ans,n);
    }
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        squares(nums,0,ans,n);
        sort(ans.begin(),ans.end());
        return ans;
    }
};