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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if(head->next==nullptr){
            delete head;
            return nullptr;
        }
        ListNode* temp = head;
        int cnt = 0;

        while(temp!=nullptr){
            cnt++;
            temp = temp->next;
        }

        int nodeToBeRemoved = cnt - n;
        if(nodeToBeRemoved==0){
            ListNode* temp = head;
            head = head->next;
            temp->next = nullptr;
            delete temp;
        }

        cnt = 0;
        temp = head;
        while(cnt!=nodeToBeRemoved-1 && temp!=nullptr){
            cnt++;
            temp = temp->next;
        }

        if(temp!=nullptr && temp->next!=nullptr){
            ListNode* nodeToBeDelete = temp->next;
            temp->next = temp->next->next;
            delete nodeToBeDelete;
        }

        return head;
    }
};