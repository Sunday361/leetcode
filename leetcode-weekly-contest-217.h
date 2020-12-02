#ifndef CPP_LEETCODE_WEEKLY_CONTEST_217_H
#define CPP_LEETCODE_WEEKLY_CONTEST_217_H

#include "allheaders.h"

class Solution {
public:
    /* 5614. 找出最具竞争力的子序列
     * 单调栈 但是要做一点改变
     * 当目前栈内元素个数不满k时,需要往里面压栈
     * 出栈时也需要考虑剩余的元素的个数
     * */

    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> stack;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            while(stack.size() + len - i > k && stack.size() != 0 && nums[i] < stack.back()) {
                stack.pop_back();
            }
            if (stack.size() != k) {
                stack.push_back(nums[i]);
            }
        }
        return stack;
    }

    /* 5615. 使数组互补的最少操作次数
     * 用res[x]来代表当目标值为x时 需要的转换次数
     * 对于 nums[i] + nums[n - 1 - i] = A + B有三种情况(A<=B)
     * 1. res[x] += 2 (x < 1 + A || x > B + limit);
     * 2. res[x] += 1 (1 + A <= x <= B + limit);
     * 3. res[x] += 0 (x == A + B)
     *
     * 考虑到 遍历 x (2 <= x <= 2 * limit)
     * 可以用 差分数组来降低累加的复杂度
     *
     * diff[x] => res[x] = diff[0...x]
     *
     * 考虑 res[x] 在某个区间[0, y]全部加2 则有 diff[0] += 2, diff[y + 1] -= 2;
     * */

    int minMoves(vector<int>& nums, int limit) {

        // 差分数组, diff[0...x] 的和表示最终互补的数字和为 x，需要的操作数
        // 因为差分数组的计算需要更新 r + 1，所以数组的总大小在 limit * 2 + 1 的基础上再 + 1
        vector<int> diff(limit * 2 + 2, 0);

        int n = nums.size();
        for (int i = 0; i < n / 2; i++) {
            int A = nums[i], B = nums[n - 1 - i];

            // [2, 2 * limit] 范围 + 2
            int l = 2, r = 2 * limit;
            diff[l] += 2, diff[r + 1] -= 2;

            // [1 + min(A, B), limit + max(A, B)] 范围 -1
            l = 1 + min(A, B), r = limit + max(A, B);
            diff[l] += -1, diff[r + 1] -= -1;

            // [A + B] 再 -1
            l = A + B, r = A + B;
            diff[l] += -1, diff[r + 1] -= -1;
        }

        // 依次求和，得到 最终互补的数字和 i 的时候，需要的操作数 sum
        // 取最小值
        int res = n, sum = 0;
        for (int i = 2; i <= 2 * limit; i++) {
            sum += diff[i];
            if (sum < res) res = sum;
        }
        return res;
    }

    /* 5616. 数组的最小偏移量
     * 将数组全部转换为可能的最大值 再考虑将其缩小
     *
     * 正确性未知 ？？？？
     * */

    int minimumDeviation(vector<int>& nums) {
        set<int> s;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 1) {
                nums[i] = 2 * nums[i];
            }
            s.insert(nums[i]);
        }
        set<int>::iterator begin = s.begin();
        set<int>::reverse_iterator end = s.rbegin();
        int res = *end - *begin;
        while(*end % 2 == 0) {
            int p = *end;
            s.erase(s.find(p));
            p = p / 2;
            s.insert(p);
            set<int>::iterator begin = s.begin();
            set<int>::reverse_iterator end = s.rbegin();
            res = min(res, *end - *begin);
        }
        return res;
    }
};


#endif //CPP_LEETCODE_WEEKLY_CONTEST_217_H
