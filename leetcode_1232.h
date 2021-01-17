//
// Created by panrenhua on 1/17/21.
//

#ifndef LEETCODE_LEETCODE_1232_H
#define LEETCODE_LEETCODE_1232_H

#include "allheaders.h"
/** 1232. 缀点成线
 * */
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if (coordinates.size() == 2) return true;
        int dy = coordinates[0][1] - coordinates[1][1];
        int dx = coordinates[0][0] - coordinates[1][0];
        for (int i = 2; i < coordinates.size(); i++) {
            if ((coordinates[i][0] - coordinates[1][0]) * dy != (coordinates[i][1] - coordinates[1][1]) * dx) {
                return false;
            }
        }
        return true;
    }
};
#endif //LEETCODE_LEETCODE_1232_H
