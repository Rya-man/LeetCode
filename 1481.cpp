#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
    ios::sync_with_stdio(false);
    std::unordered_map<int, int> freqMap;

    // Count frequency of each element in the array
    for (int num : arr) {
        freqMap[num]++;
    }

    // Create a vector of pairs to hold frequency and value
    std::vector<std::pair<int, int>> freqVec;
    for (const auto& pair : freqMap) {
        freqVec.push_back(std::make_pair(pair.second, pair.first));
    }

    // Sort the vector in ascending order of frequency
    std::sort(freqVec.begin(), freqVec.end());

    // Calculate the number of unique integers to remove
    int uniqueIntegersToRemove = 0;
    for (const auto& pair : freqVec) {
        if (k >= pair.first) {
            k -= pair.first;
            uniqueIntegersToRemove++;
        } else {
            break; // If we can't remove anymore, break the loop
        }
    }

    // Return the remaining unique integers
    return freqMap.size() - uniqueIntegersToRemove;
    }
};