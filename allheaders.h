//
// Created by panrenhua on 2021/9/12.
//

#ifndef LEETCODE_ALLHEADERS_H
#define LEETCODE_ALLHEADERS_H
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#endif //LEETCODE_ALLHEADERS_H
