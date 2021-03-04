//
// Created by panrenhua on 3/4/21.
//

#ifndef LEETCODE_LEETCODE_165_H
#define LEETCODE_LEETCODE_165_H
#include "allheaders.h"
/** 165. 比较版本号
 * */
class Solution {
public:
    int compareVersion(string version1, string version2) {
        istringstream s1 = istringstream(version1);
        istringstream s2 = istringstream(version2);
        int n1, n2;
        char c;
        while (bool(s1 >> n1) + bool(s2 >> n2)) {
            if (n1 < n2) return -1;
            if (n1 > n2) return 1;
            n1 = n2 = 0;

            s1 >> c;
            s2 >> c;
        }
        return 0;
    }
};
#endif //LEETCODE_LEETCODE_165_H
