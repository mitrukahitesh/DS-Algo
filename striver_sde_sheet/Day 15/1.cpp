#include <bits/stdc++.h>
using namespace std;

// Reverse Words in a String
// https://leetcode.com/problems/reverse-words-in-a-string/submissions/

// O(n) space
string reverseWords(string s)
{
    int len = s.length();
    stack<string> st;
    string temp = "";
    for (int i = 0; i < len; ++i)
    {
        if (s[i] == ' ')
        {
            if (temp == "")
                continue;
            st.push(temp);
            temp = "";
        }
        else
        {
            temp.push_back(s[i]);
        }
    }
    while (!st.empty())
    {
        if (temp != "")
            temp = temp + " " + st.top();
        else
            temp = temp + st.top();
        st.pop();
    }
    return temp;
}

// O(1) space
string reverseWords(string s)
{
    reverse(s.begin(), s.end());
    int last = 0;
    for (int i = 0; i < s.length(); ++i)
    {
        int j = i;
        int cnt = 0;
        while (j < s.length() && s[j] == ' ')
            j++, cnt++;
        if (j == s.length())
            break;
        while (j < s.length() && s[j] != ' ')
            j++;
        reverse(s.begin() + i, s.begin() + j);
        i = j - cnt;
    }
    while (s.back() == ' ')
        s.pop_back();
    return s;
}