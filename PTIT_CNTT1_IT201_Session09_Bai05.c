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
Node* addFirst(Node* head, int value) {
    Node* newNode = createNode(value);
    newNode->next = head;
    return newNode;
}
void printfList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ",current->data);
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
    int newValue;
    printf("Nhap so nguyen duong de them: ");
    scanf("%d",&newValue);
    if (newValue <= 0) {
        printf("so ko hop le");
        return 1;
    }
    head = addFirst(head, newValue);
    printfList(head);
    return 0;
}
