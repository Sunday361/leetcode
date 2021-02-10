//
// Created by panrenhua on 2/10/21.
//

#ifndef LEETCODE_LEETCODE_475_H
#define LEETCODE_LEETCODE_475_H

#include "allheaders.h"
/** 475. 供暖器
 * */
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int left = 0, right = INT32_MAX;
        sort(heaters.begin(), heaters.end());
        sort(houses.begin(), houses.end());
        while (left < right) {
            int mid = (left + right) / 2;
            int index = 0;
            int up, down;
            for (int i = 0; i < heaters.size(); i++) {
                up = heaters[i] - mid;
                down = heaters[i] + mid;
                while (index < houses.size() && houses[index] >= up && houses[index] <= down) {
                    index++;
                }
            }
            if (index != houses.size()) {
                left = mid + 1;
            }else {
                right = mid;
            }
        }
        return left;
    }
};
#endif //LEETCODE_LEETCODE_475_H
