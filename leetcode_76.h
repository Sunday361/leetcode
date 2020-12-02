#ifndef CPP_LEETCODE_76_H
#define CPP_LEETCODE_76_H

#include "allheaders.h"
/* 76. 最小覆盖子串
 *  利用滑动窗口 两个指针 分别指向子字符串的头尾
 *  向右移动j使 字符串满足条件 再向右移动 i 使得子字符串仍满足条件
 *  最后子字符串不再满足条件 向右移动j 循环上一过程
 */
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> match, pattern;
        for (int i = 0; i < t.size(); i++) {
            match[t[i]]++;
        }
        int cnt = 0, front = 0, rear = 0, mindis = INT_MAX, start = 0, flag = 0;
        while (rear < s.size()) {
            if (match.find(s[rear]) != match.end()) {
                pattern[s[rear]]++;
                if (pattern[s[rear]] == match[s[rear]])
                    cnt++;
            }
            while (cnt == match.size()) {
                flag = 1;
                if (rear - front < mindis) {
                    mindis = rear - front;
                    start = front;
                }
                if (match.find(s[front]) != match.end()) {
                    pattern[s[front]]--;
                    if (pattern[s[front]] < match[s[front]])
                        cnt--;
                }
                front++;
            }
            rear++;
        }
        return flag?s.substr(start, mindis + 1):"";
    }
};

#endif //CPP_LEETCODE_76_H
