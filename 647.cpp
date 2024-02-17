/*Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.

 

Example 1:

Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
Example 2:

Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 

Constraints:

1 <= s.length <= 1000
s consists of lowercase English letters.*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
    int ans = 0;

    for (int i = 0; i < s.length(); ++i) {
      ans += extendPalindromes(s, i, i);
      ans += extendPalindromes(s, i, i + 1);
    }

    return ans;
  }
private:
  int extendPalindromes(const string& s, int l, int r) {
    int count = 0;

    while (l >= 0 && r < s.length() && s[l] == s[r]) {
      ++count;
      --l;
      ++r;
    }

    return count;
  }
};