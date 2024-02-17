#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
    ios::sync_with_stdio(false);
    vector<int> count(26, 0); // Assuming only lowercase letters, adjust for other characters
    vector<int> index(26, -1); // Store the first occurrence index

    for (int i = 0; i < s.length(); ++i) {
        char c = s[i];
        count[c - 'a']++;

        if (index[c - 'a'] == -1) {
            index[c - 'a'] = i;
        }
    }

    int result = INT_MAX;

    for (int i = 0; i < 26; ++i) {
        if (count[i] == 1) {
            result = min(result, index[i]);
        }
    }

    return (result == INT_MAX) ? -1 : result;
    }
};