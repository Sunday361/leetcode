//
// Created by panrenhua on 2/5/21.
//

#ifndef LEETCODE_LEETCODE_457_H
#define LEETCODE_LEETCODE_457_H

#include "allheaders.h"
/** 457. 环形数组循环
 *
 * 快慢指针 我也不知道他的 O(n) 算法怎么搞
 * */
class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int len = nums.size();
        int direction;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                direction = 1;
            } else {
                direction = -1;
            }
            int fast = i, slow = i;
            while (nums[slow] * direction > 0 && nums[fast] * direction > 0) {
                //cout << fast << slow << endl;
                int pf = fast, ps = slow;
                slow = (slow + nums[slow] + 5000 * len) % len;
                fast = (fast + nums[fast] + 5000 * len) % len;
                if (slow == ps || fast == pf) break;
                if (nums[fast] * direction > 0) {
                    pf = fast;
                    fast = (fast + nums[fast] + 5000 * len) % len;
                    if (pf == fast) break;
                }else {
                    break;
                }
                if (fast == slow) return true;
            }
            nums[i] = 0;
        }
        return false;
    }
};
#endif //LEETCODE_LEETCODE_457_H
