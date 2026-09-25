class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int start =0,end =0,count=0;
        long long total =0;
        int n=nums.size();
        int maxele =0;
        for(int i=0;i<n;i++)
        {
            maxele = max(maxele,nums[i]);
        }
        while(end<n)
        {
            if(nums[end] == maxele)
            {
                count++;
                while(count == k)
                {
                    total += n-end;
                    if(nums[start] == maxele)
                    {
                        count--;
                    }
                    start++;
                }
            }
            end++;
        }
        return total;
    }
};