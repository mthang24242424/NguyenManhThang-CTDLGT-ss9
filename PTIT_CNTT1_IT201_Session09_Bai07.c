#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

Node* insertAtPosition(Node* head, int value, int pos) {
    if (pos < 0) {
        printf("Vi tri khong hop le!\n");
        return head;
    }

    Node* newNode = createNode(value);

    if (pos == 0) {
        newNode->next = head;
        return newNode;
    }

    Node* current = head;
    for (int i = 0; i < pos - 1; i++) {
        if (current == NULL) {
            printf("Vi tri vuot qua do dai danh sach!\n");
            free(newNode);
            return head;
        }
        current = current->next;
    }

    if (current == NULL) {
        printf("Vi tri vuot qua do dai danh sach!\n");
        free(newNode);
        return head;
    }

    newNode->next = current->next;
    current->next = newNode;
    return head;
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
    int values[] = {10, 20, 30, 40, 50};
    int n = sizeof(values) / sizeof(values[0]);

    Node* head = createNode(values[0]);
    Node* current = head;
    for (int i = 1; i < n; i++) {
        current->next = createNode(values[i]);
        current = current->next;
    }

    printf("Danh sach ban dau: ");
    printList(head);

    int value, pos;
    printf("Nhap gia tri muon them: ");
    scanf("%d", &value);
    printf("Nhap vi tri muon them (bat dau tu 0): ");
    scanf("%d", &pos);

    head = insertAtPosition(head, value, pos);

    printf("Danh sach sau khi them: ");
    printList(head);

    return 0;
}
