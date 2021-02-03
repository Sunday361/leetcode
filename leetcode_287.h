//
// Created by panrenhua on 2/2/21.
//

#ifndef LEETCODE_LEETCODE_287_H
#define LEETCODE_LEETCODE_287_H

#include "allheaders.h"
/** 287. 寻找重复数
 * */
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size() - 1;
        int left = 1, right = n;
        // 二分法 目标值为 mid
        // 根据抽屉原理 n+1 个抽屉放 n 种元素 必然会有 抽屉有重复元素
        // 二分法 小于等于 mid 的元素个数如果严格大于 mid 说明元素必然落在 1...mid之间
        while(left < right) {
            int count = 0;
            int mid = (left + right) / 2;
            for (int num : nums) {
                if (num <= mid) {
                    count++;
                }
            }
            if (count > mid) {
                right = mid;
            }else {
                left = mid + 1;
            }
        }
        return right;
    }
    // 快慢指针
    // head --------> entry ----meet----
    //                   ^             |
    //                   |             |
    //                   ---------------
    // c 为环的长度  a为 entry - head的长度 b 为快慢指针相遇点的到环入口的距离
    // fast slow 相遇时 所走路程为 n = a + c * k1 + b; 2n = a + c * k2 + b
    // 此时 n = c * k3 ==> a = k * c - b
    // 所以当快慢指针相遇时 一个指针从head出发 两者会在环的入口处相遇
    int _findDuplicate(vector<int>& nums) {
        int fast = 0, slow = 0;
        while(true){
            fast = nums[nums[fast]];
            slow = nums[slow];
            if(fast == slow)
                break;
        }
        int finder = 0;
        while(true){
            finder = nums[finder];
            slow = nums[slow];
            if(slow == finder)
                break;
        }
        return slow;
    }
};
#endif //LEETCODE_LEETCODE_287_H
