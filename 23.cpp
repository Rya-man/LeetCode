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
    struct Compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};
public:
// ListNode* merge(ListNode* first,ListNode* second)
// {
//     if(!first)
//     return second;
//     if(!second)
//     return first;
//     ListNode* ans = new ListNode();
//     ListNode* p =ans;
//     while(first && second)
//     {
//         if(first->val < second->val)
//         {
//             p->next = first;
//             p=p->next;
//             first=first->next;
//         }
//         else{
//             p->next = second;
//             p=p->next;
//             second=second->next;
//         }

//     }
//     if(first)
//     {
//         p->next = first;
//     }
//     else if(second)
//     {
//         p->next= second;
//     }
//     return ans->next;
// }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
        if (lists.empty()) return nullptr;

        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

        for (ListNode* list : lists) {
            if (list)
                pq.push(list);
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();
            tail->next = node;
            tail = tail->next;

            if (node->next)
                pq.push(node->next);
        }

        return dummy.next;
    }
};
