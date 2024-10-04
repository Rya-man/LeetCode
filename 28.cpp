class Solution {
public:
    int strStr(string haystack, string needle) {
        int start=0;
        int end=needle.size()-1;

        while(end<haystack.size())
        {
            if(haystack.substr(start,end-start+1)==needle)
            return start;
            start++;
            end++;
        }
        return -1;
    }
};
