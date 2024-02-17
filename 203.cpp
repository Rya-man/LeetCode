#include<bits/stdc++.h>
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ios::sync_with_stdio(false);
        ListNode* temp;
        temp= new ListNode();
        while(head !=NULL&& head->val==val)
        {
            head= head->next;
        }
        if(head==NULL)
        return NULL;
        temp= head;
        while(temp->next!=NULL)
        {
            if(temp->next->val==val)
            {
                temp->next=temp->next->next;
            }
            else
            temp=temp->next;
        }
        return head;
    }
};