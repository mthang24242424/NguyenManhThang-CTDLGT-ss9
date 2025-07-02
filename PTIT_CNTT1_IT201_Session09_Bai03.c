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

int main() {
    int values[] = {10,20,30,40,50};
    int n = sizeof(values) / sizeof(values[0]);

    Node*head = createNode(values[0]);
    Node* current = head;
    for (int i=1 ; i<n; i++) {
        current->next = createNode(values[i]);
        current = current->next;
    }
    int number;
    printf("Nhap so nguyen duong bat ki: ");
    scanf("%d",&number);
    if (number<=0) {
        printf("false");
        return 0;
    }
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == number) {
            printf("True");
            return 1;
        }
        temp = temp->next;
    }
    printf("false");
    return 0;
}
