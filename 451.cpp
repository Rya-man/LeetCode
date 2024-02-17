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