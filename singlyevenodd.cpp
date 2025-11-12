#include <stdio.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    // Create 10 nodes statically
    struct Node nodes[10];
    struct Node *first = NULL, *even = NULL, *odd = NULL;
    struct Node *temp, *etemp = NULL, *otemp = NULL;

    // Initialize data and links for 1→2→3→...→10
    for (int i = 0; i < 10; i++) {
        nodes[i].data = i + 1;
        nodes[i].next = (i < 9) ? &nodes[i + 1] : NULL;
    }
    first = &nodes[0];  // first node

    temp = first;

    // Split list into even and odd
    while (temp != NULL) {
        if (temp->data % 2 == 0) {  // even
            if (even == NULL)
                even = etemp = temp;
            else {
                etemp->next = temp;
                etemp = temp;
            }
        } else {  // odd
            if (odd == NULL)
                odd = otemp = temp;
            else {
                otemp->next = temp;
                otemp = temp;
            }
        }
        temp = temp->next;
    }

    // Terminate both lists properly
    if (etemp) etemp->next = NULL;
    if (otemp) otemp->next = NULL;

    // Display even list
    printf("Even List: ");
    temp = even;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    // Display odd list
    printf("\nOdd List: ");
    temp = odd;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}