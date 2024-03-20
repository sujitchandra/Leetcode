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
    ListNode *getIntersectionNode(ListNode *firstHead, ListNode *secondHead) {
         if(firstHead == NULL || secondHead ==NULL) return NULL;
        ListNode* d1 = firstHead, *d2 = secondHead;



        while(d1 != d2) {

            d1 = d1->next;
            d2 = d2->next;

            if (d1 == d2) return d1;

            if(d1 == NULL) d1 = secondHead;
            if(d2 == NULL) d2 = firstHead;
        }

        return d1;
    }
};