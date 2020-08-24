#include <iostream>
using namespace std;

int match(string text, string pattern) {
	int length_text = text.length();
	int length_pattern = pattern.length();
	int lps[length_pattern];
	for (int i = 0; i < length_pattern; ++i)
		lps[i] = -1;
	for (int i = 1; i < length_pattern; ++i) {
		int j = 0;
		int k = i;
		while (pattern[k] == pattern[j]) {
			lps[k] = j;
			++j;
			++k;
		}
		if (k != i)
			i = k - 1;
	}
	int j = 0;
	for (int i = 0; i < length_text; ++i) {
		int k = i;
		while (text[k] == pattern[j]) {
			++j;
			++k;
			if (j == length_pattern)
				return k - length_pattern;
		}
		if (j > 0)
			j = lps[j - 1] + 1;
		if (k != i)
			i = k - 1;
	}
	return -1;
}

int main() {
	string text = "ABABDABACDABABCABAB";
	string pattern = "ABABCABAB";
	int index = match(text, pattern);
	cout << index << endl;
	return 0;
}