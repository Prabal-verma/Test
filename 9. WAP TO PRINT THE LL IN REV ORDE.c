// 9. WAP TO PRINT THE LL IN REV ORDER WITHOUT CHANGING LL //

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a Node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new element at the beginning of the list
void insertAtBeginning(struct Node** head, int newData) {
    // Allocate memory for the new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    // Check if memory allocation was successful
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    // Set the data for the new node
    newNode->data = newData;

    // Set the next of the new node to the current head
    newNode->next = *head;

    // Update the head to point to the new node
    *head = newNode;
}

// Function to print the linked list in reverse order
void printReverse(struct Node* head) {
    if (head == NULL) {
        return;
    }

    // Recursively call the function for the next node
    printReverse(head->next);

    // Print the data of the current node
    printf("%d -> ", head->data);
}

int main() {
    // Initialize an empty linked list
    struct Node* head = NULL;

    // Insert some elements at the beginning
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);

    // Print the linked list in reverse order
    printf("Linked List (in reverse order): ");
    printReverse(head);
    printf("NULL\n");

    return 0;
}
