#include<iostream>
#include<unordered_map>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr)return nullptr;
        Node* cur = head;
        unordered_map<Node*, Node*>map;
        while (cur) {
            map[cur] = new Node(cur->val);
            cur = cur->next;
        }
        cur = head;
        while (cur) {
            map[cur]->next = map[cur->next];
            map[cur]->random = map[cur->random];
            cur = cur->next;
        }
        return map[head];
    }
    Node* copyNormalList(Node* head) {
        Node* cur = head;
        Node* res = new Node(0),*pre=res;
        while (cur) {
            Node* node = new Node(cur->val);
            pre->next = node;
            cur = cur->next;
            pre = pre->next;
        }
        return res;
    }
};