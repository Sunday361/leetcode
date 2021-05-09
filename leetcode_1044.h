//
// Created by panrenhua on 3/31/21.
//

#ifndef LEETCODE_LEETCODE_1044_H
#define LEETCODE_LEETCODE_1044_H
#include "allheaders.h"
/** 1044. 最长重复子串
 * */
const int N = 100000+10;
int bucket[N];//桶。用于桶排序
int suffix_array[N];//后缀数组。排在i的是哪个后缀。
int ranks[N];//排名数组。后缀i排名是多少
int tmp[N];
int height[N];//height[i]=suffix(sa[i-1])和 suffix(sa[i])的最长公共前缀，也就是排名相邻的两个后缀的最长公共前缀。
class Solution {
public:

    //计算后缀数组
    void get_suffix_sa(const string& s){
        const int n = s.size();
        //单字符前缀
        //单字符桶排序。
        int bucket_cnt = 256;
        for(int i=0;i<bucket_cnt;++i) bucket[i] = 0;
        for(int i=0;i<n;++i){
            ++bucket[s[i]];
        }
        for(int i=1;i<bucket_cnt;++i){
            bucket[i] += bucket[i-1];
        }
        //根据桶排序的结果构造后缀数组
        for(int i=n-1;i>=0;--i){
            suffix_array[--bucket[s[i]]] = i;
        }
        //借助后缀数组，计算排名数组
        int rank_no = 1;
        ranks[suffix_array[0]] = 0;
        for(int i=1;i<n;++i){
            if(s[suffix_array[i-1]] == s[suffix_array[i]]){//相同字符，排名相同
                ranks[suffix_array[i]] = rank_no-1;
            }else{
                ranks[suffix_array[i]] = rank_no++;
            }
        }
        //2*len长度的前缀串
        int len = 1;
        for(;len <= n;len *= 2){
            int* first_key_sorted = tmp;
            //前缀串由两个len长的key1和key2拼接成。要对前缀串排序。
            //key2先排序。上一轮的suffix_array就已经确定key2的顺序了。
            //现在借助上一轮的suffix_array，按key2顺序取出对应的key1。

            int p=0;
            for(int i=n - len;i<n;++i){//越界的key2，对应的key1一定排在最前面
                first_key_sorted[p++] = i;//取对应的key1
            }
            for(int i=0;i<n;++i){
                if(suffix_array[i] >= len){//未越界的key2，对应的key1 等于 suffix_array[i] - len
                    first_key_sorted[p++] = suffix_array[i] - len;
                }
            }

            //至此，first_key_sorted中放置了，已按key2排好序的key1。
            //在对key1的ranks进行桶排序
            for(int i=0;i<bucket_cnt;++i) bucket[i] = 0;
            for(int i=0;i<n;++i){
                ++bucket[ranks[first_key_sorted[i]]];
            }
            for(int i=1;i<bucket_cnt;++i){
                bucket[i] += bucket[i-1];
            }
            //根据桶排序的结果构造后缀数组
            for(int i= n-1;i>=0;--i){
                suffix_array[--bucket[ranks[first_key_sorted[i]]]] = first_key_sorted[i];
            }
            //借助suffix_array和上一轮的ranks，计算新的rank
            int* new_rank=tmp;
            new_rank[suffix_array[0]] = 0;
            int rank_no = 1;
            for(int i=1;i<n;++i){
                //key1和key2的ranks都相等时，新排名相同。
                if(ranks[suffix_array[i-1]] ==  ranks[suffix_array[i]]
                   && max(suffix_array[i-1],suffix_array[i]) + len < n //key2越界的算不同排名
                   && ranks[suffix_array[i-1]+len] == ranks[suffix_array[i]+len]){
                    new_rank[suffix_array[i]] = rank_no-1;
                }else{
                    new_rank[suffix_array[i]] = rank_no++;
                }
            }
            for(int i=0;i<n;++i){//复制到ranks
                ranks[suffix_array[i]] = new_rank[suffix_array[i]];
            }
            bucket_cnt = rank_no;//增加桶，这步很重要
            if(rank_no >= n){//排名全部确定了，不用再算了。
                //printf("done!\n");
                break;
            }
        }
    }

    //计算height数组
    //height[i]=suffix(sa[i-1])和 suffix(sa[i])的最长公共前缀，也就是排名相邻的两个后缀的最长公共前缀。
    //这里借助h[i]=height[rank[i]]，也就是 suffix(i)和在它前一名的后缀的最长公共前缀
    //用递推的方式计算。
    void getHeight(const string& s){
        const int n = s.size();
        int len = 0;//h[i]
        height[0] = 0;
        for(int i = 0;i < n;++i){
            if(len){
                len--;//h[i-1] - 1
            }
            int rk = ranks[i];
            if(rk - 1 >= 0){
                int j = suffix_array[rk - 1];//排在ranks[i] - 1的后缀串j
                while(i+len < n && j + len < n &&
                      s[i+len] == s[j+len]){//计算后缀i与后缀j的LCP
                    ++len;
                }
                height[rk] = len;
            }else{
                height[rk] = len;
            }
        }
    }

    string longestDupSubstring(string S) {
        get_suffix_sa(S);
        getHeight(S);
        int p=0;
        int len = 0;
        for(int i=0;i<S.size();++i){
            if(height[i] > len){
                len = height[i];
                p = suffix_array[i];
            }
        }
        return S.substr(p,len);
    }
};
#endif //LEETCODE_LEETCODE_1044_H
