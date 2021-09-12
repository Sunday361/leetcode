//
// Created by panrenhua on 2021/9/12.
//

#ifndef LEETCODE_LEEETCODE_678_H
#define LEETCODE_LEEETCODE_678_H
/**678. 有效的括号字符串
*/
class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<bool>> f(n + 1, vector<bool>(n + 1));
        f[0][0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= i; j++) {
                if (s[i - 1] == '(') {
                    if (j - 1 >= 0) f[i][j] = f[i - 1][j - 1];
                }else if (s[i - 1] == ')') {
                    if (j + 1 <= i) f[i][j] = f[i - 1][j + 1];
                }else if (s[i - 1] == '*') {
                    f[i][j] = f[i - 1][j];
                    if (j - 1 >= 0) f[i][j] ||= f[i - 1][j - 1];
                    if (j + 1 <= i) f[i][j] ||= f[i - 1][j + 1];
                }
            }
        }
        return f[n][0];
    }
};

#endif //LEETCODE_LEEETCODE_678_H
