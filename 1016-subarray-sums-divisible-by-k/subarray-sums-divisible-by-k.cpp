class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int ,int>m;
        int n = nums.size();
        m[0] =1;
        int prefixsum =0,rem,total =0;
        for(int i=0;i<n;i++)
        {
            prefixsum += nums[i];
            rem = prefixsum % k;
            if(rem <0)
            {
                rem = rem+k;
            }
            if(m.count(rem))
            {
                total += m[rem];
                m[rem]++;
            }
            else
            {
                m[rem] =1;
            }
        }
        return total;
    }
};