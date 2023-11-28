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

void printModular(struct Node *head, int k) {
    if (k < 0 || head == NULL) {
        return;
    }

    int i = 1;
    struct Node *curr = head, *mod = NULL;

    while (curr != NULL) {
        if (i % k == 0) {
            mod = curr;
        }
        curr = curr->next;
        i++;
    }

    printf("Modular node is: %d\n", mod->data);
}

int main() {
    struct Node *head;
	head = createNode(1);
    head->next = createNode(20);
    head->next->next = createNode(2);
    head->next->next->next = createNode(0);
    head->next->next->next->next = createNode(4);

    printModular(head, 2);

    return 0;
}

