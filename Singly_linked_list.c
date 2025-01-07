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
    newNode->next = head;
    head = newNode;
    printf("\nNode inserted at the beginning.\n");
}

void insertAtEnd(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("\nNode inserted at the end.\n");
}

void insertBetween(int value, int loc1, int loc2) {
    if (head == NULL) {
        printf("\nList is empty. Inserting at the beginning.\n");
        insertAtBeginning(value);
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    struct Node* temp = head;
    while (temp != NULL && (temp->data != loc1 && temp->data != loc2)) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("\nLocation not found.\n");
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
        printf("\nNode inserted between %d and %d.\n", loc1, loc2);
    }
}

void removeBeginning() {
    if (head == NULL) {
        printf("\nThe list is empty.\n");
    } else {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        printf("\nNode removed from the beginning.\n");
    }
}

void removeEnd() {
    if (head == NULL) {
        printf("\nThe list is empty.\n");
    } else if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("\nNode removed from the end.\n");
    } else {
        struct Node* temp = head;
        struct Node* prev = NULL;
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        free(temp);
        printf("\nNode removed from the end.\n");
    }
}

void removeSpecific(int value) {
    if (head == NULL) {
        printf("\nThe list is empty.\n");
        return;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("\nValue not found in the list.\n");
    } else {
        if (prev == NULL) { // Node to be deleted is the head
            head = temp->next;
        } else {
            prev->next = temp->next;
        }
        free(temp);
        printf("\nNode with value %d removed.\n", value);
    }
}

void display() {
    if (head == NULL) {
        printf("\nThe list is empty.\n");
    } else {
        struct Node* temp = head;
        printf("\nList elements are: ");
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int choice, value, loc1, loc2;

    while (1) {
        printf("\n\n****** MENU ******");
        printf("\n1. Insert");
        printf("\n2. Display");
        printf("\n3. Delete");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("\nEnter the value to insert: ");
            scanf("%d", &value);
            printf("\nWhere do you want to insert?");
            printf("\n1. At the beginning");
            printf("\n2. At the end");
            printf("\n3. Between two nodes");
            printf("\nEnter your choice: ");
            scanf("%d", &loc1);

            switch (loc1) {
            case 1:
                insertAtBeginning(value);
                break;
            case 2:
                insertAtEnd(value);
                break;
            case 3:
                printf("\nEnter the two values where you want to insert: ");
                scanf("%d %d", &loc1, &loc2);
                insertBetween(value, loc1, loc2);
                break;
            default:
                printf("\nInvalid choice!\n");
            }
            break;

        case 2:
            display();
            break;

        case 3:
            printf("\nHow do you want to delete?");
            printf("\n1. From the beginning");
            printf("\n2. From the end");
            printf("\n3. Specific value");
            printf("\nEnter your choice: ");
            scanf("%d", &loc1);

            switch (loc1) {
            case 1:
                removeBeginning();
                break;
            case 2:
                removeEnd();
                break;
            case 3:
                printf("\nEnter the value to delete: ");
                scanf("%d", &value);
                removeSpecific(value);
                break;
            default:
                printf("\nInvalid choice!\n");
            }
            break;

        case 4:
            exit(0);

        default:
            printf("\nInvalid choice! Try again.\n");
        }
    }

    return 0;
}
