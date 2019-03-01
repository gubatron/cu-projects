#include<iostream>

struct Node {
    int key;
    Node *next;

    Node(int k, Node *n) {
        key = k;
        next = n;
    }

    Node(int k) {
        key = k;
        next = 0;
    }

    Node() {
        key = -1;
        next = 0;
    }
};

class List {
private:
    Node *head;
    Node *tail;


public:
    List() {
        head = 0;
        tail = 0;
    }

    ~List() { for (Node *tmp = head; tmp != 0; tmp = tmp->next) delete tmp; }

    void append(int val) {
        Node *curr = new Node(val, 0);
        if (head == 0) {
            head = tail = curr;
        } else {
            tail->next = curr;
            tail = curr;
        }
        //    appendRecursive(head, val);
    }


    int size() {
        return sizeRecursive(head);
    }

    bool search(int k) {
        return searchRecursive(head, k);
    }

    void Reverse() {
        std::cout << "List is reverse: ";
        ReverseRecursive(head);
        std::cout << std::endl;
    }

    void Print() {
        std::cout << "List: ";
        PrintRecursive(head);
        std::cout << std::endl;
    }

private:

    void ReverseRecursive(Node *list) {
        if (list == 0) return;
        else {
            ReverseRecursive(list->next);
            std::cout << list->key << " ";
        }
    }

    void PrintRecursive(Node *list) {
        if (list == 0) return;
        else {
            std::cout << list->key << " ";
            PrintRecursive(list->next);
        }
    }

    int sizeRecursive(Node *l) {
        if (l == 0) return 0; // if empty, size is zero
        else return (1 + sizeRecursive(l->next)); // else size is 1 plus size of the next list
    }

    bool searchRecursive(Node *l, int k) { /*argument is a list l; takes a list and checks if the value k is there*/
        if (l == 0) return false; // if empty, value is NOT in the list
        else if (l->key == k) return true; // value could be in the first node
        else return searchRecursive(l->next, k); // or in the list pointed to by the next pointer so you search the whole thing
    }

    void appendRecursive(Node *l, int val) {
        Node *tmp = new Node(val);
        if (l == 0) {
            l = tmp;
            head = tail = l;
        } else {
            tail->next = tmp;
            tail = tmp;
        }
    }

};

int main() {
    List L;

    L.append(11);
    L.append(22);
    L.append(33);
    L.append(44);
    L.append(55);
    L.append(66);

    // if (L.search(33)) std::cout << "33 is in the list" <<std::endl;
    // else std::cout << "33 is not in the list" << std::endl;

    // if (L.search(23)) std::cout << "23 is in the list" <<std::endl;
    // else std::cout << "23 is not in the list" << std::endl;

    // std::cout << "size of the list is " << L.size();
    L.Print();
    L.Reverse();
}
