//
// Created by panrenhua on 2020/11/30.
//

#ifndef CPP_LEETCODE_767_H
#define CPP_LEETCODE_767_H
#include "allheaders.h"
/* 767. 重构字符串
 * 优先队列初始化
 * priority_queue<char, vector<char>, decltype(cmp)> c{cmp};
 * 或者 priority_queue<char, vector<char>, cmp> c; 但是此时 cmp 需要声明为一个仿函数
 *
 * 因为 decltype 返回的是一个参数类型 而仿函数是一个类 同样是参数类型 常用 decltype(auto ...)
 *
 * template <class T, class Container = vector<T>,
 * class Compare = less<typename Container::value_type> > class priority_queue;
 * */

class Solution {
public:
    string reorganizeString(string S) {
        vector<int> m = vector<int>(26, 0);
        string ans = "";
        auto cmp = [&](char a, char b) {return m[a - 'a'] < m[b - 'a'];};
        priority_queue<char, vector<char>, decltype(cmp)> c{cmp};
        for (int i = 0; i < S.size(); i++) {
            m[S[i] - 'a']++;
            if (S.size() % 2 == 0 && m[S[i] - 'a'] > S.size() / 2) return ans;
            if (S.size() % 2 == 1 && m[S[i] - 'a'] > S.size() / 2 + 1) return ans;
        }
        for (int i = 0; i < 26; i++) {
            if (m[i] != 0) c.push('a' + i);
        }
        while(!c.empty()) {
            char u = c.top(), v;
            c.pop();
            if (c.empty()) ans.push_back(u);
            else {
                v = c.top();
                c.pop();
                if (u == ans.back()) {
                    ans.push_back(v);
                    ans.push_back(u);
                }else {
                    ans.push_back(u);
                    ans.push_back(v);
                }
                m[v - 'a']--; m[u - 'a']--;
                if (m[v - 'a'] != 0) c.push(v);
                if (m[u - 'a'] != 0) c.push(u);
            }
        }
        return ans;
    }
};

#endif //CPP_LEETCODE_767_H
