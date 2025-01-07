#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insertAtBeginning(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL) {
        newNode->next = newNode; // Circular link
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        newNode->next = head;
        head = newNode;
        temp->next = head; // Maintain circular link
    }

    printf("\nNode inserted at the beginning.\n");
}

void insertAtEnd(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL) {
        newNode->next = newNode; // Circular link
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head; // Maintain circular link
    }

    printf("\nNode inserted at the end.\n");
}

void insertAfter(int value, int location) {
    if (head == NULL) {
        printf("\nThe list is empty. Cannot insert after a node.\n");
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    struct Node* temp = head;
    do {
        if (temp->data == location) {
            newNode->next = temp->next;
            temp->next = newNode;
            printf("\nNode inserted after %d.\n", location);
            return;
        }
        temp = temp->next;
    } while (temp != head);

    printf("\nNode with value %d not found.\n", location);
}

void deleteBeginning() {
    if (head == NULL) {
        printf("\nThe list is empty. Cannot delete.\n");
        return;
    }

    struct Node* temp = head;

    if (head->next == head) { // Only one node
        head = NULL;
    } else {
        struct Node* last = head;
        while (last->next != head) {
            last = last->next;
        }
        head = head->next;
        last->next = head; // Maintain circular link
    }

    free(temp);
    printf("\nNode deleted from the beginning.\n");
}

void deleteEnd() {
    if (head == NULL) {
        printf("\nThe list is empty. Cannot delete.\n");
        return;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;

    if (head->next == head) { // Only one node
        head = NULL;
    } else {
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = head; // Maintain circular link
    }

    free(temp);
    printf("\nNode deleted from the end.\n");
}

void deleteSpecific(int value) {
    if (head == NULL) {
        printf("\nThe list is empty. Cannot delete.\n");
        return;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;

    do {
        if (temp->data == value) {
            if (temp == head) { // Deleting the head node
                deleteBeginning();
                return;
            } else {
                prev->next = temp->next;
                free(temp);
                printf("\nNode with value %d deleted.\n", value);
                return;
            }
        }
        prev = temp;
        temp = temp->next;
    } while (temp != head);

    printf("\nNode with value %d not found.\n", value);
}

void display() {
    if (head == NULL) {
        printf("\nThe list is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("\nThe elements in the list are: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

int main() {
    int choice, value, position;

    while (1) {
        printf("\n*********** MENU *************\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("\nEnter the value to insert: ");
            scanf("%d", &value);
            printf("\n1. At the beginning\n2. At the end\n3. After a node\nEnter your choice: ");
            scanf("%d", &position);

            if (position == 1) {
                insertAtBeginning(value);
            } else if (position == 2) {
                insertAtEnd(value);
            } else if (position == 3) {
                printf("\nEnter the value of the node after which to insert: ");
                scanf("%d", &position);
                insertAfter(value, position);
            } else {
                printf("\nInvalid choice!\n");
            }
            break;

        case 2:
            printf("\n1. Delete from the beginning\n2. Delete from the end\n3. Delete a specific node\nEnter your choice: ");
            scanf("%d", &position);

            if (position == 1) {
                deleteBeginning();
            } else if (position == 2) {
                deleteEnd();
            } else if (position == 3) {
                printf("\nEnter the value of the node to delete: ");
                scanf("%d", &value);
                deleteSpecific(value);
            } else {
                printf("\nInvalid choice!\n");
            }
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);

        default:
            printf("\nInvalid choice! Try again.\n");
        }
    }

    return 0;
}
