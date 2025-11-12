//number split 1 to 10 in even and odd
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *first, *temp, *ntemp, *ptemp;
Node *efirst = NULL, *etemp = NULL;
Node *ofirst = NULL, *otemp = NULL;

Node* createp(int x) {
    Node *p = new Node;
    p->data = x;
    p->next = NULL;
    return p;
}

void init() {
    first = temp = ntemp = ptemp = NULL;
    efirst = etemp = ofirst = otemp = NULL;
}

void createfirst(int x) {
    first = new Node;
    first->data = x;
    first->next = NULL;
}

void addnode(int x) {
    temp = first;
    while (temp->next != NULL)
        temp = temp->next;
    ntemp = new Node;
    ntemp->data = x;
    ntemp->next = NULL;
    temp->next = ntemp;
}

void disp(Node *head) {
    temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void even_part() {
    temp = first;
    while (temp != NULL) {
        if (temp->data % 2 == 0) {
            ntemp = createp(temp->data);
            if (efirst == NULL) {
                efirst = ntemp;
                etemp = efirst;
            } else {
                etemp->next = ntemp;
                etemp = etemp->next;
            }
        }
        temp = temp->next;
    }
}

void odd_part() {
    temp = first;
    while (temp != NULL) {
        if (temp->data % 2 != 0) {
            ptemp = createp(temp->data);
            if (ofirst == NULL) {
                ofirst = ptemp;
                otemp = ofirst;
            } else {
                otemp->next = ptemp;
                otemp = otemp->next;
            }
        }
        temp = temp->next;
    }
}

int main() {
    init();
    createfirst(1);
    for (int i = 2; i <= 10; i++) {
        addnode(i);
    }

    cout << "Original Linked List: ";
    disp(first);

    even_part();
    cout << "Even Linked List: ";
    disp(efirst);

    odd_part();
    cout << "Odd Linked List: ";
    disp(ofirst);

    return 0;
}