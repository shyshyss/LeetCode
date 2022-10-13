//¿ìÂýÖ¸Õë
#include<iostream>
using namespace std;

typedef struct ListNode {
    int val;
    ListNode * next;
}ListNode;

ListNode* creat() {
    ListNode* head = (ListNode*)malloc(sizeof(ListNode));
    head->next = NULL;
    return head;
}
void insert(ListNode* head, int n) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->val = n;
    node->next = head->next;
    head->next = node;
}
 
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* fp = head->next;
        ListNode* sp = head->next;
        while (fp && fp->next) {
            fp = fp->next->next;
            sp = sp->next;
        }
        return sp;
    }
};
void main()
{
    ListNode* l1 = creat();
    ListNode* mp = NULL;
    int i;
    Solution a;
    for (i = 1; i < 5; i++) {
        insert(l1, i);
    }
    ListNode* p=l1->next;
    while (p) {
        cout << p->val << endl;
        p = p->next;
    }
    mp = a.middleNode(l1);
    cout << mp->val << endl;
    
}