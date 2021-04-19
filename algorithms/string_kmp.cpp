#include <bits/stdc++.h>
using namespace std;

int KMPSearch(string txt, string pat) {
    int len_txt = txt.length();
    int len_pat = pat.length();
    // lps
    int* lps = new int[len_pat];
    for (int i = 0; i < len_pat; ++i) lps[i] = 0;
    int j = 0;
    for (int i = 1; i < len_pat; ++i) {
        if (pat[i] == pat[j]) {
            lps[i] = j + 1;
            ++j;
        } else {
            j = 0;
        }
    }
    // lps
    j = 0;
    for (int i = 0; i < len_txt; ++i) {
        if (txt[i] == pat[j]) {
            ++j;
            if (j == len_pat) return i - len_pat + 1;
        } else {
            if (j > 0) {
                j = lps[j - 1];
                --i;
            }
        }
    }
    return -1;
}

int main() {
    string txt = "AAABAAABAACABABCABAB";
    string pat = "AAABAAC";
    cout << KMPSearch(txt, pat);
    return 0;
}
