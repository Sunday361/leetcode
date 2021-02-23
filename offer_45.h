//
// Created by panrenhua on 2/22/21.
//

#ifndef LEETCODE_OFFER_45_H
#define LEETCODE_OFFER_45_H
#include "allheaders.h"
/**
 * */
class Solution {
public:
    string minNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [&](int x, int y) {
            if (x == y) return true;
            string sx(to_string(x) + to_string(y));
            string sy(to_string(y) + to_string(x));
            return sx < sy;
        });

        string ans = "";
        for (auto& num : nums) {
            ans += to_string(num);
        }
        return ans;
    }
};
class Solution1 {
public:
    string minNumber(vector<int>& nums) {
        vector<string> ss;

        for (auto& num : nums) {
            ss.emplace_back(to_string(num));
        }

        sort(ss.begin(), ss.end(), [&](string s1, string s2) {
            return s1 + s2 < s2 + s1;
        });
        string ans = "";
        for (auto& s : ss) {
            ans += s;
        }
        return ans;
    }
};
#endif //LEETCODE_OFFER_45_H
