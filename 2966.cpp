#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& v, int k) {
        ios::sync_with_stdio(false);
        sort(v.begin(), v.end());
        vector<vector<int>> result;
        int i,j=0;
         for(i=1;i<(v.size()-1);i+=3)
         {
             int temp=j;
             if(v[i]-v[i-1]<=k && v[i+1]-v[i]<=k && v[i+1]-v[i-1]<=k)
             {
                result.push_back({v[i-1],v[i],v[i+1]});
                j++;
             }
            if(temp==j)
            return {};
         }
         return result;
    }
};