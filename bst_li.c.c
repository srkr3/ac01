#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct ListNode {
    int data;
    struct ListNode* next;
};

struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to print the linked list.
void printList(struct ListNode* head) {
    while (head->next != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("%d ", head->data);
}


void bstToLinkedList(struct TreeNode* root) {
    if (root == NULL) {
        return ;
    }

    struct ListNode* listHead = NULL;
    struct ListNode* listTail = NULL;

    void convertList(struct TreeNode* node) {
        if (node == NULL) {
            return;
        }

        convertList(node->left);

        struct ListNode* newlist = (struct ListNode*)malloc(sizeof(struct ListNode));
        newlist->data = node->data;
        newlist->next = NULL;

        if (listHead == NULL) {
            listHead = listTail = newlist;
        } else {
            listTail->next = newlist;
          	listTail = newlist;
        }

        convertList(node->right);
    }
    convertList(root);
    printList(listHead) ;
}


int main() {
    // Sample BST:
    //        4
    //       / \
    //      2   6
    //     / \ / \
    //    1  3 5  7

    struct TreeNode* root = createNode(4);
    root->left = createNode(2);
    root->right = createNode(6);
    root->left->left = createNode(1);
    root->left->right = createNode(3);
    root->right->left = createNode(5);
    root->right->right = createNode(7);

    bstToLinkedList(root);
    
}

