#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findTheWinner(int n, int k) {
        ios::sync_with_stdio(false);
        int winner = 0;
        for (int i = 1; i <= n; ++i)
        winner = (winner + k) % i;
        return winner + 1;
    }
};