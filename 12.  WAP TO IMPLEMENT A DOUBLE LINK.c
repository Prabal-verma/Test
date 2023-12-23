//12.  WAP TO IMPLEMENT A DOUBLE LINKED LIST

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a Node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = newData;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the doubly linked list
void insertAtBeginning(struct Node** head, int newData) {
    struct Node* newNode = createNode(newData);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

// Function to insert a node at the end of the doubly linked list
void insertAtEnd(struct Node** head, int newData) {
    struct Node* newNode = createNode(newData);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

// Function to print the doubly linked list forward
void printForward(struct Node* head) {
    struct Node* current = head;
    printf("Doubly Linked List (Forward): ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to print the doubly linked list backward
void printBackward(struct Node* head) {
    struct Node* current = head;
    if (current == NULL) {
        return;
    }
    while (current->next != NULL) {
        current = current->next;
    }
    printf("Doubly Linked List (Backward): NULL");
    while (current != NULL) {
        printf(" <- %d", current->data);
        current = current->prev;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL; // Initialize an empty doubly linked list

    // Insert elements at the beginning
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);

    // Print the doubly linked list forward and backward
    printForward(head);
    printBackward(head);

    // Insert elements at the end
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);

    // Print the doubly linked list forward and backward after insertion at the end
    printForward(head);
    printBackward(head);

    // Free memory
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
