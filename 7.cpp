/*
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

 

Example 1:

Input: x = 123
Output: 321
Example 2:

Input: x = -123
Output: -321
Example 3:

Input: x = 120
Output: 21
 

Constraints:

-231 <= x <= 231 - 1
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        ios::sync_with_stdio(false);
    int y=0;
    // int n;
    while( x != 0){
        // n = x%10;
        if (y > INT_MAX/10 || y < INT_MIN/10){
            return 0;
        }
        y = y*10 + x%10;
        x /= 10;
    }
    return y;
    }
};