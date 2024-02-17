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