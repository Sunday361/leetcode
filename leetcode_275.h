//
// Created by panrenhua on 2/11/21.
//

#ifndef LEETCODE_LEETCODE_275_H
#define LEETCODE_LEETCODE_275_H

#include "allheaders.h"
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int lo = 0, hi = n;
        while(lo < hi){
            int mi = (lo + hi) >> 1;
            if(n - mi <= citations[mi]) hi = mi;
            else lo = mi + 1;
        }
        return n - lo;
    }
};


#endif //LEETCODE_LEETCODE_275_H
