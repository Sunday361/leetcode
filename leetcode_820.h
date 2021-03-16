//
// Created by panrenhua on 3/16/21.
//

#ifndef LEETCODE_LEETCODE_820_H
#define LEETCODE_LEETCODE_820_H

#include "allheaders.h"
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        for (auto& word : words) {
            reverse(word.begin(), word.end());
        }

        sort(words.begin(), words.end());
        int count = 0;
        for (int i = 0; i < words.size(); i++) {
            if (i == 0) {
                count += words[0].size();
            }else {
                if (words[i - 1].size() > words[i].size() || words[i][0] != words[i - 1][0]) {
                    count += words[i].size() + 1;
                }else {
                    int j = 0;
                    for (; j < words[i - 1].size(); j++) {
                        if (words[i - 1][j] != words[i][j]) {
                            break;
                        }
                    }
                    if (j != words[i - 1].size()) {
                        count += words[i].size() + 1;
                    }else {
                        count += (words[i] - words[i - 1]);
                    }
                }
            }
        }
        return count + 1;
    }
};

#endif //LEETCODE_LEETCODE_820_H
