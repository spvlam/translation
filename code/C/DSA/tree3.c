#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct Node {
    int id;
    struct Node* firstChild;
    struct Node* nextSibling;
} Node;

Node* createNode(int id) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->id = id;
    newNode->firstChild = NULL;
    newNode->nextSibling = NULL;
    return newNode;
}

void makeRoot(Node** root, int u) {
    *root = createNode(u);
}

void insertNode(Node* parent, int u) {
    Node* newNode = createNode(u);
    if (parent->firstChild == NULL) {
        parent->firstChild = newNode;
    } else {
        Node* temp = parent->firstChild;
        while (temp->nextSibling != NULL) {
            temp = temp->nextSibling;
        }
        temp->nextSibling = newNode;
    }
}

void preOrderTraversal(Node* root) {
    if (root != NULL) {
        printf("%d ", root->id);
        Node* temp = root->firstChild;
        while (temp != NULL) {
            preOrderTraversal(temp);
            temp = temp->nextSibling;
        }
    }
}

void inOrderTraversal(Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->firstChild);
        printf("%d ", root->id);
        Node* temp = root->firstChild;
        while (temp != NULL) {
            inOrderTraversal(temp->nextSibling);
            temp = temp->nextSibling;
        }
    }
}

void postOrderTraversal(Node* root) {
    if (root != NULL) {
        Node* temp = root->firstChild;
        while (temp != NULL) {
            postOrderTraversal(temp);
            temp = temp->nextSibling;
        }
        printf("%d ", root->id);
    }
}

int main() {
    Node* root = NULL;
    char action[20];
    int u, v;

    while (scanf("%s", action) == 1) {
        if (action[0] == '*') {
            break;
        }

        if (strcmp(action, "MakeRoot") == 0) {
            scanf("%d", &u);
            makeRoot(&root, u);
        } else if (strcmp(action, "Insert") == 0) {
            scanf("%d %d", &u, &v);
            Node* parent = root;
            while (parent->id != v) {
                parent = parent->nextSibling;
            }
            insertNode(parent, u);
        } else if (strcmp(action, "PreOrder") == 0) {
            preOrderTraversal(root);
            printf("\n");
        } else if (strcmp(action, "InOrder") == 0) {
            inOrderTraversal(root);
            printf("\n");
        } else if (strcmp(action, "PostOrder") == 0) {
            postOrderTraversal(root);
            printf("\n");
        }
    }

    return 0;
}
