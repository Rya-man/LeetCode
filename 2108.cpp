#include<bits/stdc++.h>
using namespace std;


class Solution {
 public:
  string firstPalindrome(vector<string>& words) {
    ios::sync_with_stdio(false);
    for (const string& word : words)
      if (isPalindrome(word))
        return word;
    return "";
  }

 private:
  bool isPalindrome(const string& s) {
    int i = 0;
    int j = s.length() - 1;
    while (i < j)
      if (s[i++] != s[j--])
        return false;
    return true;
  }
};