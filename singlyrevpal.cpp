#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct palstr {
    char data;
    struct palstr *next;
};

struct palstr *first, *temp, *dtemp, *newfirst, *newtemp;
int i;

// initialize all pointers
void init() {
    first = temp = dtemp = newfirst = newtemp = NULL;
}

// function to add node
void addnode(char name) {
    temp = (struct palstr*)malloc(sizeof(struct palstr));
    temp->data = name;
    temp->next = NULL;

    if (first == NULL)
        first = temp;
    else
        dtemp->next = temp;

    dtemp = temp;
}

// function to display linked list
void display(struct palstr *node) {
    while (node != NULL) {
        printf("%c -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// function to reverse the linked list
void reverseLL() {
    struct palstr *curr, *prev, *nextnode;
    prev = NULL;
    curr = first;

    while (curr != NULL) {
        nextnode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextnode;
    }
    newfirst = prev;   // newfirst points to reversed list
}

// function to check palindrome
void checkPalindrome() {
    struct palstr *p1 = first;
    struct palstr *p2 = newfirst;

    while (p1 != NULL && p2 != NULL) {
        if (p1->data != p2->data) {
            printf("Not Palindrome\n");
            return;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    printf("Palindrome\n");
}

// main function
int main() {
    char word[] = "MALAYALAM";

    init();

    // add each character into linked list
    for (i = 0; word[i] != '\0'; i++)
        addnode(word[i]);

    printf("Original Linked List:\n");
    display(first);

    reverseLL();

    printf("Reversed Linked List:\n");
    display(newfirst);

    checkPalindrome();

    return 0;
}