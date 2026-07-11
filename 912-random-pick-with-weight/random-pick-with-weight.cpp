class Solution {
public:
    vector<int>prefix;
    int sum;
    Solution(vector<int>& w) {
        int n= w.size();
        prefix.resize(n);
        prefix[0] = w[0];
        for(int i=1;i<n;i++)
        {
            prefix[i] = prefix[i-1]+w[i];
        }
        sum = prefix[n-1];
    }
    
    int pickIndex() {

        int target = rand() % sum + 1;

        int start = 0;
        int end = prefix.size()-1;
        int ans = -1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (prefix[mid] >= target) {
                ans = mid;
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }

        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */