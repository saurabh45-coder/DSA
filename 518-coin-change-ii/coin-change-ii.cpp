class Solution {
public:
// recursion ...........
// int solverec(int amount,vector<int>&coins, int n)
// {
//     if(n == 0)
//     {
//         return 0;
//     }
//     if(amount == 0)
//     {
//         return  1;
//     }
//     if(amount <0)
//     {
//         return 0;
//     }
//     int exclude = solverec(amount,coins,n-1);
//     int include = solverec(amount-coins[n-1],coins,n);
//     return exclude + include;
// }


// using DP .....

int solvemem(int amount,vector<int>coins,int n,vector<vector<int>>&dp)
{
    if(n == 0)
    {
        return 0;
    }
    if(amount == 0)
    {
        return  1;
    }
    if(amount <0)
    {
        return 0;
    }
    if(dp[n][amount] != -1)
    {
        return dp[n][amount];
    }
    int exclude = solvemem(amount,coins,n-1,dp);
    int include = solvemem(amount-coins[n-1],coins,n,dp);
    dp[n][amount] =  exclude + include;
    return dp[n][amount];
}


    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // return solverec(amount,coins,n);

        //create 2d array
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        return solvemem(amount,coins,n,dp);
    }
};