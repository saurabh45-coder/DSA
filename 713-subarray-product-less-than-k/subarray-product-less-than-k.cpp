class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int count =0;
        for(int i=0;i<n;i++)
        {
            int product =1;
            for(int j=i;j<n;j++)
            {
                if(product * nums[j]<k)
                {
                    product *= nums[j];
                    count++;
                }
                else
                {
                    break;
                }
            }
        }
        return  count;
    }
};