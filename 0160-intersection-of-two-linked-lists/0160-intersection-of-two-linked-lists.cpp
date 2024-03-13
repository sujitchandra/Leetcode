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
        ListNode* temp=headA;
        int l1=0,l2=0;
        while(temp!=NULL){
            temp=temp->next;
            l1++;
        }
        temp=headB;
        while(temp!=NULL){
            temp=temp->next;
            l2++;
        }
        if(l1>l2) swap(headA,headB);
        int diff = abs(l1-l2);
        while(diff!=0){
            headB=headB->next;
            diff--;
        }
        while(headA!=headB){
            headA=headA->next;
            headB=headB->next;
        }
        return headA;
    }
};