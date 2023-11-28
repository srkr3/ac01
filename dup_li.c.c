#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void display(struct Node* head) {
    while (head->next != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("%d -> ", head->data);
    printf("NULL\n");
}

void removeDuplicates(struct Node* head) {
    struct Node *current, *t, *temp;

    current = head;
    while (current->next != NULL) {
        t = current;
        while (t->next != NULL) {
            if (t->next->data == current->data) {
                t->next = t->next->next;
            } else {
                t = t->next;
            }
        }
        current = current->next;
    }
}

int main() {
    struct Node* head;
	head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(2);
    head->next->next->next = createNode(2);
    head->next->next->next->next = createNode(4);
    head->next->next->next->next->next = createNode(1);

    printf("Original Linked List:\n");
    display(head);

    removeDuplicates(head);

    printf("\nLinked List after Removing Duplicates:\n");
    display(head);
    
	return 0;
}

