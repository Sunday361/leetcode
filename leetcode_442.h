//
// Created by panrenhua on 3/19/21.
//

#ifndef LEETCODE_LEETCODE_442_H
#define LEETCODE_LEETCODE_442_H
#include "allheaders.h"
/** 442. 数组中重复的数据
 * 原地索引, 两次的, 三次的, n次的都可以解决了
 * */
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        for(int i = 0; i < nums.size(); i++){ // 直接原地索引了
            nums[(nums[i] - 1) % n] += n;
        }
        for(int i = 0 ;i < nums.size(); i++){
            if(nums[i] > 2 * n) res.push_back(i + 1);
        }
        return res;
    }
};
#endif //LEETCODE_LEETCODE_442_H
