#include <bits/stdc++.h>
using namespace std;

// Check balanced parantheses
// O(n) time, O(n) space

bool isValid(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            st.push(s[i]);
        else
        {
            if (st.empty())
                return false;
            if (s[i] == ')' && st.top() != '(')
                return false;
            else if (s[i] == '}' && st.top() != '{')
                return false;
            else if (s[i] == ']' && st.top() != '[')
                return false;
            st.pop();
        }
    }
    return st.empty();
}