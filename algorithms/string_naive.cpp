#include <iostream>
using namespace std;

int match(string text, string pattern) {
    int length_text = text.length();
    int length_pattern = pattern.length();
    for (int i = 0; i < length_text - length_pattern + 1; ++i) {
        int j = 0;
        while (j < length_pattern && text[i + j] == pattern[j]) ++j;
        if (j == length_pattern) return i;
    }
    return -1;
}

int main() {
    string text = "qwertyuiop";
    string pattern = "iop";
    int index = match(text, pattern);
    cout << index << endl;
    return 0;
}