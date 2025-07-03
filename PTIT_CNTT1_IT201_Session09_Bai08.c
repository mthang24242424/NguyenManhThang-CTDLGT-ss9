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

Node* deleteAtPosition(Node* head, int pos) {
    if (head == NULL) {
        printf("Danh sach rong!\n");
        return head;
    }

    if (pos < 0) {
        printf("Vi tri khong hop le!\n");
        return head;
    }

    if (pos == 0) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    Node* current = head;
    for (int i = 0; i < pos - 1; i++) {
        if (current == NULL || current->next == NULL) {
            printf("Vi tri vuot qua do dai danh sach!\n");
            return head;
        }
        current = current->next;
    }

    Node* temp = current->next;
    if (temp == NULL) {
        printf("Vi tri vuot qua do dai danh sach!\n");
        return head;
    }

    current->next = temp->next;
    free(temp);
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

    int pos;
    printf("Nhap vi tri muon xoa (bat dau tu 0): ");
    scanf("%d", &pos);

    head = deleteAtPosition(head, pos);

    printf("Danh sach sau khi xoa: ");
    printList(head);

    return 0;
}
