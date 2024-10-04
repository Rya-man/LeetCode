/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
 
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr)
        return NULL;
        ListNode* fast =head->next;
        ListNode* slow = head;
        while(fast!=nullptr)
        {
            
            int temp =slow->val;
            slow->val = fast->val;
            fast->val = temp;
            if(fast->next==NULL || fast->next->next==NULL)
            break;
            slow = slow->next->next;
            fast = fast->next->next;
        }
        return head;
    }
};
