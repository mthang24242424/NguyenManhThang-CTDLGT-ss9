#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node *next;
}Node;

Node* createNode(int value) {
    struct Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
int main() {
    int values[] = {10,20,30,40,50};
    int n = sizeof(values) / sizeof(values[0]);

    Node*head = createNode(values[0]);
    Node* current = head;
    for (int i=1 ; i<n; i++) {
        current->next = createNode(values[i]);
        current = current->next;
    }
    printList(head);
    return 0;
}
