// 10. WAP TO REVERSAL OF A LINKED LIST

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

// Function to reverse the linked list
void reverseLinkedList(struct Node** head) {
    struct Node* prev = NULL;   // Previous node
    struct Node* current = *head;  // Current node
    struct Node* next = NULL;   // Next node

    while (current != NULL) {
        // Store the next node
        next = current->next;

        // Reverse the current node's pointer
        current->next = prev;

        // Move pointers one position ahead
        prev = current;
        current = next;
    }

    // Update the head to point to the new first node (which was the last node)
    *head = prev;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;

    printf("Linked List: ");

    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }

    printf("NULL\n");
}

int main() {
    // Initialize an empty linked list
    struct Node* head = NULL;

    // Insert some elements at the beginning
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);

    // Print the original linked list
    printf("Original ");
    printList(head);

    // Reverse the linked list
    reverseLinkedList(&head);

    // Print the reversed linked list
    printf("Reversed ");
    printList(head);

    return 0;
}
