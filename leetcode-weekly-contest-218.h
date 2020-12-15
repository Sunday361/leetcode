//
// Created by panrenhua on 2020/12/6.
//

#ifndef LEETCODE_LEETCODE_WEEKLY_CONTEST_218_H
#define LEETCODE_LEETCODE_WEEKLY_CONTEST_218_H

#include "allheaders.h"

/**
 *
 * */
class Solution1 {
public:
    string interpret(string command) {
        string ans = "";
        for (int i = 0; i < command.size(); ) {
            if (command[i] == '(') {
                if (command[i + 1] == ')') {
                    ans.push_back('o');
                    i += 2;
                }else {
                    ans.append("al");
                    i += 4;
                }
            }else if (command[i] == 'G'){
                ans.push_back('G');
                i += 1;
            }
        }
        return ans;
    }
};

/**
 *
 * */

class Solution2 {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (m[k - nums[i]] > 0 && k - nums[i] != nums[i]) {
                m[k - nums[i]]--;
                m[nums[i]]--;
                count++;
            }else if (m[k - nums[i]] >= 2 && k - nums[i] == nums[i]){
                m[nums[i]] -= 2;
                count++;
            }
        }

        return count;
    }
};

/**
 *
 * */

class Solution {
public:
    int concatenatedBinary(int n) {
        string res = "";

        for (int i = 1; i <= n; i++) {
            string num = "";

            while(i != 0) {
                num.push_back(i % 2 + '0');
                i = i / 2;
            }
            reverse(num.begin(), num.end());

            res.append(num);
        }

        cout << res;
        return 0;
    }
};

#endif //LEETCODE_LEETCODE_WEEKLY_CONTEST_218_H
