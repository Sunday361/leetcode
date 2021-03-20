//
// Created by panrenhua on 3/20/21.
//

#ifndef LEETCODE_LEETCODE_887_H
#define LEETCODE_LEETCODE_887_H
#include "allheaders.h"
/** 887. 鸡蛋掉落
 *
 * 对于一个鸡蛋, 在第 x 层掉落, 被分解为两个子问题
 * dp[k][n] k代表 鸡蛋的个数, n代表层数
 * dp[k][n] = 1 + min{1 <= x <= n}(max(dp[k][n - x], dp[k - 1][x - 1]))
 * 我们知道 dp[k][n - x] 随着 x增大而减小, dp[k - 1][x - 1] 随着 x增大 而增大
 * 所以应该在相交处的值的最大值才是最小值
 *  int lo = 1, hi = n;
 *  利用二分查找, 当 dp[k][n - x] > dp[k - 1][x - 1] => lo = mid
 *                 dp[k][n - x] < dp[k - 1][x - 1] => hi = mid
 *                 dp[k][n - x] = dp[k - 1][x - 1] => lo = hi = mid
 * */
class Solution {
    unordered_map<int, int> memo;
    int dp(int K, int N) {
        if (memo.find(N * 100 + K) == memo.end()) {
            int ans;
            if (N == 0) ans = 0;
            else if (K == 1) ans = N;
            else {
                int lo = 1, hi = N;
                while (lo + 1 < hi) {
                    int x = (lo + hi) / 2;
                    int t1 = dp(K-1, x-1);
                    int t2 = dp(K, N-x);

                    if (t1 < t2) lo = x;
                    else if (t1 > t2) hi = x;
                    else lo = hi = x;
                }

                ans = 1 + min(max(dp(K-1, lo-1), dp(K, N-lo)),
                              max(dp(K-1, hi-1), dp(K, N-hi)));
            }

            memo[N * 100 + K] = ans;
        }

        return memo[N * 100 + K];
    }
public:
    int superEggDrop(int K, int N) {
        return dp(K, N);
    }
};
#endif //LEETCODE_LEETCODE_887_H
