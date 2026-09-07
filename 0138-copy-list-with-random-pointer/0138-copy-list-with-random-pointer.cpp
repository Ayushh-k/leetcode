/*
// Definition for a Node.
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
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return head;

        Node* curr = head;

        while(curr!=nullptr){
            Node* copy = new Node(curr->val);

            copy->next = curr->next;
            curr->next = copy;

            curr = copy->next;
        }

        curr = head;

        while(curr!=nullptr){
            Node* copy = curr->next;

            if(curr->random != nullptr){
                copy->random = curr->random->next;
            }else{
                copy->random = nullptr;
            }

            curr = copy->next;
        }

        curr = head;
        Node* copyHead = head->next;

        while(curr!=nullptr){
            Node* copy = curr->next;

            curr->next = copy->next;

            if(copy->next != nullptr){
                copy->next = copy->next->next;
            }else{
                copy->next = nullptr;
            }

            curr = curr->next;
        }

        return copyHead;
    }
};