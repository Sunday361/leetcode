//
// Created by panrenhua on 4/9/21.
//

#ifndef LEETCODE_LEETCODE_154_H
#define LEETCODE_LEETCODE_154_H
#include "allheaders.h"
/** 154. 寻找旋转排序数组中的最小值 II
 * */
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left=0;
        int right=nums.size()-1;

        while(left<right){
            int mid=(left+right)/2;
            if(nums[mid]==nums[right]){
                right--;
            }else if(nums[mid]<nums[right]){
                right=mid;
            }else if(nums[mid]>nums[right]){
                left=mid+1;
            }
        }

        return nums[left];
    }
};
#endif //LEETCODE_LEETCODE_154_H
