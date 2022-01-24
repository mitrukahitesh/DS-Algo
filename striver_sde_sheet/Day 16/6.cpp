#include <bits/stdc++.h>
using namespace std;

// Compare Version Numbers
// https://leetcode.com/problems/compare-version-numbers/

/*
    Shorter solution but takes more time
    https://leetcode.com/submissions/detail/626873024/
*/

int compareVersion(string version1, string version2)
{
    int i = 0, j = 0;
    while (i < version1.length() && j < version2.length())
    {
        int rev1 = 0;
        while (i < version1.length() && version1[i] != '.')
        {
            rev1 = rev1 * 10 + (version1[i] - '0');
            i++;
        }
        int rev2 = 0;
        while (j < version2.length() && version2[j] != '.')
        {
            rev2 = rev2 * 10 + (version2[j] - '0');
            j++;
        }
        if (rev1 < rev2)
            return -1;
        else if (rev1 > rev2)
            return 1;
        i++, j++;
    }
    if (i < version1.length())
    {
        while (i < version1.length())
        {
            while (i < version1.length() && version1[i] != '.')
            {
                if (version1[i] != '0')
                    return 1;
                i++;
            }
            i++;
        }
    }
    else if (j < version2.length())
    {
        while (j < version2.length())
        {
            while (j < version2.length() && version2[j] != '.')
            {
                if (version2[j] != '0')
                    return -1;
                j++;
            }
            j++;
        }
    }
    return 0;
}