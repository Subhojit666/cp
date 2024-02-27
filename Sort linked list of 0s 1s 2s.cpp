- Sort 0s, 1s and 2s : https://bit.ly/3s3fAOu


//Approach 1:
void insertAtTail(Node* &tail, Node* curr){
    tail -> next = curr;
    tail = curr;
}


Node* sortList(Node *head){
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;
    
    Node* curr = head;
    while(curr != NULL){
        int value = curr -> data;
        if(value == 0){
            insertAtTail (zeroTail, curr);
        }
        else if(value == 1){
            insertAtTail (oneTail, curr);
        }
        if(value == 2){
            insertAtTail (twoTail, curr);
        }
        curr = curr -> next;
    }
    if(oneHead -> next != NULL){
        zeroTail -> next = oneHead -> next;
    }
    else {
        zeroTail -> next = twoHead -> next;
    }

    oneTail -> next = twoHead -> next;
    twoTail -> next = NULL;

    head = zeroHead -> next;

    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
    
}

//Approach 2:


Node* sortList(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* zeroDummy = new Node(0);
    Node* oneDummy = new Node(0);
    Node* twoDummy = new Node(0);
    Node* zeroTail = zeroDummy;
    Node* oneTail = oneDummy;
    Node* twoTail = twoDummy;

    Node* curr = head;

    while (curr != NULL) {
        if (curr->data == 0) {
            zeroTail->next = curr;
            zeroTail = curr;
        } else if (curr->data == 1) {
            oneTail->next = curr;
            oneTail = curr;
        } else {
            twoTail->next = curr;
            twoTail = curr;
        }
        curr = curr->next;
    }

    zeroTail->next = oneDummy->next != NULL ? oneDummy->next : twoDummy->next;
    oneTail->next = twoDummy->next;
    twoTail->next = NULL;

    head = zeroDummy->next;
    delete zeroDummy;
    delete oneDummy;
    delete twoDummy;

    return head;
}
