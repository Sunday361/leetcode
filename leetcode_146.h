//
// Created by panrenhua on 3/4/21.
//

#ifndef LEETCODE_LEETCODE_146_H
#define LEETCODE_LEETCODE_146_H
#include "allheaders.h"
/** 146. LRU
 * */
class LRUCache {
public:
    struct node{
        int key;
        int val;
        struct node* next;
        struct node* prev;
        node(int key, int val):key(key), val(val), next(NULL),prev(NULL) {}
    };
    unordered_map<int, node*> mp;
    node* head;
    int capcity_;
    LRUCache(int capacity) {
        capcity_ = capacity;
        head = new node(0, 0);
        head->next = head->prev = head;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;
        else {
            addBefore(mp[key]);
            return mp[key]->val;
        }
    }

    void deleteAfter(){
        node* p = head->prev;
        p->prev->next = head;
        head->prev = p->prev;
        p->prev = p->next = NULL;
        delete p;
    }

    void addBefore(node* p) {
        if (p->next != NULL) {
            p->next->prev = p->prev;
            p->prev->next = p->next;
            p->next = p->prev = NULL;
        }
        head->next->prev = p;
        p->next = head->next;
        head->next = p;
        p->prev = head;
    }

    void put(int key, int value) {
        if (mp.find(key) == mp.end()) {
            mp[key] = new node(key, value);
            if (mp.size() > capcity_) {
                mp.erase(mp.find(head->prev->key));
                deleteAfter();
            }
            addBefore(mp[key]);
        }else {
            mp[key]->val = value;
            addBefore(mp[key]);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
#endif //LEETCODE_LEETCODE_146_H
