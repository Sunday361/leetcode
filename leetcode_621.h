//
// Created by panrenhua on 2020/12/5.
//

#ifndef LEETCODE_LEETCODE_621_H
#define LEETCODE_LEETCODE_621_H

#include "allheaders.h"

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> m;
        for (int i = 0; i < tasks.size(); i++) {
            m[tasks[i]]++;
        }
        auto cmp = [&](char a, char b) {return m[a] > m[b];};
        priority_queue<char, vector<char>, decltype(cmp)> q{cmp};

        for (auto it = m.begin(); it != m.end(); it++) {
            q.push(it->first);
        }

        char c = q.top();
        q.pop();
        int len = (m[c] - 1) * n + m[c];
        while(!q.empty()) {
            char next = q.top();
            if (m[c] == m[next]) {
                len++;
            }else {
                break;
            }
        }
        return tasks.size() >  len ? tasks.size() : len;
    }
};

#endif //LEETCODE_LEETCODE_621_H
