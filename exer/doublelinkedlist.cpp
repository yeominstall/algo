#include <iostream>

class Node {
public:
    Node* prev;
    Node* next;
    int data;
};

class doublelinkedlist {
private:
    
public:
    Node** p;
    Node initNode;
    int size;

    doublelinkedlist() {
        size = 0;
        initNode.next = NULL;
        initNode.data = -1;
        *p = &initNode;
    }

    // ~doublelinkedlist();

    Node** append(int newData) {
        Node newNode;
        newNode.data = newData;
        newNode.next = (**p).next;
        if (newNode.next != NULL) newNode.next->prev = &newNode;
        (**p).next = &newNode;
        newNode.prev = (*p);
        size++;
        
        return &((*p)->next);
    }

    Node** remove(Node* removeNode) {
        (removeNode->prev)->next = removeNode->next;
        (removeNode->next)->prev = removeNode->prev;
        // delete &removeNode;

        return &(removeNode->prev);
    }

};

int main (void) {
    doublelinkedlist dl;
    Node** pc;

    std::cout << "This is demo for double linked list." << std::endl;
    dl.append(3);
    // dl.append(17);
    // dl.append(2);

    std::cout << "list size: " << dl.size << std::endl;
    *pc = &(dl.initNode);
    for (int i = 0; i < dl.size; i++) {
        **pc = *((*pc)->next);
        std::cout << (*pc)->data << "\n";
    }
    return 0;
}

// seems totally wrong...