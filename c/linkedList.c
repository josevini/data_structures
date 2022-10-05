#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    struct Node * next;
} Node;

Node * createNode(int data, Node * next) {
    Node * node = (Node *) malloc(sizeof(Node));

    node->data = data;
    if (next) {
        node->next = (struct Node *) next;
    }

    return node;
}

void printNode(Node * node) {
    printf("----------------\n");
    printf("Node->data: %d\n", node->data);
    printf("Node->next: %p\n", node->next);
    printf("&Node: %p\n", node);
}

void printList(Node * node) {
    while (1) {
        printNode(node);
        if (node->next) {
            node = (Node *) node->next;
        } else {
            break;
        }
    }
}

void main() {
    Node * first, * second, * third, * fourth;

    fourth = createNode(4, NULL);
    third = createNode(3, fourth);
    second = createNode(2, third);
    first = createNode(1, second);
    
    printList(first);
}