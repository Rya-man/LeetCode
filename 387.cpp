/*Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

 

Example 1:

Input: s = "leetcode"
Output: 0
Example 2:

Input: s = "loveleetcode"
Output: 2
Example 3:

Input: s = "aabb"
Output: -1
 

Constraints:

1 <= s.length <= 105
s consists of only lowercase English letters.
*/
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