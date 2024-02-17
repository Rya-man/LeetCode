#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        ios::sync_with_stdio(false);
    unordered_map<string, vector<string>> anagramGroups;
    
    for (const auto& str : strs) {
        string sortedStr = str;
        sort(sortedStr.begin(), sortedStr.end());
        anagramGroups[sortedStr].push_back(str);
    }
    vector<vector<string>> result;
    for (auto& pair : anagramGroups) {
        result.push_back(pair.second);
    }
    return result;
    }
};