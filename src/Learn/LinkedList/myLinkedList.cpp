class MyLinkedList {
private:
    struct Node
    {
        int val;
        Node * next;
        Node() : val(0), next(nullptr) {}
        Node(int v) : val(v), next(nullptr) {}
        Node(int v, Node * n) : val(v), next(n) {}
    };

    Node * head;
    Node * tail;
    int size = 0;

public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        this -> head = nullptr;
        this -> tail = nullptr;
        this -> size = 0;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index >= (this -> size)) return -1;
        Node * candidate = this -> head;
        while(index) {
            index--;
            candidate = candidate -> next;
        }
        return candidate -> val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node * newHead = new Node(val);
        if(this -> head == nullptr) {
            this -> head = newHead;
            this -> tail = newHead;
        }
        else {
            newHead -> next = this -> head;
            this -> head = newHead;
        }
        this -> size++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node * newTail = new Node(val);
        if(this -> tail == nullptr) {
            this -> tail = newTail;
            this -> head = newTail;
        }
        else {
            this -> tail -> next = newTail;
            this -> tail = newTail;
        }
        this -> size++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index > (this -> size)) return;
        if(index == (this -> size)) {
            addAtTail(val);
            return;
        }
        if(index == 0) {
            addAtHead(val);
            return;
        }

        Node * tempNode = this -> head; 
        while(index > 1) {
            tempNode = tempNode -> next;
            index--;
        }

        Node * newNode = new Node(val, tempNode -> next);
        tempNode -> next = newNode;

        this -> size++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index >= (this -> size)) return;
        if(index == 0) this -> head = this -> head -> next;
        else {
            Node * candidate = this -> head;
            int currIndex = 0;
            while(currIndex < index - 1) {
                candidate = candidate -> next;
                currIndex++;
            }
            candidate -> next = candidate -> next -> next;
            if(index == this -> size - 1) this -> tail = candidate;
        }
        this -> size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */