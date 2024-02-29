Link:https://geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1

Code:
class Solution {
private:
    Node* reverse(Node* head) {
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;

        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    void insertAtTail(Node* &head, Node* &tail, int val) {
        Node* temp = new Node(val);
        if (head == NULL) {
            head = temp;
            tail = temp;
            return;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    Node* add(Node* first, Node* second) {
        int carry = 0;
        Node* ansHead = NULL;
        Node* ansTail = NULL;

        while (first != NULL || second != NULL || carry != 0) {
            int sum = carry;
            if (first != NULL) {
                sum += first->data;
                first = first->next;
            }
            if (second != NULL) {
                sum += second->data;
                second = second->next;
            }

            int digit = sum % 10;
            carry = sum / 10;
            insertAtTail(ansHead, ansTail, digit);
        }

        return ansHead;
    }

public:
    // Function to add two numbers represented by linked list.
    Node* addTwoLists(Node* first, Node* second) {
        first = reverse(first);
        second = reverse(second);

        Node* ans = add(first, second);

        ans = reverse(ans);

        return ans;
    }
};
