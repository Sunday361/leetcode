//
// Created by panrenhua on 3/4/21.
//

#ifndef LEETCODE_LEETCODE_81_H
#define LEETCODE_LEETCODE_81_H
#include "allheaders.h"
/** 81. 搜索旋转排序数组 II
 *
 * 旋转数组至少有一半是有序的
 * */
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            //这部分最关键 删除重复的数字
            while (l < r && nums[l + 1] == nums[l]) l++;
            while (l < r && nums[r - 1] == nums[r]) r--;

            int mid = (l + r) / 2;
            if (nums[mid] == target) return true;
            if (nums[mid] >= nums[l]) { //前有序
                if (target < nums[mid] && target >= nums[l]) {
                    r = mid - 1;
                }else {
                    l = mid + 1;
                }
            }else { // 后有序
                if (target > nums[mid] && target <= nums[r]) {
                    l = mid + 1;
                }else {
                    r = mid - 1;
                }
            }
        }
        return false;
    }
};
#endif //LEETCODE_LEETCODE_81_H
