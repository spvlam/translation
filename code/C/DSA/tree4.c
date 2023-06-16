#include <stdio.h>
#include <stdlib.h>

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

Node* makeRoot(int u) {
    return createNode(u);
}

void insert(Node* parent, int u) {
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

    char action[10];
    int u, v;

    while (1) {
        scanf("%s", action);

        if (action[0] == '*')
            break;
        if (action[0] == 'M') {  // MakeRoot
            scanf("%d", &u);
            root = makeRoot(u);
        } else if (action[0] == 'I' && action[2]=='s') {  // Insert
            scanf("%d %d", &u, &v);
            insert(root, u);
        } else if (action[0] == 'P' && action[1] == 'r' ) {  // PreOrder
            preOrderTraversal(root);
            printf("\n");
        } else if (action[0] == 'I' && action[1] == 'n') {  // InOrder
            inOrderTraversal(root);
            printf("\n");
        } else if (action[0] == 'P' && action[1] == 'o') {  // PostOrder
            postOrderTraversal(root);
            printf("\n");
        } else {
            printf("Invalid action.\n");
        }
    }

    return 0;
}
