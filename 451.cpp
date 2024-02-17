/*
Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.

 

Example 1:

Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
 

Constraints:

1 <= s.length <= 5 * 105
s consists of uppercase and lowercase English letters and digits.
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    string frequencySort(string s) {
        ios::sync_with_stdio(false);
    unordered_map<char, int> charCount;
    for (char c : s) {
        charCount[c]++;
    }
    vector<pair<char, int>> sortedChars(charCount.begin(), charCount.end());
    sort(sortedChars.begin(), sortedChars.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });
    string sortedStr;
    for (const auto& p : sortedChars) {
        sortedStr += std::string(p.second, p.first);
    }

    return sortedStr;
    }
};