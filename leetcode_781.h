//
// Created by panrenhua on 4/4/21.
//

#ifndef LEETCODE_LEETCODE_781_H
#define LEETCODE_LEETCODE_781_H
#include "allheaders.h"
/** 781. 森林中的兔子
 * */
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        sort(answers.begin(), answers.end());
        int ans = answers[0] + 1;
        int count = answers[0];
        for (int i = 1; i < answers.size(); i++) {
            if (answers[i] == answers[i - 1]) {
                if (count > 0) {
                    count--;
                }else {
                    ans += (answers[i] + 1);
                    count = answers[i];
                }
            }else {
                ans += (answers[i] + 1);
                count = answers[i];
            }
        }
        return ans;
    }
};
#endif //LEETCODE_LEETCODE_781_H
