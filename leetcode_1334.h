//
// Created by panrenhua on 2021/9/15.
//

#ifndef LEETCODE_LEETCODE_1334_H
#define LEETCODE_LEETCODE_1334_H
#include "allheaders.h"
/**
 * 1334. 阈值距离内邻居最少的城市
 * */
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        const int INF = 0x3f3f3f3f;
        int graph[n][n];
        memset(graph,INF,sizeof(graph));
        int dist[n];
        bool vis[n];
        for (vector<int> edge : edges) {
            int u=edge[0], v=edge[1], w=edge[2];
            graph[u][v] = graph[v][u] = w;
        }
        int idx = -1, minCnt = INF;
        for (int i=0; i<n; ++i) {
            memset(dist, INF, sizeof(dist));
            dist[i] = 0; //自身到自身的距离为0
            memset(vis, false, sizeof(vis));
            for (int j=0; j<n; ++j) {
                int u=-1, minDis = INF;
                for (int k=0; k<n; ++k) {
                    if (!vis[k] && dist[k] < minDis) {
                        u = k;
                        minDis = dist[k];
                    }
                }
                if (u==-1) {
                    break; //所有点不可达，直接结束，加速代码进程
                }
                vis[u] = true;
                for (int v=0; v<n; ++v) {
                    if (!vis[v]) {
                        dist[v] = min(dist[v], dist[u] + graph[u][v]);
                    }
                }
            }
            int cnt = 0;
            for (int j=0; j<n; ++j) {
                if (dist[j] <= distanceThreshold && i != j) {
                    cnt++;
                }
            }
            if (cnt <= minCnt) {
                minCnt = cnt;
                idx = i;
            }
        }
        return idx;
    }
};
#endif //LEETCODE_LEETCODE_1334_H
