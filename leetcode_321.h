#ifndef LEETCODE_LEETCODE_321_H
#define LEETCODE_LEETCODE_321_H

#include "allheaders.h"

/* 321. 拼接最大数
 * lexicographical_compare(*begin1, *end1, *begin2, *end2)
 * compare the dictionary order of two vectors
 *
 * the typical method of find max k sub sequence of a sequence
 *
 * vector<int> maxKSequence(vector<int> v, int k){
        int n = v.size();
        if (n <= k)
            return v;
        vector<int> res;
        int pop = n - k;
        for (int i = 0; i < n; i++) {
            while(!res.empty() && v[i]>res.back() && n - i + res.size() > k)
                res.pop_back();
            if (res.size() < k) res.push_back(v[i]);
        }
        return res;
    }
 * similar to
 * 316. 去除重复字母（困难）
   321. 拼接最大数（困难）
   402. 移掉 K 位数字（中等）
   1081. 不同字符的最小子序列（中等）
 * */

class Solution {
public:
    vector<int> maxKsequence(vector<int> v, int k){
        int n = v.size();
        if (n <= k)
            return v;
        vector<int> res;
        int pop = n - k;
        for (int i = 0; i < n; i++) {
            while(!res.empty() && v[i]>res.back() && n - i + res.size() > k)
                res.pop_back();
            if (res.size() < k) res.push_back(v[i]);
        }
        return res;
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> res(k);
        int len1 = nums1.size(), len2 = nums2.size();
        for(int i = 0; i <= k; i++) {
            if(i <= len1 && k - i <= len2){
                vector<int> s1 = maxKsequence(nums1, i);
                vector<int> s2 = maxKsequence(nums2, k - i);
                vector<int> u;
                auto it1 = s1.begin(), it2 = s2.begin();
                while(u.size() != k) {
                    u.push_back(lexicographical_compare(it1, s1.end(), it2, s2.end()) ? *it2++ : *it1++);
                }
                if(lexicographical_compare(res.begin(), res.end(), u.begin(), u.end()))
                    res = u;
            }
        }
        return res;
    }
};

#endif //LEETCODE_LEETCODE_321_H
