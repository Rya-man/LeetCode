/*Given an array of integers arr and an integer k. Find the least number of unique integers after removing exactly k elements.

 

Example 1:

Input: arr = [5,5,4], k = 1
Output: 1
Explanation: Remove the single 4, only 5 is left.
Example 2:
Input: arr = [4,3,1,1,3,3,2], k = 3
Output: 2
Explanation: Remove 4, 2 and either one of the two 1s or three 3s. 1 and 3 will be left.
 

Constraints:

1 <= arr.length <= 10^5
1 <= arr[i] <= 10^9
0 <= k <= arr.length*/

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