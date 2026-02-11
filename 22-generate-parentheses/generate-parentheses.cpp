class Solution {
public:
void parantheses(int n,int left,int right,vector<string>&ans,string& temp)
{
    // base case
    if(left == n && right == n)
    {
        ans.push_back(temp);
        return ;
    }
    //left paranthese
    if(left<n)
    {
        temp.push_back('(');
        parantheses(n,left+1,right,ans,temp);
        temp.pop_back();
    }
    //right parantheses
    if(right<left)
    {
        temp.push_back(')');
        parantheses(n,left,right+1,ans,temp);
        temp.pop_back();
    }
}
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string temp;
        parantheses(n,0,0,ans,temp);
        return ans;
    }
};