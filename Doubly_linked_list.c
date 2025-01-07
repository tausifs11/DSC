#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node *previous, *next;
} *head = NULL;

// Function to insert at the beginning
void insertAtBeginning(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->previous = NULL;
    newNode->next = head;

    if (head != NULL) {
        head->previous = newNode;
    }

    head = newNode;
    printf("\nNode inserted at the beginning!\n");
}

// Function to insert at the end
void insertAtEnd(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->previous = NULL;
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->previous = temp;
    }
    printf("\nNode inserted at the end!\n");
}

// Function to insert after a specific node
void insertAtAfter(int value, int location) {
    struct Node *temp = head;
    while (temp != NULL && temp->data != location) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("\nThe specified node does not exist!\n");
    } else {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = temp->next;
        newNode->previous = temp;

        if (temp->next != NULL) {
            temp->next->previous = newNode;
        }

        temp->next = newNode;
        printf("\nNode inserted after %d!\n", location);
    }
}

// Function to delete the first node
void deleteBeginning() {
    if (head == NULL) {
        printf("\nThe list is empty! Cannot delete.\n");
        return;
    }

    struct Node *temp = head;
    head = head->next;

    if (head != NULL) {
        head->previous = NULL;
    }

    free(temp);
    printf("\nNode deleted from the beginning!\n");
}

// Function to delete the last node
void deleteEnd() {
    if (head == NULL) {
        printf("\nThe list is empty! Cannot delete.\n");
        return;
    }

    struct Node *temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    if (temp->previous != NULL) {
        temp->previous->next = NULL;
    } else {
        head = NULL;
    }

    free(temp);
    printf("\nNode deleted from the end!\n");
}

// Function to delete a specific node
void deleteSpecific(int value) {
    if (head == NULL) {
        printf("\nThe list is empty! Cannot delete.\n");
        return;
    }

    struct Node *temp = head;

    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("\nThe specified node does not exist!\n");
        return;
    }

    if (temp->previous != NULL) {
        temp->previous->next = temp->next;
    } else {
        head = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->previous = temp->previous;
    }

    free(temp);
    printf("\nNode with value %d deleted!\n", value);
}

// Function to display the list
void display() {
    if (head == NULL) {
        printf("\nThe list is empty!\n");
        return;
    }

    struct Node *temp = head;
    printf("\nThe elements of the list are:\n");
    printf("NULL <-> ");

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Main function
int main() {
    int choice1, choice2, value, position;

    while (1) {
        printf("\n*********** MENU *************");
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice1);

        switch (choice1) {
            case 1:
                printf("\nEnter the value to insert: ");
                scanf("%d", &value);
                printf("\nSelect from the following insert options:");
                printf("\n1. At the beginning");
                printf("\n2. At the end");
                printf("\n3. After a node");
                printf("\n4. Cancel");
                printf("\nEnter your choice: ");
                scanf("%d", &choice2);

                switch (choice2) {
                    case 1:
                        insertAtBeginning(value);
                        break;
                    case 2:
                        insertAtEnd(value);
                        break;
                    case 3:
                        printf("\nEnter the position after which you want to insert: ");
                        scanf("%d", &position);
                        insertAtAfter(value, position);
                        break;
                    case 4:
                        break;
                    default:
                        printf("\nInvalid choice! Try again.\n");
                }
                break;

            case 2:
                printf("\nSelect from the following delete options:");
                printf("\n1. At the beginning");
                printf("\n2. At the end");
                printf("\n3. Specific node");
                printf("\n4. Cancel");
                printf("\nEnter your choice: ");
                scanf("%d", &choice2);

                switch (choice2) {
                    case 1:
                        deleteBeginning();
                        break;
                    case 2:
                        deleteEnd();
                        break;
                    case 3:
                        printf("\nEnter the value of the node to be deleted: ");
                        scanf("%d", &value);
                        deleteSpecific(value);
                        break;
                    case 4:
                        break;
                    default:
                        printf("\nInvalid choice! Try again.\n");
                }
                break;

            case 3:
                display();
                break;

            case 4:
                printf("\nExiting program.\n");
                exit(0);

            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }

    return 0;
}
