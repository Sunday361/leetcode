//
// Created by panrenhua on 2020/12/10.
//

#ifndef LEETCODE_LEETCODE_860_H
#define LEETCODE_LEETCODE_860_H

/**
 * 860. 柠檬水找零 */
#include "allheaders.h"
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int, int> m;
        if (bills[0] != 5) return false;
        m[5] = 1;
        for (int i = 1; i < bills.size(); i++) {
            if (bills[i] == 5) m[5]++;
            else if (bills[i] == 10) {
                if (m[5] == 0) return false;
                else {
                    m[5]--;
                    m[10]++;
                }
            }else if (bills[i] == 20) {
                if (m[10] != 0 && m[5] != 0) {
                    m[10]--;
                    m[5]--;
                }else if (m[10] == 0 && m[5] >= 3) {
                    m[5] -= 3;
                }else {
                    return false;
                }
            }
        }
        return true;
    }
};


#endif //LEETCODE_LEETCODE_860_H
