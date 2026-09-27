class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n= nums.size();
        unordered_map<int,int>m;
        int sum =0;
        m[0] =-1;
        for(int i=0;i<n;i++)
        {
            sum += nums[i];

            int rem = sum % k;

            if(m.count(rem))
            {
                if(i - m[rem] >= 2)
                {
                    return true;
                }
            }
            else
            {
                m[rem] = i;
            }
            
        }
        return false;
    }
};