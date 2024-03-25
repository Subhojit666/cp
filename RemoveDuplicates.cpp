Node* removeDuplicates(Node* head) {
    if (head == NULL) {
        return NULL;
    }

    unordered_set<int> seen;
    Node* prev = NULL;
    Node* curr = head;

    while (curr != NULL) {
        if (seen.find(curr->data) != seen.end()) {
            // If current node's data is already seen, it's a duplicate
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        } else {
            // If not seen, add it to set and move forward
            seen.insert(curr->data);
            prev = curr;
            curr = curr->next;
        }
    }

    return head;
}

