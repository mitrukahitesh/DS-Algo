#include <iostream>
using namespace std;

#define base_value 256  // number of characters used in text and pattern
#define mod_value 101   // a prime number

int match(string text, string pattern) {
    int length_text = text.length();
    int length_pattern = pattern.length();
    int hash_pattern = 0, hash_text = 0,
        h = 1;  // h = pow(base_value, length_pattern - 1) % mod_value;
    for (int i = 0; i < length_pattern - 1; ++i) {
        h = (h * base_value) % mod_value;
    }
    for (int i = 0; i < length_pattern; ++i) {
        // for pattern
        hash_pattern = (hash_pattern * base_value + pattern[i]) % (mod_value);
        // for text
        hash_text = (hash_text * base_value + text[i]) % (mod_value);
    }
    cout << hash_pattern << endl << hash_text << endl;
    for (int i = 0; i < length_text - length_pattern + 1; ++i) {
        if (hash_text == hash_pattern) {
            int j = 0;
            while (text[i + j] == pattern[j]) {
                ++j;
                if (j == length_pattern) return i;
            }
        }
        if (i < length_text - length_pattern) {
            hash_text = (base_value * (hash_text - text[i] * h) +
                         text[length_pattern + i]) %
                        mod_value;
            if (hash_text < 0)  // if negative modulo
                hash_text = (hash_text + mod_value) % mod_value;
            cout << hash_text << endl;
        }
    }
    return -1;
}

int main() {
    string text = "bhuyakabhuyhaka";
    string pattern = "haka";
    int index = match(text, pattern);
    cout << index << endl;
    return 0;
}