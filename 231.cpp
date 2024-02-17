#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool isPowerOfTwo(int n) {
        ios::sync_with_stdio(false);
       int cnt = 0; //num of bits 1
        for(; n>0; n>>=1){
            if ( n & 1 ) {
                cnt++;
                if (cnt>1) return false;
            }
        }
        return cnt==1;
    }
};