//
// Created by panrenhua on 1/17/21.
//

#ifndef LEETCODE_LEETCODE_WEEKLY_CONTEST_224_H
#define LEETCODE_LEETCODE_WEEKLY_CONTEST_224_H

#include "allheaders.h"
/** leetcode-weekly-contest-234
 * */
class Solution {
public:
    int numDifferentIntegers(string word) {
        set<string> s;
        string temp;
        for (int i = 0; i < word.size(); i++) {
            if (isdigit(word[i])) {
                temp += word[i];
            }else {
                if (temp.size() != 0) {
                    while (temp[0] == '0' && temp.size() != 1) {
                        temp = temp.substr(1);
                    }
                    s.insert(temp);
                    temp = "";
                }
            }
        }
        if (temp.size() != 0) {
            while (temp[0] == '0' && temp.size() != 1) {
                temp = temp.substr(1);
            }
            s.insert(temp);
        }
        return s.size();
    }

    int reinitializePermutation(int n) {
        if (n == 2) return 1;
        vector<int> a(n);
        vector<int> p(n);

        for (int i = 0; i < n; i++) {
            p[i] = i;
        }
        int count = 0;
        while (1) {
            if (count % 2 == 0){
                for (int i = 0; i < n/2; i++) {
                    a[i*2] = p[i];
                    a[i*2 + 1] = p[n/2+i];
                }
                if (a[1] == 1) break;
            }else {
                for (int i = 0; i < n/2; i++) {
                    p[i*2] = a[i];
                    p[i*2 + 1] = a[n/2+i];
                }
                if (p[1] == 1) break;
            }
            count++;
        }
        return count;
    }

    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> m;
        string ans = "";
        for (int i = 0; i < knowledge.size(); i++) {
            m[knowledge[i][0]] = knowledge[i][1];
        }
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                int j = i;
                while (j < s.size() && s[j] != ')') {
                    j++;
                }
                string temp = s.substr(i + 1, j - i - 1);
                if (m.find(temp) != m.end()) {
                    ans.append(m[temp]);
                }else {
                    ans.append("?");
                }
                i = j;
            }else {
                ans += s[i];
            }
        }
        return ans;
    }

    #define MOD 1000000007
    typedef long long ll;
    ll qpow(ll a, ll n)
    {
        if (n == 0)
            return 1;
        else if (n % 2 == 1)
            return qpow(a, n - 1) * a % MOD;
        else
        {
            ll temp = qpow(a, n / 2) % MOD;
            return temp * temp % MOD;
        }
    }
    int maxNiceDivisors(int primeFactors) {
        if (primeFactors == 1) return 1;
        int k = primeFactors / 3;
        int l = primeFactors - (3 * k);

        if (l == 1) {
            k -= 1;
            l = 4;
        }

        long long ans = qpow(3, k);
        if (l)
            ans *= l;

        return ans % MOD;
    }
};

#endif //LEETCODE_LEETCODE_WEEKLY_CONTEST_224_H
