//
// Created by panrenhua on 1/17/21.
//

#ifndef LEETCODE_LEETCODE_WEEKLY_CONTEST_224_H
#define LEETCODE_LEETCODE_WEEKLY_CONTEST_224_H

#include "allheaders.h"
/** leetcode-weekly-contest-233
 * */
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans = nums[0];
        int sum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                sum += nums[i];
            }else {
                ans = max(ans, sum);
                sum = nums[i];
            }
        }
        ans = max(sum, ans);
        return ans;
    }
    /** [[26,7,0],[16,1,1],[14,20,0],[23,15,1],[24,26,0],[19,4,1],[1,1,0]]
     * */
    const int N = 1e9 + 7;
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        auto cmp1 = [&](vector<int>& a, vector<int>& b) {
            return a[0] >= b[0];
        };
        auto cmp2 = [&](vector<int>& a, vector<int>& b) {
            return a[0] <= b[0];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp1)> sells{cmp1};
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp2)> buys{cmp2};

        for (auto& order : orders) {
            if (order[2] == 1) {
                int amount = order[1];
                while (amount > 0 && !buys.empty() && buys.top()[0] >= order[0]) {
                    auto top = buys.top();
                    buys.pop();

                    while (amount > 0 && top[1] > 0) {
                        amount--;
                        top[1]--;
                    }
                    if (top[1] > 0) {
                        buys.push(top);
                    }
                }
                if (amount != 0)
                    sells.push({order[0], amount});
            }else {
                int amount = order[1];
                while (amount > 0 && !sells.empty() && sells.top()[0] <= order[0]) {
                    auto top = sells.top();
                    sells.pop();

                    while (amount > 0 && top[1] > 0) {
                        amount--;
                        top[1]--;
                    }
                    if (top[1] > 0) {
                        sells.push(top);
                    }
                }
                if (amount != 0)
                    buys.push({order[0], amount});
            }
        }
        long long ans = 0;
        while (!sells.empty()) {
            ans += sells.top()[1];
            sells.pop();
        }
        while (!buys.empty()) {
            ans += buys.top()[1];
            buys.pop();
        }
        return ans % N;
    }

    int maxValue(int n, int index, int maxSum) {
        int lo = 1, hi = maxSum + 1;
        // 最大值加1
        while (lo < hi) {
            long long mid = (lo + hi) / 2;
            long long sum = 0;
            if (mid >= index + 1) {
                sum += ((mid + mid - index) * (index + 1) / 2);
            }else {
                sum += ((mid + 1) * mid / 2);
                sum += (index + 1 - mid);
            }

            if (mid >= n - index) {
                sum += ((mid + mid - n + index + 1) * (n - index) / 2);
            }else {
                sum += ((mid + 1) * mid / 2);
                sum += (n - index - mid);
            }
            sum -= mid;

            if (sum > maxSum) {
                hi = mid;
            }else {
                lo = mid + 1;
            }
        }
        return lo - 1;
    }
};

#endif //LEETCODE_LEETCODE_WEEKLY_CONTEST_224_H
