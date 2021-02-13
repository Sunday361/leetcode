//
// Created by panrenhua on 2/13/21.
//

#ifndef LEETCODE_LEETCODE_430_H
#define LEETCODE_LEETCODE_430_H

#include "allheaders.h"
/**
 * */
class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return head;
        Node* p = head;

        while (p->next && !p->child) {
            p = p->next;
        }
        if (p->child) {
            Node* child = flatten(p->child);
            Node* rear = child;
            Node* n = p->next;
            while (rear->next) rear = rear->next;
            p->child = nullptr;
            p->next = child;
            child->prev = p;
            rear->next = n;
            if (n) n->prev = rear;
        }
        return head;
    }
};
#endif //LEETCODE_LEETCODE_430_H
