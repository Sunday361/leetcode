//
// Created by panrenhua on 2020/12/11.
//

#ifndef LEETCODE_LEETCODE_649_H
#define LEETCODE_LEETCODE_649_H

/** 649. Dota2 参议院
 *
 * */
#include "allheaders.h"
class Solution {
public:
    string predictPartyVictory(string senate) {
        int numD = 0, numR = 0;
        for (int i = 0; i < senate.size(); i++) {
            if (senate[i] == 'D') numD++;
            else numR++;
        }
        int index = 0;
        int r = 0, d = 0;
        for (;;) {
            if (senate[index] == 'D') {
                if (numR == 0) return "Dire";
                if (d == 0) {
                    r++;
                    numR--;
                    senate.push_back('D');
                }else {
                    d--;
                }
            }else {
                if (numD == 0) return "Radiant";
                if (r == 0) {
                    d++;
                    numD--;
                    senate.push_back('R');
                }else {
                    r--;
                }
            }
            index++;
            if (index == senate.size()) return "";
        }
        return "";
    }
};


#endif //LEETCODE_LEETCODE_649_H
