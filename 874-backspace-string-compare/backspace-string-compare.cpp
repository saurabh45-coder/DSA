class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>st,temp;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] != '#')
            {
                st.push(s[i]);
            }
            else if(!st.empty())
            {
                st.pop();
            }
        }

        for(int i = 0; i < t.size(); i++)
        {
            if(t[i] != '#')
            {
                temp.push(t[i]);
            }
            else if(!temp.empty())
            {
                temp.pop();
            }
        }
        if(st.size() != temp.size())
        {
            return false;
        }
        while(!st.empty())
        {
            if(st.top() != temp.top())
            {
                return false;
            }
            st.pop();
            temp.pop();
        }
        return true;

    }
};