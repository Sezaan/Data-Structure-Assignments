#include <bits/stdc++.h>

using namespace std;

struct node {
    int data;
    node* next;

    node() {
        data = 0;
        next = NULL;
    }

    node(int x) {
        data = x;
        next = NULL;
    }
};

class circularLinkedList {
    public:
    node* tail;
    int size;

    circularLinkedList() {
        tail = NULL;
        size = 0;
    }

    void pushBack(int x) {
        if(tail == NULL) {
            node* cur = new node(x);
            tail = cur;
            tail -> next = tail;
        }
        else {
            node* cur = new node(x);
            cur -> next = tail -> next;
            tail -> next = cur;
            tail = cur;
        }
        size++;
    }

    void pushFront(int x) {
        if(tail == NULL) {
            node* cur = new node(x);
            tail = cur;
            tail -> next = tail;
        }
        else {
            node* cur = new node();
            cur -> data = x;
            cur -> next = tail -> next;
            tail -> next = cur;
        }
        size++;
    }

    void deleteAt(int idx) {
        if(tail == NULL) {
            cout << "The list is empty." << "\n";
            return;
        }
        if(idx > size) {
            cout << "The index is greater than the total elements of the list." << '\n';
            return;
        }
        if(size == 1) {
            tail = NULL;
        }
        else if(idx == 1) {
            node* cur = tail -> next;
            tail -> next = tail -> next -> next;
            free(cur);
        }
        else if(idx == size) {
            node* cur = tail -> next;
            while(cur -> next != tail) {
                cur = cur -> next; 
            }
            cur -> next = tail -> next;
            tail = cur;
        }
        else {
            idx--;
            node* cur = tail -> next;
            do {
                idx--;
                if(idx == 0) {
                    node* p = cur -> next;
                    cur -> next = p -> next;
                    free(p);
                    break;
                }
                cur = cur -> next;
            } while(cur != tail -> next);
        }
        size--;
    }

    void traverse() {
        if(tail == NULL) {
            cout << "The list is empty." << '\n';
            return;
        }
        node* cur = tail -> next;
        do {
            cout << cur -> data << " ";
            cur = cur -> next;
        } while(cur != tail -> next);
        puts("");
    }
};

int main() {
    circularLinkedList List = circularLinkedList();

    while(true) {
        cout << "1. Push back an element to the list." << "\n";
        cout << "2. Push front an element to the list" << "\n";
        cout << "3. Traverse the list." << "\n";
        cout << "4. Delete an item from any position on list." << "\n";
        cout << "5. Exit the prompt" << "\n";

        cout << "Please enter a choice from above. ^_^" << "\n";

        int op; cin >> op;
        if(op == 1) {
            cout << "Enter the element you want to push back: ";
            int x; cin >> x;
            List.pushBack(x);
        }
        else if(op == 2) {
            cout << "Enter the element you want to push front: ";
            int x; cin >> x;
            List.pushFront(x);
        }
        else if(op == 3) {
            List.traverse();
        }
        else if(op == 4) {
            cout << "Enter the position of the element which you want to delete: ";
            int idx; cin >> idx;
            List.deleteAt(idx);
        }
        else {
            break;
        }
    }
}
