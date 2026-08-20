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
    ListNode* reverseList(ListNode* head) {

        // iterately reverse

        // ListNode* pre = nullptr;
        // ListNode* curr = head;
        // while(curr!=NULL){
        //     ListNode* temp = curr->next;
        //     curr->next = pre;
        //     pre = curr;
        //     curr = temp;
        // }

        // return pre;

        // reverse via recursion

        if(head==nullptr || head->next == nullptr){
            return head;
        }

        ListNode* newHead = reverseList(head->next);

        head->next->next = head;
        head->next = nullptr;

        return newHead;
    }
};