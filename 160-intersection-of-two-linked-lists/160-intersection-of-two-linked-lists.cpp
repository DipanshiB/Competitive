/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n1 = 0, n2 = 0;
        ListNode *ptrA = headA, *ptrB = headB;
        while(ptrA) {
            n1++;
            ptrA = ptrA -> next;
        }
        while(ptrB) {
            n2++;
            ptrB = ptrB -> next;
        }
        ptrA = headA; ptrB = headB;
        if(n1 > n2) {
            for(int i=0; i<n1-n2; i++) {
                ptrA = ptrA -> next;
            }
        }
        else {
            for(int i=0; i<n2-n1; i++) {
                ptrB = ptrB -> next;
            }
        }
        while(ptrA && ptrB) {
            if(ptrA == ptrB) return ptrA;
            ptrA = ptrA -> next;
            ptrB = ptrB -> next;
        }
        return NULL;
    }
};