//
// Created by panrenhua on 2020/12/8.
//

#ifndef LEETCODE_LEETCODE_842_H
#define LEETCODE_LEETCODE_842_H

/** 842. 将数组拆分成斐波那契序列
 * */

#include "allheaders.h"

class Solution {
public:
    const int mn = INT32_MAX;
    vector<int> splitIntoFibonacci(string S) {
        long long f1, f2;
        string s1, s2;
        if (S.size() < 3) return {};

        for (int i = 1; i < 11 && i <= S.size() / 2; i++) {
            //cout << i << endl;
            if (S[0] == '0' && i != 1) return {};
            s1 = S.substr(0, i);
            f1 = stoll(s1);
            if (f1 > mn) return {};
            for (int j = 1; j < 11 && j <= (S.size() - 2 * i); j++) {
                s2 = S.substr(i, j);
                f2 = stoll(s2);
                if (f2 > mn || (S[i] == '0' && j != 1)) break;

                vector<int> ans;

                f1 = stoi(s1);
                f2 = stoi(s2);
                ans.push_back(f1);
                ans.push_back(f2);
                //cout << f1 << " " << f2 << " " << endl;
                int u = i + j;
                while(u < S.size()) {
                    long long f3 = f1 + f2;
                    if (f3 > mn) return {};
                    else {
                        string s3 = to_string(f3);
                        if (s3 == S.substr(u, s3.size())){
                            f1 = f2;
                            f2 = f3;
                            ans.push_back(f2);
                            u += s3.size();
                            //cout << f1 << " " << f2 << " " << endl;
                        } else{
                            break;
                        }
                    }
                }

                if (u == S.size()) return ans;
            }
        }
        return {};
    }
};


#endif //LEETCODE_LEETCODE_842_H
