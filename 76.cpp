#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    string minWindow(string s, string t) {
    ios::sync_with_stdio(false);
        string win;
    if (s.size()<=0 || t.size()<=0 || t.size() > s.size()) return win;
    /*
     * Declare two "hash map" for ASCII chars
     *   window[]: represents the char found in string S
     *   dict[]: stores the chars in string T
     */    
    const int MAX_CHARS = 256;
    int window[MAX_CHARS], dict[MAX_CHARS];

    const int NOT_EXISTED   = -1;
    const int NOT_FOUND     =  0;
    memset(dict, NOT_EXISTED, sizeof(dict));
    memset(window, NOT_EXISTED, sizeof(window));

    /* 
     *  Go through the T, and inital the dict[] and window[] 
     *  Notes: a same char can be appeared multiple times.
     */
    for(int i=0; i<t.size(); i++) {
        dict[t[i]]==NOT_EXISTED ? dict[t[i]]=1 : dict[t[i]]++ ; 
        window[t[i]] = NOT_FOUND; 
    }

    int start =-1;
    int winSize = INT_MAX;
    int letterFound = 0;
    int left = 0;

    for(int right=0; right<s.size(); right++) {
        if ( dict[s[right]] == NOT_EXISTED ){
            continue;
        }

        /* if s[i] is existed in `t` */ 
        char chr = s[right];
        window[chr]++;

        /* if one char has been found enough times, then do not do letterFound++ */
        if (window[chr] <= dict[chr]) {
            letterFound++;
        }

        if ( letterFound >= t.size() ) {
            /* 
             * Find the left of the window - try to make the window smaller
             * 1) windows[S[left]] == NOT_EXISTED  ===> the char at the `left` is not in T
             * 2) window[S[left]] > dict[S[left]]   ===> a same char appeared more than excepted.
             */
            char chl = s[left];
            while ( window[chl] == NOT_EXISTED || window[chl] > dict[chl] ) { 
                if (dict[chl] != NOT_EXISTED  ) {
                    //move the left of window
                    window[chl]--; 
                    // reduce the number of letters found
                    if (window[chl] < dict[chl] ) letterFound--;
                }
                chl = s[++left];
            }

            /* Calculate the minimized window size */
            if(winSize > right - left + 1){
                start = left;
                winSize = right - left + 1;
            }

        }
    }

    if (start>=0 && winSize>0) {
        win = s.substr(start, winSize);
    }
    return win;
    }
};