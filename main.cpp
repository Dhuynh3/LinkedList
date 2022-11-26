#include <iostream>

// Taken from leetcode
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class SingleLinkedList {
public:
    ListNode* head;
    ListNode* tail;

    SingleLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void InsertNode(ListNode* new_node, int x);

    void PrependNode(ListNode* new_node, int x);

    void DeleteNode(int x);

    void InsertAfterNode(ListNode* current_node, ListNode* new_node, int x);

    void RemoveAfterNode(ListNode* current_node);
};

void SingleLinkedList::InsertNode(ListNode* new_node, int x) {

    new_node->val = x;
    new_node->next = nullptr;

    if (this->head == nullptr) { // If head is null, we're inserting the first node in the list.

        this->head = new_node;
        this->tail = new_node;
       
    }
    else { // Not first node inserted in the list

        this->tail->next = new_node; // Set current tail's next to the new node
        this->tail = new_node; // The new node is our tail now.
      
    }

}

void SingleLinkedList::PrependNode(ListNode* new_node, int x) {

    new_node->val = x;
    new_node->next = nullptr;

    if (this->head == nullptr) {

        this->head = new_node;
        this->tail = new_node;

    }
    else {

        new_node->next = this->head; // First we set the new node's next to the head.
        this->head = new_node; // The head of the node is now the new node

    }

}

void SingleLinkedList::DeleteNode(int x) {

}

void SingleLinkedList::InsertAfterNode(ListNode* current_node, ListNode* new_node, int x) {

    new_node->val = x;

    if (this->head == nullptr) {

        this->head = new_node;
        this->tail = new_node;

    }
    else if (this->tail == current_node) { // Inserting after the tail

        this->tail->next = new_node;
        this->tail = new_node;

    } else {

        new_node->next = current_node->next;
        current_node->next = new_node;

    }

}

void SingleLinkedList::RemoveAfterNode(ListNode* current_node) {


    // If head exists and we pass in a null new node, remove the head node. 
    if (current_node == nullptr && this->head != nullptr) {

        ListNode* temp = this->head->next; // Store the node after the head into temp
        this->head = temp; // Make the second node the head.

        if (temp == nullptr) { // If there were no next node, last item removed
            this->tail = nullptr;
        }

    }
    else if (current_node->next) {

        ListNode* temp = current_node->next->next;
        current_node->next = temp;

        if (temp == nullptr) {
            this->tail = current_node;
        }

    }
    
}

int main() {

    SingleLinkedList* List = new SingleLinkedList;
    printf("Head is initially null %p\n", List->head);
    printf("Tail is initially null %p\n", List->tail);

    ListNode* a = new ListNode;
    ListNode* b = new ListNode;
    ListNode* c = new ListNode;
    ListNode* d = new ListNode;
    ListNode* e = new ListNode;

    List->InsertNode(a, 1);
    List->InsertNode(b, 2);
    List->InsertNode(c, 3);
    List->InsertNode(d, 4);
    List->InsertNode(e, 5);

    List->RemoveAfterNode(nullptr);
    

    ListNode* curr = List->head;
    while (curr) {
        printf("Val %i\n", curr->val);
        curr = curr->next;
    }
    
    
    system("pause");
	return 0;
}